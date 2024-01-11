#include <iostream>
using namespace std;
int island(int ** grid,int i,int j,int m,int n){
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!=1) return 0;
    //cout << i << " " << j << endl;
    grid[i][j]=-1;
    int ans = 1+island(grid,i+1,j,m,n)+island(grid,i-1,j,m,n)+island(grid,i,j-1,m,n)+island(grid,i,j+1,m,n);
    return ans;
}
int max_island(int **grid,int m,int n){
    int ans = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                ans = max(ans,island(grid,i,j,m,n));
            }
        }
    }
    return ans;
}
int main(){
    int m,n;
    cin >> m >> n;
    int ** grid = new int*[m];
    for(int i=0;i<m;i++){
        grid[i] = new int[n];
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    cout << max_island(grid,m,n) << endl;
    for(int i=0;i<m;i++){
        delete []grid[i];
    }
    delete []grid;
    return 0;
}/*
5 5
1 1 1 0 0
0 1 0 0 1
0 0 1 1 0
0 1 1 0 0
0 0 1 0 0
*/