/* Fiers in first out 

operation 
push and pop
 
 
 */
/* Queue using circular array */
class Queue {
    int * arr;
    int cs;
    int ms;
    int front ;
    int rare;
    public:
    Queue(int defaultSize=5){
        ms=defaultSize;
        arr=new int (ms);
        cs=0;
        front=0;
        rare=ms-1;

    }
    bool full(){
        return cs==ms;
    }
    bool empty (){
        return cs==0;
    }

    void push(int d ){
        if (!full()){
            rare=(rare+1)%ms;
            arr[front]=d;
            cs++;
        }
    }
    void pop(){
        if (!empty()){
            front=(front+1)%ms;
            cs--;
        }
    }
    int getFront(){
        return arr[rare];
    }
};