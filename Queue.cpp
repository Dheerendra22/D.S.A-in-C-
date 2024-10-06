#include<iostream>
using namespace std;

class Queue{
 
 int arr[100];
 int front;
 int rear;

 public:
 Queue(){
    front=-1;
    rear=-1;
 } 

 void enque(int val){
    if(rear==99){
        cout<<"Queue is Overflow.";
    }else if(front==-1){
        front++;
        rear++;
        arr[rear]=val;
        return;
    }else{
         rear++;
         arr[rear]=val;
    }
   

 }

 void deque(){
   if(front==rear){
        front=rear=-1;
    }else{
        cout<<"deleted "<<arr[front]<<endl;
        front++;
    }
    
 }


 void print(){
    if(rear==-1){
        cout<<"Queue is Empty.";
        return;
    }
    for(int i=front; i<=rear; i++){
        cout<<arr[i]<<" ";
    }
 }

};

 
int main(){

 Queue q1;
 q1.enque(100);
 q1.enque(200);
 q1.enque(300);
 q1.enque(400);
 q1.deque();
 q1.deque();
 q1.deque();
 q1.deque();

 q1.print();


}