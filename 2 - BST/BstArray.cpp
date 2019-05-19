#include <iostream>
using namespace std;

typedef int Tree[500000];
int maxIndex = 0;

void insertData(Tree tree, int data, int index){
    if(tree[index] == 0){
        tree[index] = data;
        maxIndex = max(index, maxIndex);
    }else{
        int newIndex = (data < tree[index]) ? (2*index)+1 : (2*index)+2;
        insertData(tree, data, newIndex);
    }
}

void preOrder(Tree tree, int index){
    if(tree[index] != 0){
        cout << tree[index] << " ";
        preOrder(tree, (2*index)+1);
        preOrder(tree, (2*index)+2);
    }
}

void inOrder(Tree tree, int index){
    if(tree[index] != 0){
        preOrder(tree, (2*index)+1);
        cout << tree[index] << " ";
        preOrder(tree, (2*index)+2);
    }
}

void postOrder(Tree tree, int index){
    if(tree[index] != 0){
        preOrder(tree, (2*index)+1);
        preOrder(tree, (2*index)+2);
        cout << tree[index] << " ";
    }
}

void levelOrder(Tree tree){
    for(int i=0; i<=maxIndex; i++){
        if(tree[i] != 0){
            cout << tree[i] <<  " ";
        }
    }
}

int findMax(Tree tree){
    int index = 0;
    while(tree[(2*index)+2] != 0){
        index = (2*index)+2;
    }
    return tree[index];
}

int findMin(Tree tree){
    int index = 0;
    while (tree[(2*index)+1] != 0){
        index = (2*index)+1;
    }
    return tree[index];
}

int main(){
    Tree tree = {0};
    int arr[] = {25, 73, 41, 30, 58, 64, 98, 13, 87, 91, 17, 76, 28, 45, 56};
	int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++){
        insertData(tree, arr[i], 0);
    }
    cout << "Maximum element is : " << findMax(tree) << endl;
    cout << "Minimum element is : " << findMin(tree) << endl;
    //levelOrder(tree);
}