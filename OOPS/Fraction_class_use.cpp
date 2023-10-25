#include <iostream>
#include <algorithm>
using namespace std;
#include "Fraction_class.cpp"
int main(){
    Fraction f1(4,2);
    Fraction f2(1,3);
    f1+=f2;
    f1.display();
    Fraction f3=f1++;
    f3.display();
    f1.display();
}