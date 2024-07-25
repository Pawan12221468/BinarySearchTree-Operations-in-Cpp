#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int key) : val(key), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    TreeNode* search(int key) {
        return search(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

private:
    TreeNode *root;

    TreeNode* insert(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }
        if (key < node->val) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }
        return node;
    }

    TreeNode* search(TreeNode* node, int key) {
        if (node == nullptr || node->val == key) {
            return node;
        }
        if (key < node->val) {
            return search(node->left, key);
        }
        return search(node->right, key);
    }

    TreeNode* deleteNode(TreeNode* node, int key) {
        if (node == nullptr) {
            return node;
        }
        if (key < node->val) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->val) {
            node->right = deleteNode(node->right, key);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteNode(node->right, temp->val);
        }
        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
};

int main() {
    BinarySearchTree bst;
    int choice, key;

    while (true) {
        cout << "\nBinary Search Tree Operations Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> key;
                bst.insert(key);
                cout << "Value inserted.\n";
                break;
            case 2:
                cout << "Enter the value to search: ";
                cin >> key;
                if (bst.search(key) != nullptr) {
                    cout << "Value found in the tree.\n";
                } else {
                    cout << "Value not found in the tree.\n";
                }
                break;
            case 3:
                cout << "Enter the value to delete: ";
                cin >> key;
                bst.deleteNode(key);
                cout << "Value deleted if it existed.\n";
                break;
            case 4:
                cout << "Exiting.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }

    return 0;
}