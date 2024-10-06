#include<iostream>
using namespace std;

class PQueue{
 
 int arr[10];
 int front;
 int rear;

 public:
 PQueue(){
    front=-1;
    rear=-1;
 }

 void Enque(int val){
    if(rear==9){
        cout<<"Queue is overflow.";
    }else if(front==-1){
    front++;
    arr[++rear]=val;
   }else if(val>=arr[front]){
    for(int i=rear; i>=front; i--){
        arr[i+1]=arr[i];
    }
    arr[front]=val;
    rear++;
   }else if(val<arr[front]){
    int i=0;
    for(i=front+1; i<=rear; i++){
        if(val>=arr[i])
          break;
    }
    for(int j=rear; j>=i; j--){
        arr[j+1]=arr[j];
    }
    arr[i]=val;
    rear++;

   } 

 }

  void Deque(){
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

 PQueue q1;
 q1.Enque(100);
 
 q1.Enque(400);
 q1.Enque(200);
 q1.Enque(300);
 q1.Enque(500);
 q1.Enque(50);

 q1.Deque();
 
 q1.print();


}

