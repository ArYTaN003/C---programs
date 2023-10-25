#include <iostream>
using namespace std;
#include "Dynamic_Array_Class.cpp"
int main(){
    Dynamic_Array d;
    d.addElement(1);
    d.addElement(2);
    d.addElement(3);
    d.print();
    d.addElement(0,23);
    d.print();
    Dynamic_Array d1(d);
    d.addElement(4);
    d.print();
    d1.print();
}