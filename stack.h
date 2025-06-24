 #include<iostream>
 using namespace std;
/* template <typename T >
class stack{}
template <typename T >
class Node {
    public:
    T data;
    Node*<T> next;
    Node ( T data):data(data),next(NULL){}

};
template <typename T>
class stack {
    Node * <T> head;
    public :
    stack():head(NULL){}
    void push(){
        Node*<T> n=new Node<T>(data);
        n->next=head;
        head= n;
    }
    void pop(){
        if (head!=NULL){
        Node * <T> temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;}
    }
    T Top(){
        return head->data;
    }
    bool empty (){
        return head==NULL;
    }
}
*/
 template<typename T>
class stack;
template <typename T>
class Node {
    public:
    T data;
    Node<T> *next;
    Node (T d){
        data=d;

    }   
};
template<typename T>
class stack{
    Node<T> * head;
    public:
    stack(){
        head==NULL;
    }
    void push(T data){
         Node<T> * n= new Node<T>(data);
         n->next=head;
         head=n;
    }
    bool empty(){
        bool a= head==NULL;
        return a;
    }
    void pop(){
        if(head!=NULL){
        Node<T> * temp=head;
        head=head->next;
        delete temp;
        }
    }
    T top(){
        return head->data;
    }
};
