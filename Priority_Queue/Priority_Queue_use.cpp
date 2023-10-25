#include"Priority_Queue_class.h"
#include<iostream>
using namespace std;
int main(){
    PriorityQueue p;
    p.insert(12);
    p.insert(6);
    p.insert(5);
    p.insert(100);
    p.insert(1);
    p.insert(9);
    p.insert(0);
    p.insert(14);
    p.insert(2);
    while(!p.isEmpty()){
        cout << p.getMin() << " ";
        p.removeMin();
    }
    cout <<endl;
    return 0;
}