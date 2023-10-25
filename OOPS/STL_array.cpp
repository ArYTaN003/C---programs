#include <iostream>
#include <climits>
using namespace std;
template<class T>
class arr1{
    int size;
    T *ar=new T[size];

    public:
    arr1(T a[],int si){
        for(int i=0;i<si;i++){
            this->ar[i]=a[i];
        }
        this->size=si;
    }
    void del(){
        delete []this->ar;
        cout << "\nDeleted\n";
    }
    void out(){
        for(int i=0;i<this->size;i++){
            cout << ar[i] << endl;
        }
    }
    T greatest(){
        T max=this->ar[0];
        for(int i=1;i<this->size;i++){
            if(this->ar[i]>max){
                max=this->ar[i];
            }
        }
        return max;
    }
    T sum(){
        T sum=0;
        for(int i=0;i<this->size;i++){
            sum+=this->ar[i];
        }
        return sum;
    }
    T min(){
        T min=this->ar[0];
        for(int i=1;i<this->size;i++){
            if(this->ar[i]<min){
                min=this->ar[i];
            }
        }
        return min;
    }
    T second_max(){
        T max=this->greatest();
        T sec=this->ar[0];
        for(int i=0;i<this->size;i++){
            if(this->ar[i]>sec && this->ar[i]<max){
                sec=this->ar[i];
            }
        }
        return sec;
    }
    T sec_min(){
        T min=this->min();
        T sec=__DBL_MAX__;
        for(int i=0;i<this->size;i++){
            if(this->ar[i]>min && this->ar[i]<sec){
                sec=this->ar[i];
            }
        }
        return sec;
    }
};
int main(){
    int size;
    cout << "Enter Size of Array : ";
    cin >> size;
    float *a = new float[size];
    for(int i=0;i<size;i++){
        cout << "Enter Element : ";
        cin >> a[i];
    }
    arr1 obj1(a,size);
    obj1.out();
    cout << "Sum  is : " << obj1.sum() << endl;
    cout << "Greatest Element is : "<< obj1.greatest() << endl;
    cout << "Minimum Element is : "<< obj1.min() << endl;
    cout << "Second Greatest Element is : "<< obj1.second_max() << endl;
    cout << "second minimum Element is : "<< obj1.sec_min() << endl;
    obj1.del();
    delete []a;
    return 0;
}