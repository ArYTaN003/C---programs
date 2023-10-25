#include <iostream>
#include<cmath>
using namespace std;
int balancedBTs_bruteForce(int n) {
    // Write your code here
    if(n<=2){
        return pow(2,n)-1; 
    }
    long int l=balancedBTs_bruteForce(n-1);
    long int r=balancedBTs_bruteForce(n-2);
    int mod=1e9+7;
    long long int temp1=((long long)(l)*l)%mod;
    long long int temp2=((long long)(l)*r*2)%mod;
    long long int x=(temp1+temp2)%mod;
    return x;
 }
int balancedBTs(int n) {
    // Write your code here
    int mod = 1e9 + 7;
    long int* arr=new long int[n+1];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=(arr[i-1]*arr[i-2]*2+arr[i-1]*arr[i-1])%mod;
    }
    int res=arr[n];
    delete []arr;
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}