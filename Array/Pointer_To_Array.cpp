#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int (*ptr)[5]=&arr;
    //ptr points to the whole array instead of just first element.
    //(*ptr) points to the address of the first element.
    for(int i=0;i<5;i++){
        cout << (*ptr)[i] << endl;
    }
    return 0;
}