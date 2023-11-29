#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int max_profit(int n,int* mp){
    vector<int> dp(n+1,0);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int max_val = INT_MIN;
        for(int j=0;j<i;j++){
            max_val = max(max_val,mp[j]+dp[i-j-1]);
        }
        dp[i]=max_val;
    }
    return dp[n];
}
int main(){
    unordered_map<int,int> mp={{1,1},{2,5},{3,8},{4,9},{5,10},{6,17},{7,17},{8,20}};
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n;
    cin >> n;
    cout << max_profit(n,arr) << endl;
    return 0;
}