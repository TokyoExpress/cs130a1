#include <iostream>
#include "transaction.h"

int main(){

        int choice = 0;
        int amount;
        std::string sender;
        std::string receiver;
        std::string person;

        Blockchain* b = new Blockchain();

        while (choice != 4) {

                cout << "Welcome to the transaction-chain application..." << endl;
                cout << "1) Add a transaction to the chain." << endl;
                cout << "2) Find Balance of a person." << endl;
                cout << "3) Print the chain." << endl;
                cout << "4) Exit." << endl;
                cout << "Which operation do you want to make? (1, 2, 3, 4):" << endl;

                cin >> choice;

                if(choice == 1) {

                        std::cout << "Integer amount of money:" << endl;
                        std::cin >> amount;
                        std::cout << "Sender name" << endl;
                        std::cin >> sender;
                        std::cout << "Receiver name" << endl;
                        std::cin >> receiver;
                        b -> add(amount, sender, receiver);

                } else if(choice == 2) {

                        cout << "Person Name" << endl;
                        cin >> person;
                        cout << b -> getBalance(person) << endl;

                } else if(choice == 3) {

                        b -> print();

                } else if(choice == 4) {

                        break;

                } else {

                        cout << "wrong operation!" << endl;
                        
                }
        }

        return 0;
}
