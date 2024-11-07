#include<iostream>
using namespace std;

// Binary Search Tree (BST) class definition
class BST {

    // Private members to store data and left, right children
    int data;
    BST* left;
    BST* right;

public:

    // Constructor to initialize a node with given value
    BST(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    // Function to insert a new value into the BST
    BST* insertion(int val) {
        // If the node exists, recursively call insertion for left or right subtree
        if (this) {
            if (this->data <= val)
                this->right = this->right->insertion(val);
            else {
                this->left = this->left->insertion(val);
            }
        } else {
            // If the current node is NULL, create a new node
            return new BST(val);
        }
        return this;
    }

    // Function to calculate the height of the BST
    int height(BST* root) {
        if (root) {
            // Recursively calculate the height of left and right subtrees
            int leftHeight = height(root->left) + 1;
            int rightHeight = height(root->right) + 1;

            // Return the larger height
            return (leftHeight > rightHeight) ? leftHeight : rightHeight;
        }
        return 0;  // Base case: NULL node has height 0
    }

    // Function to find the minimum value in the BST (leftmost node)
    BST* minimum() {
        if (!this) {
            return NULL;
        } else if (!this->left) {
            // If there is no left child, this node is the minimum
            return this;
        } else {
            // Recursively find the minimum in the left subtree
            return this->left->minimum();
        }
    }

     // Function to find the minimum value in the BST (leftmost node)
    BST* maximum() {
        if (!this) {
            return NULL;
        } else if (!this->right) {
            // If there is no left child, this node is the minimum
            return this;
        } else {
            // Recursively find the minimum in the left subtree
            return this->right->minimum();
        }
    }

    // Function to delete a node with the given value from the BST
    BST* deletion(int val) {
        if (!this) {
            return NULL;  // Base case: node not found
        } else if (data < val) {
            // Recursively delete from the right subtree if value is greater
            this->right = this->right->deletion(val);
        } else if (data > val) {
            // Recursively delete from the left subtree if value is smaller
            this->left = this->left->deletion(val);
        } else {
            // Node found: check for different deletion cases
            if (this->right == NULL && this->left == NULL) {
                // Case 1: Node has no children (leaf node)
                delete this;
                return NULL;
            } else if (this->right == NULL) {
                // Case 2: Node has only left child
                BST* temp = this->left;
                delete this;
                return temp;
            } else if (this->left == NULL) {
                // Case 3: Node has only right child
                BST* temp = this->right;
                delete this;
                return temp;
            } else {
                // Case 4: Node has two children
                // Find the minimum value in the right subtree
                BST* min = this->right->minimum();
                // Replace current node's data with the minimum value
                this->data = min->data;
                // Delete the minimum node from the right subtree
                this->right = this->right->deletion(min->data);
            }
        }
        return this;
    }

    // Function for in-order traversal (left-root-right)
    void inorder() {
        if (this != NULL) {
            left->inorder();  // Traverse the left subtree
            cout << " " << data << " ";  // Print current node's data
            right->inorder();  // Traverse the right subtree
        }
    }

    // Function to search for a value in the BST
    void search(int value) {
        if (this->data == value) {
            cout << "Given value exists!" << endl;
            return;
        } else if (value > this->data) {
            // Recursively search in the right subtree
            this->right->search(value);
        } else {
            // Recursively search in the left subtree
            this->left->search(value);
        }
    }
};

int main() {
    // Create a root node with value 25
    BST* root = new BST(25);
    
    // Insert values into the BST
    root->insertion(20);
    root->insertion(10);
    root->insertion(40);
    root->insertion(30);
    root->insertion(12);

    // Delete node with value 40
    root->deletion(40);
    
    // Perform in-order traversal to print the BST
    root->inorder();
}
