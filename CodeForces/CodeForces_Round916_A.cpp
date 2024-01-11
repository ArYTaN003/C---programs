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
int probelms_solved(string & s){
	vector<int> ary(26,0);
	int count_solved = 0;
	for(int i=0;i<s.length();i++){
		ary[s[i]-'A']++;
		if(ary[s[i]-'A']==(s[i]-'A')+1){
			count_solved++;
		}
	}
	return count_solved;
}
int main(){
	int t;
	cin >> t;
	int n;
	string s;
	for(int i=0;i<t;i++){
		cin >> n;
		cin >> s;
		cout << probelms_solved(s) << endl;
	}
	return 0;
}