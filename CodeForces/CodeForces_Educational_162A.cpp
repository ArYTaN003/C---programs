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
void tan(){
    int n;
    cin >> n;
    int l = -1,r=-1,count=0;
    int * arr = new int[n];
    for(int i=0;i<n;i++){
    	cin >> arr[i];
    	if(arr[i]==1){
    		if(l==-1) l = i;
    		r = i;
    	}
    	// cout << arr[i] << " ";
    }
  	while(l<r){
  		if(arr[l]==0) count++;
  		l++;
  	}
    cout << count << endl;
    delete []arr;
}
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
    	tan();
    }
    return 0;
}