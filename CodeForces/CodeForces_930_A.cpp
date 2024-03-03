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
int main(){
    int t,n;
    cin >> t;
    for(int p=0;p<t;p++){
        cin >> n;
        vector<int> arr(n);
        for(int q=0;q<n;q++){
            cin >> arr[q];
        }
        sort(arr.begin(),arr.end());        
        int i=arr.size()-1,j=1,k=arr.size()-2,l=0;
        int ary = abs(arr[i]-arr[j])+abs(arr[j]-arr[k])+abs(arr[k]-arr[l])+abs(arr[l]-arr[i]);
        cout << ary << endl;
    }
    return 0;
}