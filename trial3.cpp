#include<bits/stdc++.h>
using namespace std;
void helper(vector<int>& arr,int curr,int cost,int& ans){
    if(curr==arr.size()-1){
        ans = min(ans,cost);
        return ;
    }
    if(curr+1<arr.size()) helper(arr,curr+1,cost+abs(arr[curr]-arr[curr+1]),ans);
    if(curr+3<arr.size()) helper(arr,curr+3,cost+abs(arr[curr]-arr[curr+3]),ans);
}
int main()
{
    int a = stoi("123");
    cout << a << endl;
    return 0;
}

