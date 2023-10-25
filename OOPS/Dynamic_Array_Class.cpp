class Dynamic_Array{
    int *data;
    int next_Index=0;
    int size;
    public:
    Dynamic_Array(){
        size=5;
        data=new int[size];
    }
    Dynamic_Array(Dynamic_Array const &d){
        this->data=new int[d.size];
        for(int i=0;i<d.next_Index;i++){
            this->data[i]=d.data[i];
        }
        this->next_Index=d.next_Index;
        this->size=d.size;
    }
    void addElement(int element){
        if(next_Index==size){
            int *newdata=new int[2*size];
            int i;
            for(i=0;i<size;i++){
                newdata[i]=data[i];
            }
            delete []data;
            data=newdata;
            size=2*size;
        }
        data[next_Index]=element;
        next_Index++;
    }
    void addElement(int i,int element){
        if(i<next_Index){
            data[i]=element;
        }
        else if(i==next_Index){
            addElement(element);
        }
        else{
            return ;
        }
    }
    void print() const{
        for(int i=0;i<next_Index;i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};