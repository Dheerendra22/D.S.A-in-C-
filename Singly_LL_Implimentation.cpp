#include<iostream>
using namespace std;

class node{
    public:

    int value;
    node* next;

    node(int val){
        value=val;
        next=NULL;
    }
};

class LinkList{

    node* head = NULL;
    int count=0;

    public:

    void insertAtBegin(int val){

        node* temp = new node(val);

        // If the list is empty, make the new node the head
        if (head == NULL) {
            head = temp;
            count++;
            return;
        }

        temp->next=head;
        count++;
        head=temp;
    }

    void insertAtMiddle(int val,int aftval){

        node* temp = new node(val);

        // If the list is empty, make the new node the head
        if (head == NULL) {
            head = temp;
            count++;
            return;
        }
        node* t = head;
        while(t!=NULL){
            if(t->value==aftval)
                break;

            t=t->next;
        }
        if(t==NULL)
        { 
            cout<<"Value "<<aftval<<" does not exist in a list."<<endl;
            return;
        }

        temp->next=t->next;
        count++;
        t->next=temp;

    }

    void insertAtEnd(int val){
        
        node* temp = new node(val);

        // If the list is empty, make the new node the head
        if (head == NULL) {
            head = temp;
            count++;
            return;
        }

        node* t = head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=temp;
        count++;
    }

    void deleteNode(int val){
        if(head==NULL){
            cout<<"No element in a linklist."<<endl;
            return;
        }
        if(head->value==val){
            node* temp=head;
            head=head->next;
            delete temp;
            count--;
            return;
        }
        node* t=head;
        while(t!=NULL){
            if(t->next==NULL){
                t=NULL;
                break;
            }
            if(t->next->value==val){
                break;
            }
            t=t->next;
        }
        if(t!=NULL){
            t->next=t->next->next;
            count--;
        }
        else{
            cout<<"Value "<<val<<" does not exist."<<endl;
        }


    }

    void search(int val){
        if(head==NULL){
            cout<<"No element in a linklist."<<endl;
            return;
        }
        node* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            if(temp->value==val){
                break;
            }
            temp=temp->next;
        }
        if(temp!=NULL){
            cout<<"Value found at "<<count<<" position."<<endl;
            return;
        }
        else{
            cout<<"Value "<<val<<" not found.";
            return;
        }
        
    }


    void removeDuplicate(){
        if(head==NULL || head->next==NULL)
            return;

        node* current = head;
        while(current!=NULL && current->next!=NULL){
            if(current->value==current->next->value){
                node* duplicate = current->next;
                current->next=current->next->next;
                delete duplicate;
                count--;

            }else {
                current = current->next;
            }
        }
    }

    void swap(){
        node* t = head;
        while(t!=NULL && t->next!=NULL){
            int temp = t->value;
            t->value = t->next->value;
            t->next->value=temp;
            t=t->next->next;
        }
    }

  void lastToFirst() {
    if (head == NULL || head->next == NULL) {
        // List is empty or contains only one node
        return;
    }

    node* t = head;

    // Find the second last node
    while (t->next->next != NULL) {
        t = t->next;
    }

    // t is now the second last node, and t->next is the last node
    node* last = t->next;

    // Break the link from the second last node to the last node
    t->next = NULL;

    // Move the last node to the front
    last->next = head;
    head = last;
}
    

    void print(){
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->value<<" -> ";
            temp=temp->next;
        }
         cout << "NULL" << endl;  
    }

    void PrintSpecifiedValue(){
        int n;
        cout<<"Enter a Node number you want fom last. ";
        cin>>n;

        if (n > count || n <= 0) {  // Invalid case: n should be between 1 and count
        cout << "Node does not exist." << endl;
        return;
    }

       
    int nodeNum = count - n + 1;

    int temp = 1;  // Start counting from the first node
    node* t = head;
    
    // Traverse the list to find the specified node
    while (t != NULL) {
        if (temp == nodeNum) {
            break;  // Found the node
        }
        temp++;
        t = t->next;
    }

    // Output the node's value
    cout << "The value of the last " << n << "th node is " << t->value << endl;

    }


};

int main() {
    LinkList ll;
    int choice, val, aftval;

    while (true) {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Insert at Begin" << endl;
        cout << "2. Insert at Middle" << endl;
        cout << "3. Insert at End" << endl;
        cout << "4. Delete a Node" << endl;
        cout << "5. Search for a Value" << endl;
        cout << "6. Print List" << endl;
        cout << "7. Remove Duplicates" << endl;
        cout << "8. swap values" << endl;
        cout << "9. Last To First" << endl;
        cout << "10. Print value of specified node." << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                cin >> val;
                ll.insertAtBegin(val);
                break;

            case 2:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter value after which to insert: ";
                cin >> aftval;
                ll.insertAtMiddle(val, aftval);
                break;

            case 3:
                cout << "Enter value to insert at the end: ";
                cin >> val;
                ll.insertAtEnd(val);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> val;
                ll.deleteNode(val);
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> val;
                ll.search(val);
                break;

            case 6:
                ll.print();
                break;

             case 7:
                ll.removeDuplicate();
                break;

            case 8:
                ll.swap();
                break;
            
            case 9:
                ll.lastToFirst();
                break;

            case 10:
                ll.PrintSpecifiedValue();
                break;

            case 11:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}