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
    int number;
    int ary = 0;
    for(int i=0;i<n;i++){
        cin >> number;
        ary+=abs(number);
    }
    cout << ary << endl;
}
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        tan();
    }
    return 0;
}
