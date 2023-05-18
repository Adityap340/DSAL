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

bool SearchValue(Node* root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return SearchValue(root->left, value);
    } else {
        return SearchValue(root->right, value);
    }
}

int main() {
    Node* root = NULL;

    // Construct binary search tree by inserting values
    int values[] = {10, 5, 15, 3, 7, 12, 20};
    int size = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < size; i++) {
        root = insertNode(root, values[i]);
    }

    cout << "Inorder traversal of the binary search tree: ";
    inorderTraversal(root);
    cout << endl;

    // Insert new node
    int newValue = 8;
    root = insertNode(root, newValue);
    cout << "Inorder traversal after inserting " << newValue << ": ";
    inorderTraversal(root);
    cout << endl;

    // Number of nodes in the longest path from root
    int height = getHeight(root);
    cout << "Number of nodes in the longest path from root: " << height << endl;

    // Minimum data value in the tree
    int minValue = getMinValue(root);
    cout << "Minimum value in the tree: " << minValue << endl;

    // Change tree so that left and right pointers are swapped
    swapChildren(root);
    cout << "Inorder traversal after swapping left and right pointers: ";
    inorderTraversal(root);
    cout << endl;

    // Search a value
    int searchValue = 7;
    bool found = SearchValue(root, searchValue);
    if (found) {
        cout << searchValue << " is found in the tree.\n";
    } else {
        cout << searchValue << " is not found in the tree.\n";
    }

    return 0;
}