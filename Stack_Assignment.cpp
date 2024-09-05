
/* Q 1. Given a stack with push(), pop(), empty() operations, delete the middle of the stack
 without using any additional data structure.
 Middle: ceil((size_of_stack+1)/2) (1-based index)
 Example 1:
 Input:
 Stack = {1, 2, 3, 4, 5}
 Output:
 ModifiedStack = {1, 2, 4, 5}
 Explanation:
 As the number of elements is 5, hence the middle element will be the 3rd element
 which is deleted
 Example 2:
 Input:
 Stack = {1 2 3 4}
 Output:
 ModifiedStack = {1 3 4}
 Explanation:
 As the number of elements is 4, hence the middle element will be the 2nd element
 which is deleted*/

#include<iostream>
#include<stack>
using namespace std;


void removeMiddle(stack<int> &st ,int midindex){

    if(midindex==0){
        return;
    }
    
    
    if(st.size()==midindex){
        st.pop();
        return;
    }

    int x = st.top();
    st.pop();
    removeMiddle(st,midindex);

    st.push(x);

}

int main(){

    stack<int> st;
    int n, num,middle;

    cout << "How many numbers do you want to enter in the stack? ";
    cin >> n;

    cout << "Enter " << n << " integer numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> num;
        st.push(num);
    }

    middle = (st.size()+1)/2 ;

    removeMiddle(st,middle);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }


}


/* Q.2. Given an expression string x. Examine whether the pairs and the orders of
 “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
 For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for
 exp = “[(])”  */


 #include<iostream>
 #include<stack>
 using namespace std ;



 bool checkValidation(string str){

    stack<char> st ;
    
    for(int i=0; i<str.size(); i++){

         if(st.empty())
                st.push(str[i]);

        if(str[i]=='{'|| str[i]=='(' || str[i]=='[' ){
            st.push(str[i]);
            
         }

         if(str[i]=='}'|| str[i]==')' || str[i]==']' ){

                if(str[i]==')'){
                    if(st.top()=='(')
                    st.pop();
                else{
                    cout<<"Invalid String!";
                    return false;
                }     
            }

            if(str[i]=='}'){
                    if(st.top()=='{')
                    st.pop();
                else{
                    cout<<"Invalid String!";
                    return false;
                }     
            }
            if(str[i]==']'){
                    if(st.top()=='[')
                    st.pop();
                else{
                    cout<<"Invalid String!";
                    return false;
                }     
            }

         }

          
           
    }

    if(!st.empty())
        return true ;


 }

 int main(){

    string str ;
    cout<<"Enter an string containing brackets. "<<endl;
    cin>>str;
    

    if(checkValidation(str))
       cout<<"string contain a valid sequence of brackets ! ";

return 0;
      

 }

 /* 
 Q 4. Given a stack, the task is to sort it such that the top of the stack has the greatest
 element.
 Example 1:
 Input:
 Stack: 3 2 1
 Output: 3 2 1
 
 */

 #include<iostream>
 #include<stack>
 using namespace std;

 void pushValue(stack<int> &st ,int val){

    if(st.empty()){
        st.push(val);
        return;
    }
    else if(st.top()>val){
            int temp = st.top();
            st.pop();
            st.push(val);
            st.push(temp);
            return;
    }else{
        st.push(val);
    }



    }



 int main(){

    stack<int> st ;
    
    int n,value;
     cout<<"How many integer number you want to enter ? ";
     cin>>n;
     cout<<"Enter vales "<<endl;

     for(int i=0; i<n; i++){
        cin>>value;
        pushValue(st,value);
     }
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
    }

 }

 /*Q. 9. Given two strings s and t, return true if they are equal when both are typed into empty
 text editors. '#' means a backspace character. Note that after backspacing an empty
 text, the text will continue empty.
 Example 1:
Input: s = "ab#c", t = "ad#c"
 Output: true
 Explanation: Both s and t become "ac".  */

 #include<iostream>
 #include<stack>
 #include <algorithm>
 #include <string>
 using namespace std;

 string toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

 bool checkString(string s1, string s2){
  
    stack<char> st1,st2;
     
    for(int i=0; i<s1.size(); i++){

      if(st1.empty() && s1[i]=='#')
        continue;
      else if(st1.empty())
        st1.push(s1[i]);
      else if(s1[i]!='#')
        st1.push(s1[i]);
      else if(s1[i]=='#')
        st1.pop();

    }

    for(int i=0; i<s2.size(); i++){

      if(st2.empty() && s2[i]=='#')
          continue;
      else if(st2.empty())
        st2.push(s2[i]);
      else if(s2[i]!='#')
        st2.push(s2[i]);
      else if(s2[i]=='#')
        st2.pop();

    }
    
    if(st1.size()==st2.size()){
      
      while(!st1.empty()){
         if(st1.top()==st2.top()){
            st1.pop();
            st2.pop();
         }else 
         return false;
         
      }
      return true;
    } else 
         return false;

 }
 
 int main(){

   string s1,s2;
   cout<<"Enter first string containin # symbol. ";
   cin>>s1;
   cout<<"Enter second string containin # symbol. ";
   cin>>s2;


   if(checkString(toLowerCase(s1),toLowerCase(s2)))
      cout<<"Both string are same.";
   else 
      cout<<"String are not same.";
   

 }


