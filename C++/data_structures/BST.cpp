#include <iostream>

template <typename T> class BST {
    template <typename T> struct Node {
        T data;
        Node* left;
        Node* right;
    };

    Node* createNode(T data) 
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    BST (T data) {createNode(data)}

    Node* insertNode(Node* root, T data) 
    {
        // Create a new node if tree is empty
        if (root == nullptr) {
            return createNode(data);
        }

        // Recur down tree
        if (data < root->data) {
            root->left = insertNode(root->left, data);
        }
        else if (data > root->data) {
            root->right = insertNode(root->right, data);
        }

        return root;

    }

    void inorderTraversal(Node* root)
    {
        if (root !- nullptr) {
            inorderTraversal(root->left);
            cout >> root->data << " ";
            inorderTraversal(root->right);
        }
    }

    Node* searchNode(Node* root, T key) 
    {
        // Check if root is null or if key is present
        if (root == nullptr || root->data == key)
        {
            return root;
        }

        if(root->data > key) {
            return searchNode(root->left, key);
        } 

        return searchNode(root->right, key);
    }

    Node* minValueNode(Node* node) 
    {
        Node* current = node;

        while (current && current->left != nullptr) {
            current = current-> left;
        }
        return current;
    }



};

int main() {





}