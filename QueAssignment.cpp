
/*Q. Implement Priority Queue using Linked Lists.*/

#include<iostream>
#include<list>
using namespace std;

class node{

 public:
 int value;
 int priority;

    // Constructor to initialize the node
    node(int v, int p) {
        value = v;
        priority = p;
    }
};

void Enque(list<node>& q1,int val,int prior=0){
    
    if(q1.empty()){
        q1.push_back(node(val,prior));
    }else {
         list<node>::iterator it;
         for (it = q1.begin(); it != q1.end(); ++it) {
            if(it->priority<=prior){
                break;
            }
    }

        q1.insert(it,node(val,prior));

    }
}

void print(list<node>& q1){

    list<node>::iterator it;
         for (it = q1.begin(); it != q1.end(); ++it) {
           cout << "value: "<<it->value <<" "<<"priority "<< it->priority << endl;
    }

}

void Deque(list<node>& q1){
    if (!q1.empty()) {
        // Access the front element
        node frontNode = q1.front();
        
        // Print the front element values
        cout << "Deleted value: " << frontNode.value << ", Priority: " << frontNode.priority << endl;
        
        // Remove the front element
        q1.pop_front();
    } else {
        cout << "The list is empty!" << endl;
    }
}


int main(){
    
    
    list<node> q1;
    
    Enque(q1,10,5);
    Enque(q1, 20, 2); 
    Enque(q1, 20, 7);
    Enque(q1, 20, 10);
    Enque(q1, 20);

    print(q1);

    return 0;


}

/* 7. Give an algorithm for reversing a queue Q. Only the following standard operations
 are allowed on queue.
 a. enqueue(x): Add an item x to the rear of the queue.
 b. dequeue(): Remove an item from the front of the queue.
 c. empty(): Checks if a queue is empty or not.  */

#include<iostream>
#include<queue>
using namespace std;

void reverse(queue<int>& q1){
    if(q1.empty())
      return;

    int front = q1.front();
    q1.pop();
    reverse(q1);
    q1.push(front);
}

void print(queue<int> q1){

    while (!q1.empty()) {
        cout << q1.front() << " ";  // Print the front element
        q1.pop();                   // Remove the front element from the copy
    }
    cout << endl;

}

int main(){

    queue<int> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);

    reverse(q1);
    print(q1);
    

}

/*  8. Given an integer k and a queue of integers, The task is to reverse the order of the
 first k elements of the queue, leaving the other elements in the same relative order.
 Only following standard operations are allowed on queue.
 a. enqueue(x) : Add an item x to rear of queue
 b. dequeue() : Remove an item from front of queue
 c. size() : Returns the number of elements in the queue.
 d. front() : Finds front item  */


#include<iostream>
#include<deque>
#include<queue>
using namespace std;

void reversek(queue<int>& q1, int k) {
    if (k <= 0 || k > q1.size()) {
        return;  // Handle invalid 'k' values
    }

    // Use a deque to reverse the first k elements
    deque<int> d1;
    for (int i = 0; i < k; i++) {
        d1.push_front(q1.front());  // Push front to reverse the order
        q1.pop();
    }

    // Push the reversed first k elements back into the queue
    while (!d1.empty()) {
        q1.push(d1.front());
        d1.pop_front();
    }

    // Move the remaining elements back to the queue in original order
    int remain = q1.size() - k;
    for (int i = 0; i < remain; i++) {
        q1.push(q1.front());
        q1.pop();
    }
}

void print(queue<int> q1){

    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();                  
    }
    cout << endl;

}

int main(){
  queue<int> q1 ;
  q1.push(10);
  q1.push(20);
  q1.push(30);
  q1.push(40);
  q1.push(50);
  
  reversek(q1,3);
  print(q1);

  return 0;
}

/*  9. Given a queue with random elements, we need to sort it. We are not allowed to use
 extra space. The operations allowed on queue are :
 a. enqueue(x) : Add an item x to rear of queue
 b. dequeue() : Remove an item from front of queue
 c. isEmpty() : check if a queue is empty.  */


 // i will do this later !!
 


#include<iostream>
#include<queue>
using namespace std;

void removeNum(queue<int>& q1,int num){
    for(int i=0; i<q1.size(); i++){
        if(q1.front()==num){
            q1.pop();
        }else {
            q1.push(q1.front());
            q1.pop();
        }
    }
}

void sort(queue<int>& q1){
    if(q1.empty())
      return;

    int small=10000;
    int  size=q1.size();

    for(int i=0; i<size; i++){
        if(q1.front()<small){
            small=q1.front();
            q1.push(small);
            q1.pop();
        }else{
            q1.push(q1.front());
            q1.pop();
        }    
        
    }

    removeNum(q1,small);
    sort(q1);
    q1.push(small);
}



void print(queue<int> q1){

    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();                  
    }
    cout << endl;

}

int main(){
    
    queue<int> q1;
    q1.push(1);
    q1.push(5);
    q1.push(3);
    q1.push(9);
    q1.push(4);
    q1.push(11);
    q1.push(2);

    sort(q1);
    print(q1);
    
    return 0;
}
 

 /* 10. There are given N ropes of different lengths, we need to connect these ropes into
 one rope. The cost to connect two ropes is equal to the sum of their lengths. The task
 is to connect the ropes with minimum cost. Given N size array arr[] contains the
 lengths of the ropes.
 Example 1:
 Input:
 n = 4
 arr[] = {4, 3, 2, 6}
 Output:
 29
 Explanation:
 We can connect the ropes in following ways.
 1) First connect ropes of lengths 2 and 3. Which makes the array {4, 5, 6}.
 Cost of
 this operation 2+3 = 5.
 2) Now connect ropes of lengths 4 and 5. Which makes the array {9, 6}. Cost
 of
 this operation 4+5 = 9.
3) Finally connect the two ropes and all ropes have connected. Cost of this
 operation 9+6 =15
 Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized
 cost for connecting ropes. Other ways of connecting ropes would always have
 same or more cost. For example, if we connect 4 and 6 first (we get three
 rope of 3, 2 and 10), then connect 10 and 3 (we get two rope of 13 and 2).
 Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.  */