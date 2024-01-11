#include <iostream>
using namespace std;
int main(){
    int n1;
    char *a;
    cin >> n1;
    a=new char[n1];
    cin >> a;
    cout << a;
    delete []a;
}