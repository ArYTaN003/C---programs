#include<bits/stdc++.h>
using namespace std;

 long int staircase(int n,long int*&arr){
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(int i=4;i<=n;i++){
        arr[i]=(arr[i-1]+arr[i-2]+arr[i-3])%1000000007;
    }
    return arr[n];
}
int main(){
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        long int*arr=new long int[n+4];
        cout <<staircase(n,arr)<< endl;
        delete []arr;
    }
    // write your code here
    return 0;
}