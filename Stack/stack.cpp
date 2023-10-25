#include <climits>
template <typename t>  
// for multiple datatypes use - template<typename t,typename v>
class Stack{
    t *data;
    int nextIndex;
    int totalsize;    
    public:
    Stack(){
        totalsize=5;
        data=new t[totalsize];
        nextIndex=0;
    }
    void push(t ele){
        if(nextIndex==totalsize){
            totalsize=totalsize*2;
            t *ndata=new t[totalsize];
            for(int i=0;i<nextIndex;i++){
                ndata[i]=data[i];
            }
            delete []data;
            data=ndata;
        }
        data[nextIndex]=ele;
        nextIndex++;
    }
    t pop(){
        if(isEmpty()){
            return 0;
        }
        nextIndex=nextIndex-1;
        return data[nextIndex];
    }
    t top() const{
        if(isEmpty()){
            return 0;
        }
        return data[nextIndex-1];
    }
    bool isEmpty() const{
        return nextIndex==0;
    }
    int size() const{
        return nextIndex;
    }
};