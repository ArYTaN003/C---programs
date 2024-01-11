/*
	 ∞
   MaCTaN 
     ∞
Aryan S Tandon
Keep Going On, Keep Coding 
Never Stop Flowing
*/
#include<bits/stdc++.h>
#include<string>
using namespace std;
bool canPlace(vector<string>& board,int i,int j){
	for(int k=0;k<i;k++){
		if(board[k][j]=='Q') return false;
	}
	for(int p=i-1,q=j-1;p>=0 && q>=0;p--,q--){
		if(board[p][q]=='Q') return false;
	}
	for(int p=i-1,q=j+1;p>=0 && q<board.size();p--,q++){
		if(board[p][q]=='Q') return false;
	}
	return true;
}
void nqueens(vector<string>& board,int r,int n,vector<vector<string>>& out){
	if(r==n){
		// for(int i=0;i<n;i++){
		// 	cout << board[i] << endl;
		// }
		out.push_back(board);
		return ;
	}
	//cout << r << endl;
	for(int i=0;i<n;i++){
		if(canPlace(board,r,i)){
			//cout << r << " " << i << endl;
				board[r][i]='Q';
				nqueens(board,r+1,n,out);
				board[r][i]='.';
			}
	}
}
int nqueens2(vector<string>& board,int r,int n){
	if(r==n){
		// for(int i=0;i<n;i++){
		// 	cout << board[i] << endl;
		// }
		return 1;
	}
	//cout << r << endl;
	int count = 0;
	for(int i=0;i<n;i++){
		if(canPlace(board,r,i)){
			//cout << r << " " << i << endl;
				board[r][i]='Q';
				count+=nqueens2(board,r+1,n);
				board[r][i]='.';
			}
	}
	return count;
}
int main(){
	int n;
	cin >> n;
	string s="";
    for(int i=0;i<n;i++){
        s+='.';
    }
    vector<string> board(n,s);
	vector<vector<string>> out;  
	/*queens(board,0,n,out);
	for(int i=0;i<out.size();i++){
		cout << "Solution " << i << endl; 
		for(int j=0;j<out[i].size();j++){
			cout << " " << out[i][j] << endl;
		}
	}*/
	cout << nqueens2(board,0,n) << endl;
	return 0;
}	