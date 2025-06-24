#include<iostream> 
#include"stackvec.h"
using namespace std;

void insertAtBotton(Stack <int > & s, int data){
    if(s.empty()){
        s.push(data);
        return;
    }
    int temp=s.top;
    s.pop();

    insertAtBotton(s,data);

    s.push(temp);/* jab uppar wala compeletly recurrion kar lega tab work karega  */

}
void reverse(stack <int > & s){
    if(s.empty()){
        return;
    }
    int t =s.top();
    s.pop();
    reverse(s);
    insertAtBotton(s,t);


}

int main(){
    Stack<int> s;
    s.push(23);
    s.push(24);
    s.push(23);
    s.push(24);
    while(!s.empty()){
    cout<< s.top() <<endl;
    s.pop();
    }
   
    
}