#include <bits/stdc++.h>
using namespace std;
bool can_construct(vector<vector<char>>&grid,string word,int i,int j,int m,int n){
    if(word.length()==0) return true;
    //cout << i << " " << j << " "<<  word << endl;
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='#' || grid[i][j]!=word[0]) return false;
    char prev = grid[i][j];
    grid[i][j] = '#';
    bool ans;
    ans = can_construct(grid,word.substr(1),i+1,j,m,n) || can_construct(grid,word.substr(1),i-1,j,m,n) || can_construct(grid,word.substr(1),i,j-1,m,n) || can_construct(grid,word.substr(1),i,j+1,m,n);
    if(!ans) grid[i][j] = prev;
    return ans;
}
bool construct(vector<vector<char>>&grid,string word){
    int m = grid.size(),n=grid[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==word[0] && can_construct(grid,word,i,j,m,n)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    string word,temp;
    cin >> word;
    int m,n;
    cin >> m >> n;
    vector<vector<char>> grid(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    if(construct(grid,word)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}


