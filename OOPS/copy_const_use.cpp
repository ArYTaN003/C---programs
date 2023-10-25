#include <iostream>
#include <cstring>
using namespace std;
#include "copy_const.cpp"
int main(){
    int age=10;
    char name[]="abcd";
    Student s1(age,name);
    Student s2(s1);
    s2.name[0]='z';
    s1.display();
    s2.display();
}