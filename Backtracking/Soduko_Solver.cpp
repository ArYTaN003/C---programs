#include<bits/stdc++.h>
using namespace std;
int board[9][9];
bool canPlace(int num,int row,int col){
    for(int i=0;i<9;i++){
      if (board[i][col] == num || board[row][i]==num){
        return false;
      }
    }
    int s=row-row%3;
    int a=col-col%3;
    for(int j=s;j<s+3;j++){
        for(int p=a;p<a+3;p++){
            if(board[j][p]==num){
                return false;
            }
        }
    }
    return true;

}
bool solveSudoku(int i,int j){
    if(i>=8 && j>=9){
            return true;    
    }
    if(j>=9){
        j=0;
        i++;
    }
    if(board[i][j]==0){
        for(int num=1;num<=9;num++){
            if(canPlace(num,i,j)){
                board[i][j]=num;
                if(solveSudoku(i,j+1)){
                    return true;
                }else{
                    board[i][j]=0;
                }
            }
        }
        return false;
    }
    return solveSudoku(i, j+1);
}
int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> board[i][j];
        }
    }
    if(solveSudoku(0,0)){
      cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    // write your code here
    return 0;
}