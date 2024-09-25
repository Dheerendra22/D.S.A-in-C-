/* Q.1. An example of a linked list with a random pointerGiven a linked list of size N where
 each node has two links: one pointer points to the next node and the second pointer
 points to any node in the list. The task is to create a clone of this linked list in O(N)
 time*/

// #include<iostream>
// using namespace std;

// class node{
//     public:
//     int value;
//     node* next;
//     node* random;
    
//     node(int val){
//         value=val;
//         next=NULL;
//         random=NULL;
//     }
// };

// node* cloneHead(node* head){

//     node* cur = head;

//     // creation of clone nodes

//     while(cur!=NULL){
//         node* temp = new node(cur->value);
//         temp->next = cur->next;
//         cur->next = temp;
//         cur= cur->next->next;
//     }

//     cur = head;
    
//     while(cur!=NULL){

//         if(cur->random!=NULL){
//             cur->next->random=cur->random->next;
//         }
//         cur=cur->next->next;

//     }

//     cur = head;

//     node* clonehead = head->next;
//     node* temp = clonehead;

//     while(cur!=NULL){
//         cur->next = temp->next;
//         if (temp->next != NULL) {
//             temp->next = temp->next->next;
//         }
//         cur = cur->next;
//         temp = temp->next;
//     }

//     return clonehead;
    
// }

// void printList(node* head) {  // Change Node* to node*
//     node* curr = head;
//     while (curr != nullptr) {
//         cout << "Node: " << curr->value;
//         if (curr->random) {
//             cout << " | Random points to: " << curr->random->value;
//         } else {
//             cout << " | Random points to: nullptr";
//         }
//         cout << endl;
//         curr = curr->next;
//     }
// }



// int main(){

//     node* head = new node(10);
//     head->next = new node(20);
//     head->next->next = new node(30);
//     head->next->next->next = new node(40);
//     head->next->next->next->next = new node(50);


//     head->random = head->next->next;
//     head->next->random = head;
//     head->next->next->random = head->next->next->next->next;
//     head->next->next->next->random = head->next->next;
//     head->next->next->next->next->random = head->next;


//     node* clonehead = cloneHead(head);

//     printList(clonehead);


//     return 0;

// }

/* Q.2. Given a sorted doubly linked list of positive distinct elements, the task is to find pairs
 in a doubly-linked list whose sum is equal to given value x, without using any extra
 space? */

//  #include<iostream>
//  #include<list>
//  #include<iterator>
//  using namespace std;

//  void findpair(list<int> l1,int val){
//     list<int>::iterator x;
//     for(x = l1.begin(); x!=l1.end(); x++){
//         for(list<int>::iterator y = next(x); y!=l1.end(); y++){
//             if(*x+*y==val){
//                 cout<<"("<<*x<<","<<*y<<")"<<endl;
//             }
//         }
//     }
//  }

//  int main(){
//     list<int> list1;
//     list1.assign({1,2,4,5,6,8,9});
//     findpair(list1,7);
//  }

 /* Q. 3. Given a sorted doubly linked list and a value to insert, write a function to insert the
 value in a sorted way. Initial doubly linked list  */

//  #include<iostream>
//  #include<list>
//  #include<iterator>
//  using namespace std;

//  void insertCorrectPosition(list<int>& l1,int val){

//     list<int> :: iterator it;

//     for(it=l1.begin(); it!=l1.end(); it++){
//         if(*it>val)
//           break;
//     }
//     l1.insert(it,val);
//  }

//  void print(list<int>& l1){
//     for(int x:l1){
//         cout<<x<<" <=> ";

//     }
//  }


//  int main(){
//     list<int> l1;
//     l1.assign({1,2,3,5,6,7});
//     insertCorrectPosition(l1,4);
//     insertCorrectPosition(l1,10);
//     print(l1);


//  }

 /* Q.4. Given a unsorted doubly linked list containing n nodes. The problem is removing
 duplicate nodes from the given list.  */
 
//  #include<iostream>
//  #include<list>
//  #include<iterator>
//  using namespace std;

//  void remove_duplicate(list<int>& l1){

//     for(auto i=l1.begin(); i!=l1.end(); i++){
//         for(auto j = next(i); j!=l1.end(); j++){
//             if(*i==*j){
//                 j = l1.erase(j);
//                 j--;
//             }
             
//         }
//     }

//  }

//  void print(list<int>& l1){
//     for(int x:l1){
//         cout<<x<<" <=> ";

