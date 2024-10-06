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

class CDLL{

    node* head=NULL;
    public:
    void insert(int val){
        node* temp = new node(val);

        if(head==NULL){
            head = temp;
            head->next = head;  // Circular link to self
            head->prev = head;
            return;
        }
        node* t = head;
        while(t->next != head){
            t=t->next;
        }
        t->next = temp;
        temp->prev = t;
        temp->next=head;
        head->prev=temp;
    }

    void insertBegin(int val){
        node* temp = new node(val);
        if(head==NULL){
            head = temp;
            head->next = head;  // Circular link to self
            head->prev = head;
            return;
        }else {
        temp->next = head;
        temp->prev=head->prev;
        head->prev->next=temp;
        head->prev = temp;
        head = temp;
        }
           
        

    }

    void printCDL(){
       

       if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        node* t = head;
        do {
            cout << t->value << " <=> ";
            t = t->next;
        } while (t != head);  // Stop when we return to the head
        cout << "HEAD" << endl;
    }


    void printReverse(){
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        node* t = head;
        while(t->next!=head){
            t=t->next;
        }
        node* rev = t;
        do {
            cout << t->value << " <=> ";
            t = t->prev;
        } while (t!=rev);  // Stop when we return to the head
    
        
    }

    void insertMiddle(int val){

        if(head==NULL){
            insert(val);
            return;
        }

        int aftervalue;
        cout<<"Enter a value after which you want to insert an element."<<val<<endl;
        cin>>aftervalue;


        node* t = head;
        while(t->next!=head){
            
            if(t->value==aftervalue){
                if(t->next==head){
                    insert(val);
                    return;
            }
                node* temp = new node(val);
                temp->next= t->next;
                temp->prev = t;
                t->next->prev = temp;
                t->next=temp;
                return;
            }
            t=t->next;

        }
        cout<<"Enter value "<<aftervalue<<" does not exist in a list."<<endl;



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
    
         do{
            
            if(t->value==val){
                if(t==head){

                    if(head->next==head){
                         head=NULL;
                         delete t;
                         return;
                    }   
                    
                    head->next->prev=head->prev;
                    head->prev->next=head->next;
                    head=head->next;
                    delete t;
                    return;
                }else if(t->next==head){
                    t->prev->next=head;
                    head->prev=t->prev;
                    delete t;
                    return;
                }
                else{
                    t->prev->next=t->next;
                    t->next->prev=t->prev;
                    delete t;
                    return;
                }

            }
            t=t->next;

        }while(t!=head);



        cout<<"Given element not found in a list. "<<endl;
        return;

    }




};

int main(){
    CDLL cl;
    cl.insert(10);
    cl.insert(20);
    cl.insert(30);
    cl.insert(40);
    // cl.insertBegin(50);
    // cl.insertBegin(70);
    // cl.insertBegin(80);
    // cl.insertBegin(90);
    cl.printCDL();
    
    // cl.insertMiddle(25);
    cl.printReverse();
    cl.deletion();
    // cl.printReverse();
    cl.printCDL();

}
