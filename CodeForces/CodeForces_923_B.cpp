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
string trace_string(vector<int>& arr,int n){
	vector<bool> used(n,false);
	string ary = "";
	int last = 0;
	for(int i=0;i<n;i++){
		if(arr[i]>0){
			for(int j = i-1;j>=0;j--){
				if(!used[j] && arr[j]==arr[i]-1){
					used[j] = true;
					ary+=ary[j];
					break;
				}
			}
		}else{
			ary+=(last+'a');
			last++;
		}
	}
	return ary;
}
int main(){
	int t;
	int n;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n;
		vector<int> arr(n);
		for(int j=0;j<n;j++){
			cin >> arr[j];
		}
		std::cout << trace_string(arr,n) << endl;
	}
	return 0;
}