template <typename t>
class Queue{
    t * data;
    int nextIndex;
    int FirstIndex;
    int size;
    int totalsize;
    public:
    Queue(int s){
        data=new t[s];
        nextIndex=0;
        FirstIndex=-1;
        size=0;
        totalsize=s;
    }
    void enqueue(t ele){
        if(size==totalsize){
            t newdata=new t[size*2];
            int i,k=0;
            for(i=FirstIndex;i<totalsize;i++){
                newdata[k]=data[i];
                k++;
            }
            for(i=0;i<FirstIndex;i++){
                newdata[k]=data[i];
                k++;
            }
            delete []data;
            totalsize=size*2;
            data=newdata;
            FirstIndex=0;
            nextIndex=size;
        }
        data[nextIndex]=ele;
        nextIndex=(nextIndex+1)%totalsize;
        if(FirstIndex==-1){
            FirstIndex=0;
        }
        size++;
    }
    t dequeue(){
        if(isempty()){
            cout << "Queue is empty" << endl;
            return 0;
        }
        t temp=data[FirstIndex];
        FirstIndex=(FirstIndex+1)%totalsize;
        size--;
        if(size==0){
            FirstIndex=-1;
            nextIndex=0;
        }
        return temp;
    }
    t front() const{
        if(isempty()){
            return 0;
        }
        return data[FirstIndex];
    }
    void isempty() const{
        return size==0;
    }
    int getSize(){
        return size;
    }
};