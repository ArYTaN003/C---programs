#include <iostream>
using namespace std;
#include "class_new.cpp"
int main(){
    Student s1(12);
    s1.name[0]='A';
    //copy constructor
    Student s2(s1);
    s2.rollno=23;
    //copy operator
    s2=s1;
    cout << s2.rollno << endl;
    Student  *s3=new Student(s2);
    delete s3;
}