/* Q. 1. Write a program to print 3rd level all node in a tree */

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

// Definition of a Node class for a binary tree
class Node {
  
public:
    int data;          // Data stored in the node
    Node* left;        // Pointer to the left child
    Node* right;       // Pointer to the right child

    // Constructor to initialize a node with a value
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    int height() {
        if (this) {
            // Recursively calculate the height of the left and right subtrees
            int leftHeight =this->left->height() + 1;
            int rightHeight = this->right->height() + 1;

            // Return the larger of the two heights
            return (leftHeight > rightHeight) ? leftHeight : rightHeight;
        }
        return 0;  // Base case: height is 0 for a NULL node
    }


    // Function to print all nodes at a given level
    void currentLevel(Node* root, int level) {
        if (root) {
            // Base case: if level is 0, print the current node
            if (level == 0) {
                cout << root->data << " ";
            } else {
                // Recursively call for left and right subtrees with level-1
                currentLevel(root->left, level - 1);
                currentLevel(root->right, level - 1);
            }
        }
    }

    // Function to print nodes at a specific level
    void printLevelOrder(int level) {
        int treeHeight = this->height();  // Get the height of the tree
        
        // Check if the given level is within the height of the tree
        if (level < treeHeight) {
            currentLevel(this, level);  // Print nodes at the given level
        } else {
            cout << "Invalid Given Level";  // Handle invalid levels
        }
    }

    int diameter(){                      // 6. find length of the diameter of the tree.
    return this->left->height()+this->right->height()+1;
   }


    // Zigzag Level Order Traversal
    void zigzagLevelOrder() {
        if (this == NULL) return;  // If the tree is empty, return

        deque<Node*> dq;            // Deque to process nodes in zigzag manner
        dq.push_back(this);         // Start by pushing the root node into the deque
        bool leftToRight = true;    // Flag to alternate the direction of printing

        while (!dq.empty()) {
            int size = dq.size();   // Get the number of nodes at the current level
            for (int i = 0; i < size; i++) {
                if (leftToRight) {
                    // Process from left to right
                    Node* current = dq.front();
                    dq.pop_front();
                    cout << current->data << " ";
                    
                    // Insert children left to right (normal order)
                    if (current->left) dq.push_back(current->left);
                    if (current->right) dq.push_back(current->right);
                } else {
                    // Process from right to left
                    Node* current = dq.back();
                    dq.pop_back();
                    cout << current->data << " ";
                    
                    // Insert children right to left (reverse order)
                    if (current->right) dq.push_front(current->right);
                    if (current->left) dq.push_front(current->left);
                }
            }
            // Toggle the direction for the next level
            leftToRight = !leftToRight;
            cout << endl;  // Print newline after each level for better readability
        }
    }

    void reverseZigzagLevelOrder() {
    if (this == NULL) return;

    deque<Node*> dq;
    dq.push_back(this);
    bool leftToRight = true;
    vector<vector<int>> levels;  // To store each level for reverse printing

    while (!dq.empty()) {
        int size = dq.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            if (leftToRight) {
                Node* current = dq.front();
                dq.pop_front();
                level.push_back(current->data);

                if (current->left) dq.push_back(current->left);
                if (current->right) dq.push_back(current->right);
            } else {
                Node* current = dq.back();
                dq.pop_back();
                level.push_back(current->data);

                if (current->right) dq.push_front(current->right);
                if (current->left) dq.push_front(current->left);
            }
        }

        levels.push_back(level);  // Store current level
        leftToRight = !leftToRight;
    }

    // Print levels in reverse order
    for (int i = levels.size() - 1; i >= 0; i--) {
        for (int val : levels[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
}

    
};

int main() {
    // Create the binary tree structure
    Node* root = new Node(5);
    root->left = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(10);

    root->right = new Node(3);
    root->right->left = new Node(2);
    root->right->left->right = new Node(1);
    root->right->left->right->left = new Node(14);
    root->right->left->right->left->left = new Node(15);

    // Print all nodes at level 3
    root->printLevelOrder(3);

    cout<<endl<<"the Diameter of the tree is "<<root->diameter()<<endl;

    root->zigzagLevelOrder();

    root->reverseZigzagLevelOrder();

    return 0;
}

