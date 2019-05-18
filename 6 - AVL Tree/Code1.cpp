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

        Node *addChild(int data){
            Node *newNode = new Node;
            newNode->data = data;
            newNode->left = newNode->right = NULL;
            return newNode;
        }

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

        int balanceFactor(Node *anode){
            int lHeight = height(anode->left);
            int rHeight = height(anode->right);

            return lHeight - rHeight;
        }

        Node *singleLeftRotation(Node *anode){
            Node *tmp = anode->right;
            anode->right = tmp->left;
            tmp->left = anode;
            return tmp;
        }

        Node *singleRightRotation(Node *anode){
            Node *tmp = anode->left;
            anode->left = tmp->right;
            tmp->right = anode;
            return tmp;
        }

        Node *rightLeftRotation(Node *anode){
            anode->right = singleRightRotation(anode->right);
            return singleLeftRotation(anode);
        }

        Node *leftRightRotation(Node *anode){
            anode->left = singleLeftRotation(anode->left);
            return singleRightRotation(anode);
        }

    public:
        Node *insertNode(Node *anode, int data){
            if(anode == NULL)
                return addChild(data);

            if(data < anode->data)
                anode->left = insertNode(anode->left, data);
            else if(data > anode->data)
                anode->right = insertNode(anode->right, data);
            else
                return anode;

            int bf = balanceFactor(anode);

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