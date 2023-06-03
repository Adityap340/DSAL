#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
        return root;
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int getHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int getMinValue(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty\n";
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

void swapChildren(Node* root) {
    if (root == NULL) {
        return;
    }
    swapChildren(root->left);
    swapChildren(root->right);
    swap(root->left, root->right);
}

bool searchValue(Node* root, int value) {
    if (root == NULL) {
        return false;
    } 
    if (root->data == value) {
        return true;
        if (value < root->data) {
            return searchValue(root->left, value);
        } 
        else {
        return searchValue(root->right, value);
        }
    }
}

int main() {
    Node* root = NULL;

    cout << "Binary Search Tree Construction\n";
    cout << "Enter values to insert into the tree (enter -1 to stop):\n";

    int value;
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        root = insertNode(root, value);
    }

    cout << "Inorder traversal of the binary search tree: ";
    inorderTraversal(root);
    cout << endl;

    int newValue;
    cout << "Enter a value to insert into the tree: ";
    cin >> newValue;
    root = insertNode(root, newValue);

    cout << "Inorder traversal after inserting " << newValue << ": ";
    inorderTraversal(root);
    cout << endl;

    int height = getHeight(root);
    cout << "Number of nodes in the longest path from root: " << height << endl;

    int minValue = getMinValue(root);
    cout << "Minimum value in the tree: " << minValue << endl;

    swapChildren(root);
    cout << "Inorder traversal after swapping left and right pointers: ";
    inorderTraversal(root);
    cout << endl;

    int valueToSearch;
    cout << "Enter a value to search in the tree: ";
    cin >> valueToSearch;
    bool found = searchValue(root, valueToSearch);
    if (found) {
        cout << valueToSearch << " is found in the tree.\n";
    } else {
        cout << valueToSearch << " is not found in the tree.\n";
    }

    return 0;
}
