#include <bits/stdc++.h>
using namespace std;
int max_number_of_heroes(int n,int health,vector<int>& h,vector<int>& v,vector<vector<int>>& dp,int curr){
    if(curr==n){
        return 0;
    }
    if(health<=0){
        return 0;
    }
    if(dp[curr][health]!=-1) return dp[curr][health];
    int ans = 0;
    if(health>=h[curr]){
        ans = 1+max_number_of_heroes(n,health-v[curr],h,v,dp,curr+1);
    }
    return dp[curr][health] = max(ans,max_number_of_heroes(n,health,h,v,dp,curr+1));

}
int main(){
    int t,n,health;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        cin >> health;
        vector<int> h(n),v(n);
        vector<vector<int>> dp(n,vector<int>(health+1,-1));
        for(int j=0;j<n;j++){
            cin >> h[j];
        }
        for(int j=0;j<n;j++){
            cin >> v[j];
        }
        cout << max_number_of_heroes(n,health,h,v,dp,0) << endl;
    }
    return 0;
}