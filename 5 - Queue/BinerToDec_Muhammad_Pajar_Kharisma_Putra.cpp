#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

//STRUKTUR NODE UNTUK SETIAP ELEMENT PADA QUEUE
struct Node{
    int data;
    Node *next;
};

//STRUKTUR QUEUE
struct Queue{
    private:
        Node *list;
        Node *tail;

    public:
        //FUNGSI UNTUK MENDEKLARASIKAN LIST = NULL ATAU MENGOSONGKAN / MERESET SEMUA ISI LIST
        void init(){
            this->list = NULL;
        }

        //FUNGSI UNTUK MENDAPATKAN DATA LIST
        Node *getList(){
            return this->list;
        }

        //FUNGSI MEMASUKAN DATA DALAM QUEUE
        void enQueue(int data){
            Node *newNode = new Node;
            newNode->data = data;
            newNode->next = NULL;
            if(this->list == NULL){
                this->list = newNode;
                this->tail = newNode;
            }else{
                this->tail->next = newNode;
                this->tail = this->tail->next;
            }
        }

        //FUNGSI MENGELUARKAN DATA DARI QUEUE
        int deQueue(){
            int data = this->list->data;
            Node *delNode = this->list;
            this->list = this->list->next;
            delete delNode;
            return data;
        }

        void printQueue(){
            cout << "ISI QUEUE : ";
            Node *l = this->list;
            while(l != NULL){
                cout << l->data << " ";
                l = l->next;
            }
        }

        //FUNGSI MEMERIKSA QUEUE KOSONG ATAU TIDAK
        bool isEmpty(){
            if(getList() == NULL)
                return true;
            else
                return false;
        }
};

int main(){
    cout << "MUHAMMAD PAJAR KHARISMA PUTRA" << endl << endl;
    Queue queue;
    queue.init();
    
    int bin;
    cout << "Input Biner : ";
    cin >> bin;

    while(bin>0){
        queue.enQueue(bin % 10);
        bin /= 10;
    }

    int dec = 0;
    int n = 0;
    while(!queue.isEmpty()){
        dec += queue.deQueue() * pow(2,n);
        n++;
    }

    cout << "Decimal Value : " << dec;    

    getch();
    return 0;
}