#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *list;

void fpush(node *newNode){
    newNode->next = list;
    list = newNode;
}

int fpop(){
    node *p = list;
    int data = p->data;
    list = p->next;
    delete p;

    return data;
}

int ftop(){
    node *p = list;
    int data = p->data;
    return data;
}

node *insertNode(node *l, node *insertNode){
    if(l == NULL){
        l = insertNode;
        l->next = NULL;
        return l;
    }else{
        node *t = l;
        while (t->next != NULL){
            t = t->next;
        }
        t->next = insertNode;
        insertNode->next = NULL;
        return l;
    }
}

void cetak(node *l){
    node *p = l;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    list = new node;
    int data[] = {20,40,10,15,50,48,22,30,35,19};
    list = NULL;
    int n = sizeof(data) / sizeof(data[0]);

    /* for(int i=0; i<n; i++){
        node *newList = new node;
        newList->data = data[i];
        list = insertNode(list, newList);
    } */

    for(int i=0; i<n; i++){
        node *newNode = new node;
        if(i<5){
            newNode->data = data[i];
            fpush(newNode);
            //cetak(list);
        }else if(i < n){ 
            int value1 = fpop();
            int value2 = fpop();
            newNode->data = value1 + value2;
            fpush(newNode);

            node *dataBaru = new node;
            dataBaru->data = data[i];
            fpush(dataBaru);
            //cetak(list);
        }
    }

   while(list ->next != NULL){
       node *newNode = new node;
       int value1 = fpop();
       int value2 = fpop();
       newNode->data = value1 + value2;
       fpush(newNode);
   }

    cout << ftop() << endl;
    return 0;
}