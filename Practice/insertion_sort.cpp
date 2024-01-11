#include <iostream>
using namespace std;
int main(){
    int *a,n,ele,prev;
    cin >> n;
    a=new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int pos=1;pos<n;pos++){
        ele=a[pos];
        prev=pos-1;
        while(prev>-1 && ele<a[prev]){
            a[prev+1]=a[prev];
            prev--;
        }
        a[prev+1]=ele;

    }
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    delete []a;
}