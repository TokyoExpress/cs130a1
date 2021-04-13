#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "transaction.h"
#include <openssl/sha.h>

using namespace std;

// hash function
string sha256(const string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
	ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

Blockchain::Blockchain() {
	head = NULL;
}

void Blockchain::add(int amount, std::string sender, std::string receiver) {

	srand (time(NULL));

	Transaction* t = new Transaction;
	t -> amount = amount;
	t -> sender = sender;
	t -> receiver = receiver;

	std::string hash = "";

	// nonce generation
	do {

		t -> nonce = "";

		for (int i = 0; i < 5; i++) {
			t -> nonce += char(rand() % 26 + 97);
		}

		hash = sha256(std::to_string(amount) + (t -> sender) + (t -> receiver) + (t -> nonce));

	} while(hash[hash.length()-1] != '0');

	if (this -> head == NULL) {

		t -> hash = "NULL";
		this -> head = t;
		t -> prev = NULL;

	}

	else {

 		t -> prev = this -> head;
		this -> head = t;
		t -> hash = sha256(std::to_string(t -> prev -> amount) + (t -> prev -> sender) + (t -> prev -> receiver) + (t -> prev -> hash) + (t -> prev -> nonce));

	}
}

int Blockchain::getBalance(string person) {

	int balance = 50;

	for (Transaction* i = this -> head; i != NULL; i = i -> prev) {

		if(person == i -> receiver) {

			balance += i -> amount;

		}

		else if(person == i->sender){

			balance -= i -> amount;

		}
	}

	return balance;

}

void Blockchain::print(){

	this -> print(this -> head);

}

void Blockchain::print(Transaction* head){

	if(head == NULL) {
		return;
	}

	this -> print(head -> prev);

	cout << "Amount: " << head -> amount << endl;
	cout << "Sender: " << head -> sender << endl;
	cout << "Receiver: " << head -> receiver << endl;
	cout << "Nonce: " << head -> nonce << endl;
	cout << "Hash: " << head -> hash << endl;

}