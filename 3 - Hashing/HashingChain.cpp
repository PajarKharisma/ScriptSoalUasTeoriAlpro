#include <iostream>
#include <conio.h>
using namespace std;

#define NUM_OF_INDEX 20

struct Node{
    int data;
    Node *next;
};

class Chain{
    public:
        Node *insertData(Node *anode, int data){
            Node *newNode = new Node;
            newNode->data = data;
            newNode->next = NULL;
            if(anode == NULL){
                return newNode;
            }else{
                Node *t = anode;
                while(t->next != NULL){
                    t = t->next;
                }
                t->next = newNode;
                newNode->next = NULL;
                return anode;
            }
        }

        void print(Node *anode){
            Node *p = anode;
            while(p != NULL){
                cout << p->data << " ";
                p = p->next;
            }
        }
};

class HashMap{
    private:
        Chain chain;

        int getBigestPrime(int val){
            bool isPrime = false;
            int bigestPrime = -1;
            while(!isPrime && val >= 0){
                int cek = 0;
                for(int i=1; i<=val; i++){
                    if(val % i == 0){
                        cek++;
                    }
                }
                if(cek <= 2){
                    isPrime = true;
                    bigestPrime = val;
                }
                val--;
            }
            return bigestPrime;
        }

    public:
        void hashing(int data, Node *database[]){
            int p = getBigestPrime(NUM_OF_INDEX);
            int index = data % p;
            database[index] = chain.insertData(database[index], data);
        }

        void printData(Node *database[]){
            for(int i=0; i<NUM_OF_INDEX; i++){
                cout << "[" << i << "] :\t";
                chain.print(database[i]);
                cout << endl;
            }
        }
};

int main(){
    HashMap hashMap;
    Node *databases[NUM_OF_INDEX] = {NULL};
    for(int i=0; i<50; i++){
        int val = (rand() % 200) + 1;
        hashMap.hashing(val, databases);
    }

    hashMap.printData(databases);
}