/* Q 6. Given a string S, the task is to find the bracket numbers.
 Example 1:
 Input:  S = "(aa(bdc))p(dee)â€‹"
 Output: 1 2 2 1 3 3
 Explanation: The highlighted brackets in the given string (aa(bdc))p(dee) has been
 assigned the numbers as: 1 2 2 1 3 3.
 Example 2:
 Input:  S = "(((()("
 Output: 1 2 3 4 4 5
 Explanation: The highlighted brackets in
 the given string (((()( has been assigned
 the numbers as: 1 2 3 4 4 5    */

 #include<iostream>
 #include<stack>
 using namespace std;

 void bracketNumber(string s1){

    stack<int> st1;
    int count=0;
    for(int i=0; i<s1.size(); i++){

        if(s1[i]=='('){
            count++;
            st1.push(count);
            cout<<count;
        }else if(s1[i]==')'){
          cout<<st1.top();
          st1.pop();

        }      
      
    }


 }

 int main(){

  string s1;
  cout<<"Enter a string containing open brackets. ";
  cin>>s1;

  bracketNumber(s1);

  return 0;

 }

 /* Q. 7. Design a data-structure SpecialStack that supports all the stack operations like
 push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should
 return minimum element from the SpecialStack. Your task is to complete all the
 functions, using stack data-Structure.
 Example 1:
 Input:
 Stack: 18 19 29 15 16
 Output: 15
 Explanation:
 The minimum element of the stack is 15.   */


#include<iostream>
#include<stack>
using namespace std;

class SpecialStack{
  
  private:
    stack<int> mainstack , minstack;

  public:
     void Push(int value){

      if(mainstack.empty()){

        mainstack.push(value);
        minstack.push(value);

      }else if(value < minstack.top()){

           mainstack.push(value);
           minstack.push(value);

      }else {
        mainstack.push(value);
        minstack.push(minstack.top());
      }
      
     }

     void Pop(){
        mainstack.pop();
        minstack.pop();
     }

     bool IsEmpty(){
        return mainstack.empty();
     }

     int getMin(){
      return minstack.top();
     }

};

int main(){

  SpecialStack sp1;

  sp1.Push(21);
  sp1.Push(34);
  sp1.Push(19);
  sp1.Push(12);
  sp1.Push(44);
  sp1.Push(5);

  cout<<sp1.getMin()<<endl;

  sp1.Pop();
  sp1.Pop();

  cout<<sp1.getMin()<<endl;

}


/* Q.8. You are given the string S . Compress the string when lower and upper cases are the
 same. In compressed string characters should be in lowercase.
 Example 1:
 Input: S = "aaABBb"
 Output: "3a3b"
 Explanation: As 'a' appears 3 times consecutively and 'b' also 3 times, and 'b' and 'B'
 are considered the same.
 Example 2:
 Input: S = "aaacca"
 Output: "3a2c1a"
 Explanation: As 'a' appears 3 times consecutively and 'c' also 2 times, and then 'a' 1
 time  */

 #include<iostream>
 #include<stack>
 #include<algorithm>
 #include<string>
 using namespace std;

 string toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

 string Compress(string str){
    stack<char> st1;
    string result="";
    int count=0;

    for(int i=0; i<str.size(); i++){
      if(st1.empty()){
        st1.push(str[i]);
        count++;
      }else if(str[i]==st1.top()){
        st1.push(str[i]);
        count++;
      }else if(str[i]!=st1.top()){
        result+=to_string(count);
        result+=st1.top();
        st1.push(str[i]);
        count=1;
        
        if(i==str.size()-1)
        {
          result+=to_string(count);
          result+=st1.top();
          
        }
        
      }
    }

    return result;

 }

 int main(){

  string s1;
  cout<<"enter a String you want to Compress. ";
  cin>>s1;

  cout<<Compress(toLowerCase(s1));
  
  return 0;

 }

