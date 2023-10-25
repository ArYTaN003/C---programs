#include <iostream>
using namespace std;
template<class T>
class myclass{
    T var;
    public:
    myclass(T a){
        this->var=a;
    }
    void getvar(){
        cout << var<<endl;
    }
    void inc(){
        this->var++;
    }
};
int main(){
    myclass<int> obj(100);
    obj.getvar();
    myclass<char> obj1('a');
    obj1.getvar();
    myclass<float> obj2(3.14);
    obj2.getvar();
    obj1.inc();
    obj1.getvar();

    return 0;
}