#include<iostream>
#include"heaps.h"
using namespace std;

int main(){
    int arr[]={10,15,20,13,6,90};
    heap h;
    for(int x: arr){
        
        h.push(x);
    }
    while(!h.empty()){
        cout<<h.top()<<endl;
        h.pop();
    }

return 0;
}