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
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> left(n);
    vector<int> right(m);
    for(int i=0;i<n;i++){
        cin >> left[i];
    }
    for(int i=0;i<m;i++){
        cin >> right[i];
    }
    int ary = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(left[j]+right[i]<=k) ary++;
        }
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