#include <iostream>
using namespace std;
int main(){
int *a,n,ele,prev;
    cin >> n;
    a=new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                a[j]=a[j]+a[j+1];
                a[j+1] = a[j]-a[j+1];
                a[j] = a[j]-a[j+1];
            }
        }

    }
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    delete []a;
    return 0;
}