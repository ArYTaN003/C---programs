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
int minLength(string cell,int n){
  int m = 0;
  int i = 0;
  int j = n-1;
  while(cell[i]=='W') i++;
  while(cell[j]=='W') j--;
  if(i>j) return 0;
  return j-i+1;
}
int main(){
  int t;
  int n;
  string cell;
  cin >> t;
  for(int i=0;i<t;i++){
    cin >> n;
    cin >> cell;
    cout << minLength(cell,n) << endl;
  }
	return 0;
}