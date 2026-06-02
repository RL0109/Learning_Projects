#include <iostream>


template <typename T> struct Node {
            T data;
            Node* left;
            Node* right;
};

template <typename T> Node<T>* createNode(T data) 
{
    Node<T>* newNode = new Node<T>();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

template <typename T> Node<T>* insertNode(Node<T>* root, T data) 
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

template <typename T> void inorderTraversal(Node<T>* root)
{
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

template <typename T> Node<T>* searchNode(Node<T>* root, T key) 
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

template <typename T> Node<T>* minValueNode(Node<T>* node) 
{
    Node<T>* current = node;

    while (current && current->left != nullptr) {
        current = current-> left;
    }
    return current;
}

template <typename T> Node<T>* maxValueNode(Node<T>* node) 
{
    Node<T>* current = node;

    while (current && current->right != nullptr) {
        current = current ->right;
    }
    return current;
}

int main() {

    Node<int>* root = nullptr;


    root = insertNode(root, 15);
    root = insertNode(root, 17);
    root = insertNode(root, 12);

    inorderTraversal(root);

    auto minimum = minValueNode(root);
    auto maximum = maxValueNode(root);

    std::cout << "\n";
    std::cout << maximum->data << "\n";
    std::cout << minimum->data << "\n";


}