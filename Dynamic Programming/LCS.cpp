/*
This Program return the length of Lowest Common Subsquence of 2 strings. 
*/
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int LCS_DP(string source,string target){
    int m=source.size();
    int n=target.size();
    int **ans=new int*[m+1];
    for(int i=0;i<m+1;i++){
        ans[i]=new int[n+1];
    }
    for(int i=0;i<=n;i++){
        ans[0][i]=0;
    }
    for(int i=0;i<=m;i++){
        ans[i][0]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(source[m-i]==target[n-j]){
                ans[i][j]=1+ans[i-1][j-1];
            }else{
                ans[i][j]=max(ans[i-1][j],max(ans[i][j-1],ans[i-1][j-1]));
            }
        }
    }
    int t=ans[m][n];
    for(int i=0;i<source.size()+1;i++){
        delete []ans[i];
    }
    delete []ans;
    return t;
}
int LCS_memoization(string source, string target,int **ans){
    if(source.size()==0 || target.size()==0){
        return 0;
    }
    int m=source.size();
    int n=target.size();
    if(ans[m][n]!=-1){
        return ans[m][n];
    }
    int out;
    if(source[0]==target[0]){
        out = 1+LCS_memoization(source.substr(1),target.substr(1),ans);
    }else{
        out = max(LCS_memoization(source,target.substr(1),ans),LCS_memoization(source.substr(1),target,ans));
    }
    ans[m][n]=out;
    return ans[m][n];
}
int LCS(string source, string target){
    if(source.size()==0 || target.size()==0){
        return 0;
    }
    if(source[0]==target[0]){
        return 1+LCS(source.substr(1),target.substr(1));
    }
    return max(LCS(source,target.substr(1)),max(LCS(source.substr(1),target),LCS(source.substr(1),target.substr(1))));
}
int main(){
    string source,target;
    cin >> source >> target;
    //cout << target  << source  <<endl;
    //cout << LCS(source,target) << endl;
    cout << LCS_DP(source,target) << endl;
    //cout << "Here" << endl;
    return 0;
}