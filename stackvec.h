#include<vector>
using namespace std;
/* template <typename T>
class stack{
    vector<T> arr;
    public:
    void push(T data){
        arr.push_back(data);
    }
    void pop(){
        arr.pop_back();

    }
    T Top(){
        int lastIndex= arr.size()-1;

        return arr[lastIndex];
    }
} */

template <typename T>
class Stack{
    vector<T> arr;
    public:
    void push(T d){
        arr.push_back(d);
    }
    void pop(){
        arr.pop_back();

    }
    T top(){
        int lastidx=arr.size()-1;
        return arr[lastidx];

    }
    bool empty(){
        return arr.size()==0;
    }
};