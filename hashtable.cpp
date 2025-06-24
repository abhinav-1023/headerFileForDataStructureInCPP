#include<iostream> 
#include"hashtable.h"
using namespace std;

int main(){
    HashTable<int > h;
    h.insert("Mnago",100);
    h.insert("Apple",120);
    h.insert("Rashmeen",200);
    h.insert("abhinav",311);
    h.insert("taniya",685);

    string fruit ="Apple";
    int *price=h.search(fruit);
    if(price!=NULL){
        cout<<"Pricce of fruit is "<<*price <<endl;
    }
    else {cout << "Fruit is not found "<<endl;}


    h.print();

    h["newFruit"]=200;

    cout<<h["newFruit"]<<endl;
    h["newFruit"]+=30;
    cout<<h["newFruit"];
    
return 0;
}