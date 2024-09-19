#include<iostream>
using namespace std;

class node{
   
   public:

    node* prev;
    int value;
    node* next;

    node(){
        prev=NULL;
        value=0;
        next=NULL;
    }

    node(int val){
        prev=NULL;
        value=val;
        next=NULL;
    }
};

class DoublyList{

    node*head = NULL;


    public:
    void insert(int val){
        node* temp = new node(val);

        if(head==NULL){
            head=temp;
            return;
        }
        node* t = head;
        while(t->next != NULL){
            t=t->next;
        }
        t->next = temp;
        temp->prev = t;
    }

    void insertBegin(int val){
        node* temp = new node(val);
        if(head==NULL){
            head=temp;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;

    }

    void insertMiddle(int val){

        int aftervalue;
        cout<<"Enter a value after which you want to insert an element."<<val<<endl;
        cin>>aftervalue;

        node* t = head;
        while(t!=NULL){
            
            if(t->value==aftervalue){
                if(t->next==NULL){
                    insert(val);
                    return;
            }
                node* temp = new node(val);
                temp->next= t->next;
                temp->prev = t->next->prev;
                t->next->prev = temp;
                t->next=temp;
                return;
            }
            t=t->next;

        }
        cout<<"Enter value "<<aftervalue<<" does not exist in a list."<<endl;



    }

    void printDDL(){
        node* t = head;

        while(t!=NULL){
            cout<<t->value<< " <=> ";
            t=t->next;
        }
        cout<<"NULL"<<endl;
    }



    void deletion(){
        int val;
        cout<<"Which element you want to delete from list ? ";
        cin>>val;
        if(head==NULL){
            cout<<"your List is empty. ";
            return;
        }
        node* t = head;
        while(t!=NULL){
            if(t->value==val){
                if(t->prev==NULL){
                    if(t->next!=NULL){  
                        head=t->next;
                        delete t;
                        printDDL();
                        return;
                    }
                    delete t;      // Only one node in a list
                    head=NULL;
                    printDDL();
                    return;
                }else if(t->next==NULL){    //last node
                    t->prev->next=NULL;
                    delete t;
                    printDDL();
                    return;
                }else {                       //middle node
                    t->prev->next = t->next;
                    delete t;
                    printDDL();
                    return;
                }                
            }
            t=t->next;
        }
        cout<<"Given element not found in a list. "<<endl;
        return;

    }

};

int main(){
    DoublyList dl;
    dl.insert(10);
    dl.insert(20);
    dl.insert(30);
    dl.insert(40);
    dl.insert(50);
    dl.insert(60);
    dl.insertBegin(5);
    dl.insertMiddle(23);
    dl.printDDL();
    dl.deletion();


}