/* Q. 10. Your task is to implement  2 stacks in one array efficiently.
 Example 1:
 Input:
 enqueue(2)
 enqueue(3)
 dequeue()
 enqueue(4)
 dequeue()
 Output: 2 3
 Explanation:
 enqueue(2) the queue will be {2}
 enqueue(3) the queue will be {3 2}
 dequeue() the poped element will be 2
 the stack will be {3}
 enqueue(4) the stack will be {4 3}
 dequeue() the poped element will be 3.
 Example 2:
 Input:
 enqueue(2)
 dequeue()
 dequeue()
 Output: 2 -1   */

 #include<iostream>
 #include<stack>
 using namespace std;

 class Queue{

  stack<int> st1 ;

  public:

  void enqueue(int value){
    st1.push(value);

  }

  void deque(){
    if(st1.size()==1){
      st1.pop();
      return;
    }
    int temp = st1.top();
    st1.pop();
    deque();
    st1.push(temp);
  }

  
  void print(){
    if(st1.size()==1){
      cout<<st1.top()<<" ";
      st1.pop();
      return;
    }
    int temp = st1.top();
    st1.pop();
    print();
    cout<<temp<<" ";
  
    
  }

 };

 int main(){

  Queue q1;
  q1.enqueue(10);
  q1.enqueue(20);
  q1.enqueue(30);
  q1.enqueue(40);
  q1.enqueue(50);
  q1.deque();
  q1.deque();
  q1.deque();
  q1.print();

  
 }

 /* Q. 4. Reverse the Words of a String using Stack.
 Example:
 Input: str = “I Love To Code”
 Output: Code To Love I   */

#include<iostream>
#include<stack>
#include<string>
using namespace std;

void reverse(stack<string> &st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    stack<string> st1;
    string s1, temp = "";
    cout << "Enter a string: ";
    getline(cin, s1);  // Use getline to capture the entire input line

    // Loop to process each character in the string
    for (int i = 0; i <= s1.size(); i++) {
        // If space is found or end of string is reached, push the word onto the stack
        if (s1[i] == ' ' || i == s1.size()) {
            st1.push(temp);
            temp = "";
        } else {
            temp += s1[i];
        }
    }

    // Reverse the stack
    reverse(st1);

    return 0;
}

/* Q.7. Create a stack of int type and sort it */

// #include<iostream>
// #include<stack>
// using namespace std;

// void arrange(stack<int> &st, int value) {
//     // If stack is empty or top of stack is smaller, push the value
//     if (st.empty() || st.top() < value) {
//         st.push(value);
//         return;
//     }

//     // If top of stack is greater, pop the top and recursively call arrange
//     int temp = st.top();
//     st.pop();
//     arrange(st, value);

//     // Push the popped element back onto the stack
//     st.push(temp);
// }

// int main(){

//     int size;
//     stack<int> st;

//     cout<<"How many integer numbers you want to enter? ";
//     cin>>size;
//     int arr[size];
//     cout<<"Enter values.";
//     for(int i=0; i<size; i++){
//         cin>>arr[i];
//     }

//     for(int i=0; i<size; i++)
//        arrange(st,arr[i]);


//        while(!st.empty()){
//         cout<<st.top()<<" ";
//         st.pop();
//        }
    
//     return 0;
// }

/* Q.9. Create back button functionality using stack.*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

class backButton{

    string current_url ="Home";
    stack<string> backward;
    stack<string> forward;

    public:

    void New_Page_visit(string url){

        backward.push(current_url);
        current_url = url;
        cout<<"you are now at "<<current_url<<endl;


    }

    void Back_Button(){
        if(backward.empty()){
            cout<<"no site Available!"<<endl;
            return;
        }
        forward.push(current_url);
        current_url=backward.top();
        cout<<"you are now at "<<current_url<<endl;
        backward.pop();
    }
    void Forward_Button(){
        if(forward.empty()){
            cout<<"No site available"<<endl;
            return;
        }
        current_url = forward.top();
        cout<<"you are now at "<<current_url<<endl;
        forward.pop(); 
    }


};

int main(){

    backButton btn;
    
    btn.Back_Button();
    btn.New_Page_visit("www.google.com");
    btn.New_Page_visit("www.facebook.com");
    btn.New_Page_visit("www.youtube.com");
    btn.Forward_Button();
    btn.Back_Button();
    btn.Back_Button();
    btn.Back_Button();
    btn.Back_Button();



}

/* Q.10.Given an array, print the Next Greater Element (NGE) for every element using stack.
 Example:
 Input: arr[] = [ 4 , 5 , 2 , 25 ]
 Output:  4      –>   5
 5      –>   25
 2      –>   25
 25     –>   -1  */

 