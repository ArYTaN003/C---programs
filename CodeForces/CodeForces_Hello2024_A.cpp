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
void helper(int a,int b){
  if((a+b)%2==0) cout << "Bob" << endl;
  else cout << "Alice" << endl;
}
int main(){
  int t,a,b;
  cin >> t;
  for(int i=0;i<t;i++){
    cin >> a >> b;
    helper(a,b);
  }
	return 0;
}