/*  Given three arrays X[], Y[], and Z[] each consisting of N integers, the task is to find
 the maximum number of triplets (X[i], Y[i], Z[i]) such that (X[i] < Y[i] < Z[i]) for any
 permutation of the three arrays using priority_queue
 Input: X = {9, 6, 14, 1,  8}, Y = {2, 10, 3, 12, 11}, Z = {15, 13, 5, 7, 4}
 Output: 3
 Explanation:
 After rearranging the arrays X[], Y[] and Z[] as {1, 6, 8, 9, 14}, {3, 2, 10, 12, 11}, and
 {4, 7, 15, 13, 5} respectively. The increasing triplets are {1, 3, 4}, {8, 10, 15} and {9,
 12, 13}.
 Therefore, the total count of such triplets is 3*/

// #include<iostream>
// #include<queue>
// using namespace std;

// int findtriplet(priority_queue<int,vector<int>,greater<int>> q1,priority_queue<int,vector<int>,greater<int>> q2,priority_queue<int,vector<int>,greater<int>> q3){

//   int count=0;
 

//   while(!q1.empty()){

//   bool second = false, third = false;
//     while(!q2.empty()){
//         if(q2.top()>q1.top()){
//             second=true;
//             q2.pop();
//             break;
//         }
//         q2.pop();
//     }

//     if(second){
//         while(!q3.empty()){
//             if(q3.top()>q2.top()){
//                 third=true;
//                 q3.pop();
//                 break;
//             }
//             q3.pop();
//         }
//     }
//     if(third){
//         count++;
//     }
//     q1.pop();
//   }

//   return count;

// }
// int main(){
//     priority_queue<int,vector<int>,greater<int>> q1,q2,q3 ;

//     q1.push(9);
//     q1.push(6);
//     q1.push(14);
//     q1.push(1);
//     q1.push(8);

//     q2.push(2);
//     q2.push(10);
//     q2.push(3);
//     q2.push(12);
//     q2.push(11);

//     q3.push(15);
//     q3.push(13);
//     q3.push(5);
//     q3.push(7);
//     q3.push(4);

//     cout<<"Number Of Triplets is "<<findtriplet(q1,q2,q3);

// }

/* 10. Given an array arr[] of size N and a number K, the task is to find the length of the
 smallest subsequence such that the sum of the subsequence is greater than or equal
 to number K do it using priority_queue.
 Example:
 Input: arr[] = {2, 3, 1, 5, 6, 3, 7, 9, 14, 10, 2, 5}, K = 35
 Output: 4
 Smallest subsequence with the sum greater than or equal to the given sum K is {7, 9,
 14, 10}
 Input: arr[] = {1, 2, 2, 2, 3, 4, 5, 4, 7, 6, 5, 12}, K = 70
 Output:-1
 Subsequence with sum greater than equal to the given sum is not possible  */

 #include<iostream>
 #include<queue>
 using namespace std;

 queue<int> findsubsequent(priority_queue<int> q1,int k){
    int sum=0;
    queue<int> result;
    while(!q1.empty()){
        if(sum>k)
          break;
        sum+=q1.top();
        result.push(q1.top());
        q1.pop();

    }
    if(sum>k)
     return result;

    return queue<int>(); // Returning an empty queue 
 }

 void print(queue<int> q1){

    if(q1.empty()){
        cout<<"No Subsecuent found!";
    }

    while (!q1.empty()) {
        cout << q1.front() << " ";  // Print the front element
        q1.pop();                   // Remove the front element from the copy
    }
    cout << endl;


}

 int main(){
     vector<int> values = {2, 3, 1, 5, 6, 3, 7, 9, 14, 10, 2, 5};
    priority_queue<int> q1(values.begin(), values.end());
    int k=50;

   print(findsubsequent(q1,k));

 }
