#include<iostream>
#include<queue>
using namespace std;

class Node{
  
 public:

    int data;
    Node* left;
    Node* right;

 Node(int val){
    data = val;
    left = NULL;
    right = NULL;
 }

 void preorder(){
    if(this != NULL){
        cout<<" "<<data<<" ";
        left->preorder();
        right->preorder();
    }
 }
 void postorder(){
    if(this != NULL){
        left->postorder();
        right->postorder();
        cout<<" "<<data<<" ";
    }
 }
 void inorder(){
    if(this != NULL){
        left->inorder();
        cout<<" "<<data<<" ";
        right->inorder();
    }
 }

 void levelorder(){
    queue<Node*> q1;
    cout<<this->data<<" ";
    q1.push(this->left);
    q1.push(this->right);

    while(!q1.empty()){
        if(q1.front()->left)
          q1.push(q1.front()->left);
        if(q1.front()->right)
          q1.push(q1.front()->right);

        cout<<q1.front()->data<<" ";
        q1.pop();
    }
 }

};

int main(){
    Node* root = new Node(5);
    root->left = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(10);

    root->right = new Node(3);
    root->right->left = new Node(2);
    root->right->left->right = new Node(1);
    root->right->left->right->left = new Node(14);
    root->right->left->right->left->left = new Node(15);

    cout<<"Preorder Traversal "<<endl;
    root->preorder();
    cout<<endl<<"Postorder Traversal "<<endl;
    root->postorder();
    cout<<endl<<"Inorder Traversal "<<endl;
    root->inorder();

    cout<<endl<<"Levelorder Traversal "<<endl;

    root->levelorder();


}