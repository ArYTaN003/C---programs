#include <iostream>
#include<vector>
using namespace std;
int max_profit(vector<int>& cost,vector<int>& weight,int n,int m,int index,vector<int>& dp){
    if(m==0 || index==n){
        return 0;
    }
    if(dp[m]!=-1) return dp[m];
    int include=INT_MIN,exclude=INT_MIN;
    if(m-weight[index]>=0){
        include=cost[index]+max_profit(cost,weight,n,m-weight[index],index+1,dp);
    }
    exclude = max_profit(cost,weight,n,m,index+1,dp);
    return dp[m]=max(include,exclude);
}
int main(){
    int n,m;
    cin >> n;
    vector<int> cost(n);
    vector<int> weight(n);
    for(int i=0;i<n;i++){
        cin >> cost[i];
    }
    for(int i=0;i<n;i++){
        cin >> weight[i];
    }
    cin >> m;
    vector<int> dp(m+1,-1);
    cout << max_profit(cost,weight,n,m,0,dp) << endl;
    return 0;
}