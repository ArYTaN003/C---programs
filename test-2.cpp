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
	vector<int> cnt(k+1,0);
	for(int i=0;i<n;i++){
		if(a[i]<=k) cnt[a[i]]|=1;
	}
	for(int i=0;i<m;i++){
		if(b[i]<=k) cnt[b[i]]|=2;
	}
	vector<int> c(4,0);
	for(int i=1;i<=k;i++){
		c[cnt[i]]++;
	}
	if(c[1]*2>k || c[2]*2>k || c[1]+c[2]+c[3]<k) return false;
	return true;
}
int main(){
	int t,n,m,k;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n >> m >> k;
		vector<int> a(n);
		vector<int> b(m);
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