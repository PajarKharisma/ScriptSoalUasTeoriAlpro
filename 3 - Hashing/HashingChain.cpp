#include <iostream>
#include <conio.h>
using namespace std;

//JUMLAH INDEX HASH TABLE
#define NUM_OF_INDEX 20

struct Node{
    int data;
    Node *next;
};

//CLASS CHAIN TEMPAT MENYIMPAN DATA MENGGUNAKAN ATURAN LINKED LIST
class Chain{
    public:
        //PROSES INSERT DATA
        Node *insertData(Node *anode, int data){
            Node *newNode = new Node;
            newNode->data = data;
            newNode->next = NULL;
            //JIKA NODE == NULL DATA AKAN DIINSERT DI DEPAN
            if(anode == NULL){
                return newNode;
            }else{
                //JIKA TIDAK, DATA AKAN DIINSERT DI BELAKANG
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

        //FUNGSI MENCARI NILAI PRIMA TERKECIL KURANG DARI N
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
        //FUNGSI MEMASUKAN DATA KE DALAM TABLE HASH, JIKA INDEX SUDAH TERISI MAKA AKAN DI LINK DENGAN ATURAN LINKED LIST
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