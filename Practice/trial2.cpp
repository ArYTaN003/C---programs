#include<bits/stdc++.h>
using namespace std;
int maxSumSubsequence(int *arr,int n,int k){
    if(k==0) return 0;
    if(n-1>=k-1) return max(arr[0]+maxSumSubsequence(arr+1,n-1,k-1),maxSumSubsequence(arr+1,n-1,k));
    return INT_MIN;
}
int main(){
    int n,k;
    cin >> n >> k;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << maxSumSubsequence(arr,n,k) << endl;
    delete []arr;
    return 0;
}