/* 9. In a singly linked list of characters, write a function that returns true if the given list is
 a palindrome, else false. */

// #include<iostream>
// #include<forward_list>
// #include<iterator>
// #include<string>
// #include <algorithm>
// using namespace std;

// void checkPalindrome(forward_list<char> fr){
//     string original ="";

//      // Convert the forward_list to a string
//     for (char c : fr) {
//         original += c;
//     }
//     string reversed = original;

//     reverse(reversed.begin(), reversed.end());

//     // Check if the original string is equal to the reversed string
//     if (original == reversed) {
//         cout << "The string is a palindrome." << endl;
//     } else {
//         cout << "The string is not a palindrome." << endl;
//     }
// }
// int main(){
//     forward_list<char> fl;
//     fl.assign({'r','a','c','e','c','a','r'});
//     checkPalindrome(fl);
// }

/* 10. Given a singly linked list, find the middle of the linked list. For example, if the given
 linked list is 1->2->3->4->5 then the output should be 3.
 If there are even nodes, then there would be two middle nodes, we need to print the
 second middle element. For example, if the given linked list is 1->2->3->4->5->6 then
 the output should be 4   */

//  #include<iostream>
//  #include<forward_list>
//  #include <iterator>
//  using namespace std;

//  void findMiddle(forward_list<int>& list) {
//     auto slow = list.begin(); // Iterator for the slow pointer
//     auto fast = list.begin(); // Iterator for the fast pointer

    
//     while (fast != list.end() && next(fast) != list.end()) {
//         ++slow;                    // Move slow pointer by 1
//         fast = next(next(fast));  // Move fast pointer by 2
//     }

//     // Output the middle element
//     if (slow != list.end()) {
//         cout << "Middle element: " << *slow << endl;
//     } else {
//         cout << "List is empty." << endl;
//     }
// }

// int main() {
//     // Create a forward_list with some values
//     forward_list<int> myList = {1, 2, 3, 4, 5, 6};

//     // Find and print the middle element
//     findMiddle(myList);

//     return 0;
// }

/*  3. Create a forward list insert elements from 1 to 10 and find the sum of elements.  */

//  #include<iostream>
//  #include<forward_list>
//  using namespace std;

//  void listSum(forward_list<int> fr){
//     int sum=0;
//     for(int x:fr)
//         sum+=x;

//     cout<<"Sum of given list is "<<sum<<endl;

//  }
//  int main(){

//  forward_list<int> myList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//  listSum(myList);


//  }

 /*  4. Write a program to reverse forward list elements. */
 
//  #include<iostream>
//  #include<forward_list>
//  using namespace std;

//  void reverseList(forward_list<int>& fr){
//     forward_list<int> revlist ;
//     for(int x:fr)
//         revlist.push_front(x);

//     fr=revlist;

//     for(int x:fr)
//         cout<<x<<" ";
//  }

//  int main(){
    
//     forward_list<int> fr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     reverseList(fr);
    
    
//     return 0;
//  }

 /* 5. Write a program remove all consecutive duplicate elements from the forward list  */

// #include<iostream>
// #include<forward_list>
// using namespace std;

// int main() {
//     forward_list<int> fr = {1, 1, 3, 4, 3, 2, 7, 2, 9, 9};

//     auto it = fr.begin();
//     while (next(it) != fr.end()) { // Ensure next(it) is valid
//         if (*it == *next(it)) {    // Compare current element with the next
//             fr.erase_after(it);    // Erase the next element
//         } else {
//             ++it; 
//         }
//     }

//     // Output the list after removal
//     for (int val : fr) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }

/* 6. Create two forward lists of int type, and merge them. */

// #include<iostream>
// #include<forward_list>
// using namespace std;

//  forward_list<int> reverseList(forward_list<int>& fr){
//     forward_list<int> revlist ;
//     for(int x:fr)
//         revlist.push_front(x);

//     return revlist;

//  }
//  forward_list<int> merge(forward_list<int>& fr1 ,forward_list<int>& fr2 ){
    
//     forward_list<int> rev = reverseList(fr1);
//     for(int x:rev)
//         fr2.push_front(x);

//     return fr2;

//  }

//  int main(){

//     forward_list<int> l1 = {1,2,3,4,5};
//     forward_list<int> l2 = {6,7,8,9,10};
   

//     for(int x:merge(l1,l2)){
//         cout<<x<<" ";
//     }

//  }

 /*  8. Create two forward lists of int type, and swap the elements of both forward lists with
 each other.  */

#include<iostream>
#include<forward_list>
using namespace std;

void swap(forward_list<int>& fr1 ,forward_list<int>& fr2 ){
    auto it1 = fr1.begin();
    auto it2 = fr2.begin();

    while(it1!=fr1.end()){
        int temp = *it1;
        *it1 = *it2;
        *it2=temp;

         it1++;
         it2++;
    }
}

int main(){
    
    forward_list<int> l1 = {1,2,3,4,5};
    forward_list<int> l2 = {6,7,8,9,10};

    swap(l1,l2);

    cout<<"After swaping."<<endl;

    for(int x:l1)
     cout<<x<<" ";

    cout<<endl;

    for(int x:l2)
    cout<<x<<" ";
     
    
    return 0;
}
