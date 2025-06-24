#include<string>
#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    string key;
    T value;
    Node * next;
    Node(string key, T value){
        this->key=key;
        this->value=value;
        next=NULL;
    }
    ~Node(){
        if (next!=NULL){
            delete next;
        }
    }
};


template <typename T>
class HashTable{
    Node<T> **table;
    int cs;
    int ts;
    int hashfn(string key ){
        int idx=0; 
        int power=1;
        for(auto ch:key){
            idx=(idx+ch*power)%ts;
            power= (power*29)%ts;
        }
           return idx;
    }
    void rehash(){
        /*  save the ptr to the oldtable and we will do insertion in the new table */
        Node<T> **oldTable=table;
        int oldts=ts;
        cs=0;
        ts=2*ts+1;
        table = new Node<T>*[ts];
        for(int i=0;i<ts;i++){
            table[i]=NULL;
        }
        /* copy elements from old table to new table  */
        for(int i=0;i<oldts;i++){
            Node <T> *temp=oldTable[i];
            while (temp!=NULL){
                string key= temp->key;
                T value= temp->value ;
                insert(key,value);
                temp=temp->next;
            }
            /* destroy the i th  linked list*/
            if (oldTable[i]!=NULL){
                delete oldTable[i];
            }

        }
        delete [] oldTable;

    }
public:
    HashTable(int default_size=7){
        cs=0;
        ts=default_size;
        table = new Node<T>*[ts];
        for(int i=0;i<ts;i++){
            table[i]=NULL;
        }
    }   
    void insert(string key, T val){
        int idx=hashfn(key);
          
        Node <T>* n=new Node<T>(key,val);
        /* insertion at head of the linked list */
        n->next=table[idx];
        table[idx]=n;
        cs++;
        float load_factor=cs/float(ts);
        if(load_factor>0.7){
            rehash();
        }
    } 
    
    T* search(string key){
        int idx=hashfn(key);
        Node<T> *temp=table[idx];
        while (temp!=NULL){
            if(temp->key==key){
                return &temp->value;
            }
            temp=temp->next;
        }
        return NULL;
    }


    void print(){
        for(int i=0;i<ts;i++){
            cout<<"Bucket "<<i<<"->";
            Node<T> *temp=table[i];
            while(temp!=NULL){
                cout<<temp->key<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

    /* erase ka function badme souchna  */

    T& operator[](string key){
        /* if key is not found then create a new node and return  */
        T* valueFound=search(key);
        if(valueFound==NULL){
            T object;
            insert(key,object);
            valueFound=search(key);
        }

        return *valueFound; 
    }

};
