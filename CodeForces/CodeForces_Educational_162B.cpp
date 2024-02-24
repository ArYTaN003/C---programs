/*
	 ∞
   MaCTaN 
     ∞
Aryan S Tandon
Keep Going On, Keep Coding 
Never Stop Flowing
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void tan(){
     ll n,k;
    cin >> n >> k;
    ll pos;
    vector<ll> health(n);
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
    	cin >> health[i];
    }
    for(int i=0;i<n;i++){
    	cin >> pos;
    	mp[abs(pos)]+=health[i];
    }
    ll b_left = k;
   	for(int i=1;i<=n;i++){
   		if(b_left<mp[i]){
   			cout << "no" << endl;
   			return ;
   		}
   		b_left-=mp[i];
   		b_left+=k;
   	}
   	cout << "yes" << endl;
   	
}
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
    	tan();
    }
    return 0;
}