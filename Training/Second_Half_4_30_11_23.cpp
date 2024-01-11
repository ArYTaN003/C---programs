#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int transform(string s1, string s2,int i,int j,vector<vector<int>>& memo) {
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(memo[i][j]!=-1) return memo[i][j];
    if(s1[i]==s2[j]){
        memo[i][j] = transform(s1,s2,i-1,j-1,memo);
    }else{
        memo[i][j] = 1+min(transform(s1,s2,i,j-1,memo),min(transform(s1,s2,i-1,j,memo),transform(s1,s2,i-1,j-1,memo)));
    }
    return memo[i][j];
}
int main(){
    string s1,s2;
    cin >> s1;
    cin >> s2;
    int m  = s1.length();
    int n = s2.length();
    vector<vector<int>> memo(m+1,vector<int>(n+1,-1));
    cout << transform(s1,s2,m,n,memo) << endl;
    return 0;
}