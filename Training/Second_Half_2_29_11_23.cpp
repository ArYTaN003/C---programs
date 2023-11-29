#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int min_chocolate(vector<int>&arr,int n,int m){
    sort(arr.begin(),arr.end());
    int diff = INT_MAX;
    for(int i=0;i+m-1<n;i++){
        diff = min(diff,arr[i+m-1]-arr[i]);
    }
    return diff;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << min_chocolate(arr,n,m) << endl;
    return 0;
}