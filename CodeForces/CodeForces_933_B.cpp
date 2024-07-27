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
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=1;i<n-1;i++){
        if(arr[i-1]>0){
            arr[i] -=2*arr[i-1];
            arr[i+1]-=arr[i-1];
            arr[i-1] = 0;
        }
    }
    bool ary = true;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            ary = false;
            break;
        }
    }
    if(ary) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        tan();
    }
    return 0;
}