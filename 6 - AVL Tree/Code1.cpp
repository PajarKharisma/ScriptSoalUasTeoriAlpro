#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
};

class AvlTree{
    private:
        Node *tree;

        //FUNGSI MENAMBAHKAN ANAK BARU PADA AVL
        Node *addChild(int data){
            Node *newNode = new Node;
            newNode->data = data;
            newNode->left = newNode->right = NULL;
            return newNode;
        }

        //FUNGSI UNTUK MEDAPATKAN TINGGI NODE
        int height(Node *anode){
            if(anode == NULL){
                return -1;
            }
            else if(anode->left == NULL && anode->right == NULL){
                return 0;
            }
            else if(anode->left != NULL && anode->right != NULL){
                return 1 + max(height(anode->left), height(anode->right));
            }
            else if(anode->left != NULL && anode->right == NULL){
                return 1 + height(anode->left);
            }
            else if(anode->right != NULL && anode->left == NULL){
                return 1 + height(anode->right);
            }
        }

        //FUNGSI UNTUK MENDAPATKAN BALANCE FACTOR PADA NODE
        int balanceFactor(Node *anode){
            int lHeight = height(anode->left);
            int rHeight = height(anode->right);

            return lHeight - rHeight;
        }

        //FUNGSI ROTASI KIRI
        Node *singleLeftRotation(Node *anode){
            Node *tmp = anode->right;
            anode->right = tmp->left;
            tmp->left = anode;
            return tmp;
        }

        //FUNGSI ROTASI KANAN
        Node *singleRightRotation(Node *anode){
            Node *tmp = anode->left;
            anode->left = tmp->right;
            tmp->right = anode;
            return tmp;
        }

        //FUNGSI ROTASI KIRI KANAN
        Node *rightLeftRotation(Node *anode){
            anode->right = singleRightRotation(anode->right);
            return singleLeftRotation(anode);
        }

        //FUNGSI ROTASI KANAN KIRI
        Node *leftRightRotation(Node *anode){
            anode->left = singleLeftRotation(anode->left);
            return singleRightRotation(anode);
        }

    public:
        //FUNGSI INSERT DATA
        Node *insertNode(Node *anode, int data){
            //JIKA NODE KOSONG, DATA AKAN LANGUSNG DIINSERT
            if(anode == NULL)
                return addChild(data);

            //PROSES MENELUSURI NODE DENGAN ATURAN BST
            if(data < anode->data)
                anode->left = insertNode(anode->left, data);
            else if(data > anode->data)
                anode->right = insertNode(anode->right, data);
            else
                return anode;

            //PROSES MENDAPATKAN BALANCE FACTOR UNTUK MENENTUKAN POHON HARUS ROTASI ATAU TIDAK
            int bf = balanceFactor(anode);

            //PROSES MENENTUKAN ROTASI BERDASARKAN NILAI DATA DAN BALANCE FACTOR
            if((bf > 1) && (data < anode->left->data)){
                return singleRightRotation(anode);
            } else if ((bf < -1) && (data > anode->right->data)){
                return singleLeftRotation(anode);
            } else if((bf > 1) && (data > anode->left->data)){
                return leftRightRotation(anode);
            } else if((bf < -1) && (data < anode->right->data)){
                return rightLeftRotation(anode);
            }

            return anode;
        }

        void printPreOrder(Node *anode){
            if(anode != NULL){
                cout << anode->data << " ";
                printPreOrder(anode->left);
                printPreOrder(anode->right);
            }
        }
};

int main(){
    AvlTree avlTree;
    Node *root = NULL;
    int data[] = {30, 45, 12, 67, 43, 27, 39, 51, 53, 33, 19, 55, 34};
    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0; i<n; i++){
        root = avlTree.insertNode(root, data[i]);
    }

    avlTree.printPreOrder(root);
    cout << endl;
    return 0;
}