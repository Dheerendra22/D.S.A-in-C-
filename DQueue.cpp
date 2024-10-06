#include<iostream>
using namespace std;

class DQueue{
 
 int arr[100];
 int front;
 int rear;

 public:
 DQueue(){
    front=-1;
    rear=-1;
 } 

 void EnqueatEnd(int val){
    if(rear==99){
        cout<<"Queue is Overflow.";
    }else if(front==-1){
        front++;
        rear++;
        arr[rear]=val;
    }else{
         rear++;
         arr[rear]=val;
    }
   

 }

 void DequeatBegin(){
    if(rear==-1){
        cout<<"Queue is Empty.";
    }else if(front==rear){
        front=rear=-1;
    }else{
        cout<<"deleted "<<arr[front]<<endl;
        front++;
    }
    
 }

 void DequeAtEnd(){
    if(rear==-1){
        cout<<"Queue is Empty.";
        return;
    }
     if(front==rear){
        cout<<"deleted "<<arr[rear]<<endl;
        front=rear=-1;
    }else{
        cout<<"deleted "<<arr[rear--]<<endl;
        
    }
 }

 void EnqueAtBegin(int val){
    if(rear==99){
        cout<<"Queue is Overflow.";
    }else if(front==-1){
        front++;
        rear++;
        arr[rear]=val;
    }else{
        for(int i=rear; i>=front; i--)
            arr[i+1]=arr[i];
        
        rear++;
        arr[front]=val;
        
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

 DQueue q1;
 q1.EnqueatEnd(100);
 q1.EnqueatEnd(200);
 q1.EnqueatEnd(300);
 q1.EnqueatEnd(400);
 q1.EnqueAtBegin(500);
 q1.DequeatBegin();
 q1.DequeatBegin();
 q1.DequeAtEnd();
 q1.DequeAtEnd();


 q1.print();


}