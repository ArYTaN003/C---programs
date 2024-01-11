/*
	 ∞
   MaCTaN 
     ∞
Aryan S Tandon
Keep Going On, Keep Coding 
*/
#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&arr,vector<int>& ary,int n){
	int score;
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		mp[arr[i]]=i;
	}
	sort(arr.begin(),arr.end());
	int count= 0;
	for(int i=0;i<n;i++){
		score = arr[i];
		count = 0;
		for(int j=0;j<n;j++){
			if(i!=j && score>=arr[j]){
				score+=arr[j];
				count++;
			}
		}
		ary[mp[arr[i]]]=count;
	}
}
int main(){
	int t,n;
	vector<int> arr;
	vector<int> ary;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n;
		arr = vector<int>(n);
		ary = vector<int>(n);
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[j];
		}
		solve(arr,ary,n);
		for(int j=0;j<n;++j){
			cout << ary[j] << " ";
		}
		cout << endl;
	}
	return 0;
}
