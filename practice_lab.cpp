#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value){
    Node* newNode = new Node();
    if(!newNode){
        cout<<"Memorry error\n";
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value){
    if(root==NULL){
        root=createNode(value);
        return root;
    }
    if(value < root->data){
        root->left=insertNode(root->left,value);
    }
    else if(value > root->data){
        root->right = insertNode(root->right, value);
    }
    return root;
}

void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
int getHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight)+1;
}

int getMinValue(Node*root){
    if(root == NULL){
        cout<<"Tree is empty\n";
        return -1;
    }
    while(root->left != NULL){
        root=root->left;
    }
    return root->data;
}

void swapChildren(Node* root){
    if( root == NULL ){
        return;
    }
    swapChildren(root->left);
    swapChildren(root->right);
    swap(root->left, root->right);
}

bool searchValue(Node* root, int value){
    if(root==NULL){
        return false;
    }
    if(root->data == value){
        return true;
        if(value < root->data){
            return searchValue(root->left, value);
        }
        else{
            return searchValue(root->right, value);
        }
    }
}

int main()
{
    Node* root = NULL;
    cout<<"BST\n";
    cout<<"Enter values(enter -1 tp stop): "<<endl;
    int value;
    while(true){
        cin>>value;
        if(value==-1){
            break;
        }
        root = insertNode(root , value);
    }

    cout<<"Inorder Traversal: ";
    inorderTraversal(root);
    cout<<endl;

    int newValue;
    cout<<"Enter new value to insert: ";
    cin>>newValue;
    root = insertNode(root, newValue);
    cout<<endl;

    cout<<"Inorder traversal after insertion: ";
    inorderTraversal(root);
    cout<<endl;

    cout<<"Minimum value in tree: "<<getMinValue(root)<<endl;

    swapChildren(root);
    cout<<"Inorder traversal after swapping child nodes: ";
    inorderTraversal(root);
    cout<<endl;

    int key;
    cout<<"Enter value to be searched: ";
    cin>>key;
    bool found = searchValue(root , key);
    if(found){
        cout<<key<<" is found in the tree.\n";
    }
    else{
        cout<<key<<" not found in the tree.\n";
    }
    return 0;
}