//     }
//  }


//  int main(){
//      list<int> l1;
//     l1.assign({1,2,1,5,5,2});

//     remove_duplicate(l1);

//     print(l1);

//     return 0;
//  }

 /* Q.7. Given a doubly-linked list, rotate the linked list counter-clockwise by N nodes. Here N
 is a given positive integer and is smaller than the count of nodes in the linked list  */


//  #include<iostream>
//  #include<list>
//  #include<iterator>
//  using namespace std;

//  void counterClockwise(list<int>& l1,int n){
//     int num;
//     cout<<"How many number you want to  rotate the linked list counter-clockwise ? ";
//     cin>>num;

//     list<int> :: iterator it = l1.begin();

//     if(num<n){
//         for(int i=0;i<num;i++){

//             l1.push_back(l1.front());
//             l1.pop_front();
//         }
//         return;
//     }else{
//         cout<<"rotation number should be smaller than the count of nodes in the linked list.";
//         return;
//     }

//  }

//  void print1(list<int> l1){
//     for(int x:l1){
//         cout<<x<<" <=> ";

//     }
//  }

//  int main(){
//     list<int> l1;
//     int n;
//     cout<<"How many integers you want to enter ? ";
//     cin>>n;
//     for(int i=0;i<n; i++){
//         int x ;
//         cin>>x;
//         l1.push_back(x);
//     }
//     counterClockwise(l1,n);
//     print1(l1);

//  }

 /*Q. 9. Given a Doubly linked list containing N nodes, the task is to remove all the nodes
 from the list which contains elements whose digit sum is even.
 Example:
 Input: DLL = 18 <=> 15 <=> 8 <=> 9 <=> 14
 Output: 18 <=> 9 <=> 14  */

//  #include<iostream>
//  #include<list>
//  #include<iterator>
//  using namespace std;

//  list<int> removeEven(list<int>& l1){
//     list<int> output;
    
//     for(int x:l1){
//         int y=x;
//         int sum=0;
//         while(x!=0){
//             sum+=x%10;
//             x/=10;
//         }
//         if(sum%2!=0)
//            output.push_back(y);
//     }
//     return output;

//  }

//  void print1(list<int> l1){
//     for(int x:l1){
//         cout<<x<<" <=> ";

//     }
//  }

//  int main(){
//     list<int> l1;
//     l1.assign({18,15,8,9,14});

//     list<int> l2 = removeEven(l1);
//     print1(l2);
//  }

/* Q.10. Given a doubly linked list containing N nodes, the task is to remove all the nodes
 from the list which contains Fibonacci numbers.
 Example:
 Input: DLL = 15 <=> 16 <=> 8 <=> 7 <=> 13
 Output: 15 <=> 16 <=> 7   */

//  #include<iostream>
//  #include<list>
//  #include<iterator>
//  #include <cmath>
//  using namespace std;

//  // Function to check if a number is a perfect square
// bool isPerfectSquare(int x) {
//     int s = sqrt(x);
//     return (s * s == x);
// }
// bool isFibonacci(int n) {
//     // Check if 5*n^2 + 4 or 5*n^2 - 4 is a perfect square
//     return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
// }

//  list<int> removeFibbonacci(list<int>& l1){
//    list<int> result;
//    list<int> :: iterator it;
//    for(it=l1.begin(); it!=l1.end();it++){
//        if(!isFibonacci(*it))
//          result.push_back(*it);
//    }

//    return result;
    
//  }

//  void print1(list<int> l1){
//     for(int x:l1){
//         cout<<x<<" <=> ";

//     }
//  }

//  int main(){
//     list<int> l1;
//     l1.assign({15,16,8,7,13});

//     list<int> l2 = removeFibbonacci(l1);
//     print1(l2);

//     return 0;


//  }

/* 6. Sort the given biotonic doubly linked list. A biotonic doubly linked list is a doubly
 linked list which is first increasing and then decreasing. A strictly increasing or a
 strictly decreasing list is also a biotonic doubly linked list.  */

//  #include<iostream>
//  #include<list>
//  #include<iterator>
//  using namespace std;

//  void sortBiotonic(list<int>& l1){
//      list<int> l2;
    
//     // Split the list into two parts: increasing (l1) and decreasing (l2)
//     auto it = next(l1.begin()); // Start from the second element
//     while (it != l1.end()) {
//         auto prevIt = prev(it);
        
