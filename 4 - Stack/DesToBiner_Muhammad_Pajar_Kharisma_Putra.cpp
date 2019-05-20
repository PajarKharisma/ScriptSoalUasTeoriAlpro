#include <iostream>
#include <conio.h>
using namespace std;

//STRUKTUR NODE UNTUK SETIAP ELEMENT PADA STACK
struct Node{
    int data;
    Node *next;
};

//STURKTUR STACK
struct Stack{
    Node *list;
    
    //FUNGSI UNTUK MENDEKLARASIKAN LIST = NULL ATAU MENGOSONGKAN / MERESET SEMUA ISI LIST
    void init(){
        list = NULL;
    }

    //FUNGSI UNTUK MENDAPATKAN DATA LIST
    Node *getList(){
        return this->list;
    }

    //FUNGSI MEMASUKAN DATA DALAM STACK
    void push(int data){
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = this->list;
        this->list = newNode;
    }

    //FUNGSI MENGELUARKAN DATA DARI STACK
    int pop(){
        Node *p = this->list;
        int data = p->data;
        this->list = p->next;
        delete p;

        return data;
    }

    //FUNGSI MEMERIKSA STUCK KOSONG ATAU TIDAK
    bool isEmpty(){
        if (this->list == NULL)
            return true;
        else
            return false;
    }
};

int main(){
    Stack stack;
    stack.init();
    int des;
    cout << "Masukan bilangan desimal : ";
    cin >> des;

    while(des > 0){
        int bin = des % 2;
        stack.push(bin);
        des = des / 2;
    }

    cout << "Bilangan biner : ";
    while(!stack.isEmpty()){
        cout << stack.pop();
    }
    getch();
    return 0;
}