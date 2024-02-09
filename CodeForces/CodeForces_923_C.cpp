/*
	 ∞
   MaCTaN 
     ∞
Aryan S Tandon
Keep Going On, Keep Coding 
Never Stop Flowing
*/
#include<bits/stdc++.h>
using namespace std;
bool possible(vector<int>& a,vector<int>& b,int n,int m,int k){
	vector<pair<bool,bool>> num(k+1,{false,false});
	for(int i=0;i<n;i++){
		if(a[i]<=k && num[a[i]].first==false){
			num[a[i]].first = true;
		}
	}
	for(int i=0;i<m;i++){
		if(b[i]<=k && num[b[i]].second==false){
			num[b[i]].second = true;
		}
	}
	for(int i=1;i<=k;i++){
		if(num[i].first==false && num[i].second==false){
			return false;
		}
	}
	return 
}
int main(){
	int t,n,m,k;
	vector<int> a;
	vector<int> b;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n >> m >> k;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		for(int i=0;i<m;i++){
			cin >> b[i];
		}
		if(possible(a,b,n,m,k)){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}