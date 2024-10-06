#include<iostream>
using namespace std;

class CQueue{
 
 int arr[10];
 int front;
 int rear;

 public:
 CQueue(){
    front=-1;
    rear=-1;
 } 

 void Enque(int val){
    if((rear+1%10)==front){
        cout<<"Queue is Overflow.";
    }else if(front==-1){
        front++;
        arr[++rear]=val;
    }else {
        rear = (rear+1)%10;
         arr[rear]=val;
    }
   

 }

 void Deque(){
    if(rear==-1){
        cout<<"Queue is Empty.";
    }else if(front==rear){
        front=rear=-1;
    }else{
        cout<<"deleted "<<arr[front]<<endl;
        front = (front+1)%10;
    }
    
 }


 void print(){
    if(rear==-1){
        cout<<"Queue is Empty.";
        return;
    }
    int i=front;
   while(i!=rear){
    cout<<arr[i]<<" ";
    i=(i+1)%10;
   }
   cout<<arr[rear]<<" ";

 }

};

int main(){

    CQueue q1;
    q1.Enque(10);
    q1.Enque(20);
    q1.Enque(30);
    q1.Enque(40);
    q1.Enque(50);
    q1.Enque(60);
    q1.Enque(70);
    q1.Enque(80);
    q1.Enque(90);
    q1.Enque(100);
    q1.print();

    q1.Deque();
    q1.Deque();

    q1.Enque(200);
    q1.print();
}