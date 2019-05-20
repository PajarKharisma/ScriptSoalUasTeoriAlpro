#include <iostream>
#include <conio.h>
using namespace std;

#define NUM_OF_INDEX 20

//STRUCK SETIAP NODE PADA TREE
struct Node { 
	int data;
	Node *left, *right;
};

class BST{
    public:
        Node *addNode(int data){
            Node *newNode = new Node;
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        Node *insertData(Node *anode, int data){
            if(anode == NULL){
                return addNode(data);
            }

            if(data < anode->data){
                anode->left = insertData(anode->left, data);
            }else if(data > anode->data){
                anode->right = insertData(anode->right, data);
            }
            return anode;
        }

        void inOrder(Node *anode){
            if(anode != NULL){
                inOrder(anode->left);
                cout << anode->data << " ";
                inOrder(anode->right);
            }
        }
        
        void preOrder(Node *anode){
            if(anode != NULL){
                cout << anode->data << " ";
                inOrder(anode->left);
                inOrder(anode->right);
            }
        }
};

class HashMap{
    private:
        BST bst;

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
            database[index] = bst.insertData(database[index], data);
        }

        void printData(Node *database[]){
            for(int i=0; i<NUM_OF_INDEX; i++){
                cout << "[" << i << "] :\t";
                bst.preOrder(database[i]);
                cout << endl;
            }
        }
};

int main(){
    HashMap hashMap;
    Node *database[NUM_OF_INDEX] = {NULL};

    for(int i=0; i<20; i++){
        int data = (rand() % 100) + 1;
        hashMap.hashing(data, database);
    }
    hashMap.printData(database);
    getch();
}