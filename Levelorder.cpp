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

 int height(Node* root){
   if(root){
      int left = height(root->left)+1;
      int right = height(root->right)+1;

      if(left>right)
       return left;
      else 
       return right;
   }
   return 0;
 }

 void currentLevel(Node* root,int level){
    if(root){
        if(level==0){
            cout<<root->data<<" ";
        }else {
            currentLevel(root->left,level-1);
            currentLevel(root->right,level-1);

        }
    }

 }

 void printLevelOrder(){
    int h = height(this);
    for(int i=0; i<h; i++){
        currentLevel(this,i);
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

    root->printLevelOrder();

 }