#include<iostream>
#include"Queues.h"
using namespace std;

int main(){
    Queue m(3);
    m.push(12);
    m.push(13);
    m.push(23);
    while(!m.empty()){
        cout<<m.getFront()<<endl;
        m.pop();
    }
}