//         // If the current element is smaller than the previous one, it's part of the decreasing section
//         if (*prevIt > *it) {
//             l2.push_front(*it);  // Add to the front of l2 to reverse the order
//             it = l1.erase(it);    // Remove the current element from l1 and move iterator to the next element
//         } else {
//             ++it;
//         }
//     }

//       // Merge l2 into l1 (both are sorted now)
//     for (auto i = l2.begin(); i != l2.end(); i++) {
//         for (auto j = l1.begin(); j != l1.end(); j++) {
//             if (*i <= *j) {
//                 l1.insert(j, *i);
//                 break;
//             }
//         }
//     }

//  }

//  void printList(const list<int>& l1) {
//     for (auto x : l1) {
//         cout << x << " <=> ";
//     }
//     cout << "NULL" << endl;
// }


// int main(){
//     list<int> l1;
//     l1.assign({1,2,3,4,5,6,4,3,2});

//     cout << "Original List: " << endl;
//     printList(l1);

//     sortBiotonic(l1);

//     cout << "Sorted List: " << endl;
//     printList(l1);

//     return 0;
// }

/* 2. Given a sorted circular doubly linked list of distinct nodes(no two nodes have the
 same data) and a value x. Count triplets in the list that sum up to a given value x.     */

//  #include<iostream>
//  #include<list>
//  #include<iterator>
//  using namespace std;

//  void findTriplets(list<int>& l1,int val){

//     bool found = false;

//     for (auto it1 = l1.begin(); it1 != prev(prev(l1.end())); ++it1) {
//         auto it2 = next(it1);
//         for (auto it3 = next(it2); it3 != l1.end(); ++it3) {
//             int sum = *it1 + *it2 + *it3;
            
//             if (sum == val) {
//                 cout << "(" << *it1 << ", " << *it2 << ", " << *it3 << ")" << endl;
//                 found = true;
//             }
//         }
//     }

//     if (!found) {
//         cout << "No triplet exists!" << endl;
//     }
    

//  }

//  int main(){

//     list<int> l1 = {2,3,5,7,8};
//     findTriplets(l1,15);

//  }

 /* Given a circular singly linked list containing N nodes, the task is to delete all the odd
 nodes from the list.  */


//  #include<iostream>
//  #include<list>
//  #include<iterator>
//  using namespace std;

//  void deleteOddNodes(list<int>& l1){
 
//   auto it = l1.begin();
//   while(it!=l1.end()){
//    it=next(l1.erase(it));
//   }

//  }


//   void print1(list<int> l1){
//     for(int x:l1){
//         cout<<x<<" <=> ";

//     }
//     cout<<"NULL";
//  }

//  int main(){
//    list<int> l1 = {1,2,3,4,5,6};
//    deleteOddNodes(l1);
//    print1(l1);
//  }

 /* Given a circular doubly linked list containing n nodes. The problem is to reverse
 every group of k nodes in the list.  */

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void reverseNodes(list<int>& l1, int k) {
    if (l1.empty() || k <= 1) return;  // No need to reverse if the list is empty or k is too small

    auto start = l1.begin();
    auto nextStart = start;

    while (start != l1.end()) {
        auto Next = start;
        
        // Move the `Next` iterator to the end of the current group of `k` nodes
        int count = 0;
        while (count < k && Next != l1.end()) {
            Next++;
            count++;
        }

        if (count < k) break;  // If less than k nodes remain, no need to reverse

        nextStart = Next;  // This marks the start of the next group

        // Now reverse the current group of `k` nodes (from `start` to `Next`)
        auto tempStart = start;
        auto tempEnd = prev(Next);

        // Corrected reversal loop: stop when tempStart and tempEnd meet or cross
        while (tempStart != tempEnd && tempStart != next(tempEnd)) {
            int temp = *tempStart;
            *tempStart = *tempEnd;
            *tempEnd = temp;

            tempStart++;
            tempEnd--;
        }

        start = nextStart;  // Move to the next group
    }
}

// Function to print the list
void print1(const list<int>& l1) {
    for (auto it = l1.begin(); it != l1.end(); ++it) {
        cout << *it;
        if (next(it) != l1.end()) {
            cout << " <=> ";  // Print separator for all elements except the last one
        }
    }
    cout << endl;
}

int main() {
    list<int> l1 = {1, 2, 3, 4, 5,6};  // Example list
    int k = 2;

    cout << "Original List: ";
    print1(l1);

    reverseNodes(l1, k);

    cout << "Reversed in groups of " << k << ": ";
    print1(l1);

    return 0;

}






