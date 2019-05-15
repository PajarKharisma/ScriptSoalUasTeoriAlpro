#include <iostream>
#include <queue>
using namespace std; 

//STRUKTUR NODE
struct Node { 
	int data; 
	Node *left, *right; 
}; 

queue<Node*> q;

//FUNGSI MENAMBAH NODE BARU
Node *addNode(int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//FUNGSI INSERT DATA SECARA BST
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

Node *insert(Node *anode, int data){
    Node *b, *p, *q;
    b = addNode(data);
    if (anode == NULL){
        anode = b;
    }
    else{
        q = anode;
        while(q!=NULL){
            p = q;    
            if(data < p->data){
                q = p->left;
            }
            else if(data > p->data){
                q = p->right;
            }else{
                q = NULL;
            }
        }
    if (data < p->data)
        p->left = b;
    else if (data>p->data)
        p->right = b;
   }  
   return anode;     
}

Node *findMax(Node *anode){
    if(anode->right != NULL){
        return findMax(anode->right);
    }
    return anode;
}

Node *findMaxSecond(Node *anode){
    Node *maxNode = anode;
    Node *parent;
    while(maxNode->right != NULL){
        parent = maxNode;
        maxNode = maxNode->right;
    }

    Node *maxChild = findMax(maxNode->left);
    anode = (maxChild->data > parent->data) ? maxChild : parent;
    return anode;
}

Node* deleteNode(Node *root, int data) {
	if(root == NULL)
        return root; 
	else if(data < root->data){
        cout << "1" << endl;
        root->left = deleteNode(root->left,data);
    }
	else if (data > root->data){
        cout << "2" << endl;
        root->right = deleteNode(root->right,data);	
    }
	else {
		if(root->left == NULL && root->right == NULL) { 
            cout << "3" << endl;
			delete root;
			root = NULL;
		} 
		else if(root->left == NULL) {
            cout << "4" << endl;
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
            cout << "5" << endl;
			Node *temp = root;
			root = root->left;
			delete temp;
		} else { 
            cout << "6" << endl;
			Node *temp = findMax(root->left);
			root->data = temp->data;
			root->left = deleteNode(root->left, temp->data);
		}
	}
	return root;
}

void deleteRoot(Node *anode){
    Node *temp;
    Node *q;
    if(anode!=NULL){
        if(anode->left != NULL) {
            q = anode->left;
            if(q->right == NULL) {
                anode->data = q->data;
                anode->left = q->left;
                delete q;
            }else {
                while (q->right->right != NULL){
                    q = q->right;
                }
                temp = q->right;
                anode->data = temp->data;
                q->right = temp->left;
                delete temp;
            }
        }else if(anode->right != NULL) {
            q = anode->right;
            if(q->left == NULL) {
                anode->data = q->data;
                anode->right = q->right;
                delete q;
            }else {
                while (q->left->left != NULL) {
                    q = q->left;
                }
                temp = q->left;
                anode->data=temp->data;
                q->left = temp->right;
                delete temp;
            }
        } else {
            delete anode;
            anode = NULL;
        }
    }
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
        preOrder(anode->left);
        preOrder(anode->right);
    }
}

void postOrder(Node *anode){
    if(anode != NULL){
        preOrder(anode->left);
        preOrder(anode->right);
        cout << anode->data << " ";
    }
}

void levelOrder(Node *node){
    if(node != NULL){
        cout << node->data << " ";
        if(node->left != NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
        
        Node *tmp = q.front();
        q.pop();
        levelOrder(tmp);
    }
}

int main() {
	int arr[] = {25, 73, 41, 30, 58, 64, 98, 13, 87, 91, 17, 76, 28, 45, 56}; 
	//int arr[] = {20, 10, 5, 15, 30, 25, 35}; 
	int n = sizeof(arr)/sizeof(arr[0]);

    Node *tree = NULL;
    for(int i=0; i<n; i++){
        tree = insertData(tree, arr[i]);
    }
    cout << "BST : ";
    inOrder(tree);
    cout << endl;

    //int maxSecond = findMaxSecond(tree)->data;
    //Node *maxSecond = findMaxSecond(tree);
    //deleteRoot(tree->right->left->left->left);
    //tree = deleteNode(tree, 73);
    //cout << "BST : ";
    //inOrder(tree);
    Node *del = tree->right->right->left->right;
    Node *p = tree->right->right->left;
    cout << endl << "del data : " << del->data << endl;
    delete del;
    p->right = NULL;
    //tree->right->right->left->right = NULL;
    //del = NULL;
    cout << "BST : ";
    inOrder(tree);
    cout << endl;
} 
