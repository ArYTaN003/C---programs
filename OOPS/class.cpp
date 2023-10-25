#include <iostream>
using namespace std;
class A{
    int total;
};
class B : public A{
    private:
    int marks;
    public:
    B(int m){
        marks=m;
    }
    void display(){
        cout << marks;
    }
};
class C : public B{
    public:
    void display(){
        cout << "This is Class C" << endl;
    }
};
int main(){
    C *ptr,obj;
    ptr=&obj;
    ptr->display();
}