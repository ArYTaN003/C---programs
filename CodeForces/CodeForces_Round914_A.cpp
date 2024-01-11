/*
	   ∞
   MaCTaN 
     ∞
Aryan S Tandon
Keep Going On, Keep Coding 
*/
#include<bits/stdc++.h>
using namespace std;
int count_moves(int a,int b,int xk,int yk,int xq,int yq){
	int dx[]={a,a,-a,-a,b,b,-b,-b};
	int dy[]={b,-b,b,-b,a,-a,a,-a};
	set<pair<int,int>> pos;
	int ary = 0;
	for(int i=0;i<8;i++){
		pos.insert({xk+dx[i],yk+dy[i]});
	}
	for(int i=0;i<8;i++){
		if(pos.find({xq+dx[i],yq+dy[i]})!=pos.end()){
			//cout << xq+dx[i] << " " << yq+dy[i] << endl;
			pos.erase({xq+dx[i],yq+dy[i]});
			ary++;
		}
	}
	return ary;
}
int main(){
	int t;
	cin >> t;
	int a,b,xk,yk,xq,yq;
	for(int i=0;i<t;i++){
		cin >> a >> b;
		cin >> xk >> yk;
		cin >> xq >> yq;
		//cout << i << endl;
		cout << count_moves(a,b,xk,yk,xq,yq) << endl;
	}
	//cout << "The number is " << n << endl;
	return 0;
}