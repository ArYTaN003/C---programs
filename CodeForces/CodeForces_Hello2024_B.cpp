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
int minpenalty(string arr,int n){
		int s = 0;
		for(int i=0;i<n;i++){
			if(arr[i]=='+') s+=1;
			else s-=1;
		}
    return abs(s);
}
int main(){
	int t,n;
	cin >> t;
	string s;
	int *arr;
	for(int i=0;i<t;i++){
		cin >> n;
		cin >> s;
		cout << minpenalty(s,n) << endl;
	}
	return 0;
}