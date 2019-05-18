#include <iostream>
#include <conio.h>
using namespace std;

class HeapTree{
    private:
        int tail;
        int parent;
        int child;
        int *tree;

    public:
        void init(int maxIndex){
            tail = 0;
            tree = new int[maxIndex];
        }

        void getChildIndex(int parent, int *arr){
            int left = (parent * 2) + 1;
            int right = (parent * 2) + 2;

            cout << "Left child index : " + left << endl;
            cout << "Left child data : " + arr[left] << endl;
            cout << "Right child index : " + right << endl;
            cout << "Right child data : " + arr[right] << endl;
        }

        void insert(int data){
            if (tail == 0){
                tree[tail] = data;
                tail++;
            } else {
                child = tail;
                parent = (child - 1) / 2;
                tree[child] = data;
                while (tree[child] < tree[parent]){
                    int tmp = tree[parent];
                    tree[parent] = tree[child];
                    tree[child] = tmp;

                    child = parent;
                    parent = (child - 1) / 2;
                }
                tail++;
            }
        }

        int remove(){
            parent = 0;
            int key = tree[parent];
            int left = (parent * 2) + 1;
            int right = (parent * 2) + 2;
            child = (tree[right] < tree[left]) ? right : left;

            tree[parent] = tree[tail-1];
            while(child < tail && tree[parent] > tree[child]){
                int tmp = tree[parent];
                tree[parent] = tree[child];
                tree[child] = tmp;

                parent = child;
                int left = (parent * 2) + 1;
                int right = (parent * 2) + 2;
                child = (tree[right] < tree[left]) ? right : left;
            }
            tail--;

            return key;
        }

        int getTail(){
            return this->tail;
        }

        int* getTree(){
            return this->tree;
        }
};

int main(){
    int data[] = {23, 56, 18, 13, 45, 82, 18, 26, 48, 38, 34, 59, 20};
    int maxIndex = sizeof(data)/sizeof(data[0]);

    HeapTree heapTree;
    heapTree.init(maxIndex);

    for(int i=0; i<maxIndex; i++){
        heapTree.insert(data[i]);
    }

    cout << "Minimum heap tree is : ";
    for(int i=0; i<maxIndex; i++){
        cout << heapTree.getTree()[i] << " ";
    }

    cout << "\n\nMinimum Key : " << heapTree.remove() << endl;
    cout << "Minimum heap tree after remove is : ";
    for(int i=0; i<heapTree.getTail(); i++){
        cout << heapTree.getTree()[i] << " ";
    }

    cout << "\n\nMinimum Key : " << heapTree.remove() << endl;
    cout << "Minimum heap tree after remove is : ";
    for(int i=0; i<heapTree.getTail(); i++){
        cout << heapTree.getTree()[i] << " ";
    }

    getch();
    return 0;
}