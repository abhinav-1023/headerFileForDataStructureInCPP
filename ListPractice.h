#include<iostream>
using namespace std;

class list;
class Node {
    int data;
    public :
    Node * next;
    Node(int d):data(d),next(NULL){}
    friend class list;
    int getData(){
        return data;
    }
};
class list{
    Node * head;
    Node * tail ;
    public:
    list():head(NULL),tail(NULL){}
    void push_front(int data){
        if(head==NULL){
            Node * n= new Node(data);
            head=tail=n;
        }
        else {
            Node * n =new Node(data);
            n->next=head;
            head = n;
        }
    }
    void push_back(int data){
        if(head==NULL){
            Node * n= new Node(data);
            head=tail=n;

        }
        else{
            Node * n= new Node(data);
            tail->next=n;
            tail=n;
        }
    
    }
    void insert(int data , int pos){
        if(pos==0){
            push_front(data);
            return ;
        }
        else{
            Node * temp = head;
            for (int jump =1;jump<=pos-1;jump++){
                temp = temp->next;
            }
            Node * n= new Node (data);
            n->next=temp->next;
            temp->next=n;

        }
    }

    bool search(int data){
       Node * temp=head;
       while(temp!=NULL){
        if(temp->data==data){
        temp->getData();
        return true;
       }
       else{
        temp=temp->next;
       }

       return false;

    }}
    void pop_front(){
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void pop_back(){
        Node *previous=NULL;
        Node *current=head;
        while(current->next!=NULL){
            previous=current;
            current=current->next;

        }
        previous->next=NULL;
        delete current;
        
    }
    Node *begin() { return head; }

    void destroy(int pos){
        Node * temp=head;
        Node* previous=NULL;
        for(int i=1;i<=pos-1;i++){
            previous=temp;
            temp->next;
        }
      previous->next=temp->next;
      temp->next=NULL;
      delete temp;  
        
    }
};
