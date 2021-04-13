#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>

using namespace std;

struct Transaction {
        private:
                Transaction * prev;
                int amount;
                std::string sender;
                std::string receiver;
                std::string nonce;
                std::string hash;
};

class Blockchain {
        public:
                Blockchain();
                void add(int amount, std::string sender, std::string receiver);
                int getBalance(std::string person);
                void print();
        private:
                Transaction * head;
};

#endif
