#include <iostream>
#include <string>
using namespace std;

struct Node {
    string keyword;
    string meaning;
    Node* left;
    Node* right;
};

class Dictionary {
private:
    Node* root;

    Node* createNode(string keyword, string meaning) {
        Node* newNode = new Node;
        newNode->keyword = keyword;
        newNode->meaning = meaning;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    Node* insertNode(Node* root, string keyword, string meaning) {
        if (root == nullptr) {
            root = createNode(keyword, meaning);
            return root;
        }

        if (keyword < root->keyword) {
            root->left = insertNode(root->left, keyword, meaning);
        } else if (keyword > root->keyword) {
            root->right = insertNode(root->right, keyword, meaning);
        }

        return root;
    }

    Node* findMinNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, string keyword) {
        if (root == nullptr)
            return root;

        if (keyword < root->keyword) {
            root->left = deleteNode(root->left, keyword);
        } else if (keyword > root->keyword) {
            root->right = deleteNode(root->right, keyword);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMinNode(root->right);
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->keyword);
        }
        return root;
    }

    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->keyword << ": " << root->meaning << endl;
            inorderTraversal(root->right);
        }
    }

    void postorderTraversal(Node* root) {
        if (root != nullptr) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout << root->keyword << ": " << root->meaning << endl;
        }
    }

    void preorderTraversal(Node* root) {
        if (root != nullptr) {
            cout << root->keyword << ": " << root->meaning << endl;
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }

    int getMaxComparisons(Node* root, string keyword, int count) {
        if (root == nullptr)
            return count;

        if (root->keyword == keyword)
            return count + 1;

        if (keyword < root->keyword)
            return getMaxComparisons(root->left, keyword, count + 1);

        return getMaxComparisons(root->right, keyword, count + 1);
    }

public:
    Dictionary() {
        root = nullptr;
    }

    void addKeyword(string keyword, string meaning) {
        root = insertNode(root, keyword, meaning);
    }

    void deleteKeyword(string keyword) {
        root = deleteNode(root, keyword);
    }

    void displayAscending() {
        inorderTraversal(root);
    }

    void displayDescending() {
        postorderTraversal(root);
    }

    void displayPreorder() {
        preorderTraversal(root);
    }

    int getMaxComparisons(string keyword) {
        return getMaxComparisons(root, keyword, 0);
    }
};

int main() {
    Dictionary dictionary;

    // Adding new keywords
    dictionary.addKeyword("Apple", "A fruit");
    dictionary.addKeyword("Banana", "A tropical fruit");
    dictionary.addKeyword("Cat", "A domestic animal");
    dictionary.addKeyword("Dog", "A domestic animal");
    dictionary.addKeyword("Elephant", "A large animal");

    cout << "Ascending Order:" << endl;
    dictionary.displayAscending();

    cout << "\nDescending Order:" << endl;
    dictionary.displayDescending();

    cout << "\nPreorder Traversal:" << endl;
    dictionary.displayPreorder();

    cout << "\nMax Comparisons for 'Cat': " << dictionary.getMaxComparisons("Cat") << endl;

    // Deleting a keyword
    dictionary.deleteKeyword("Apple");

    cout << "\nAscending Order after deleting 'Apple':" << endl;
    dictionary.displayAscending();

    return 0;
}