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
    for(int i=0;i<t;i++){
        cin >> n;
        vector<int> arr(n);
        map<int,int> freq;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            freq[arr[i]]++;
        }
        if(freq.begin()->second==1){
            cout << "YES" << endl;
            continue;
        }
        vector<int> num;
        for(auto it:freq){
            num.push_back(it.first);
        }
        if(num.size()==1){
            cout << "NO" << endl;
            continue;
        }
        bool flag = false;
        for(int i=1;i<num.size();i++){
            if(num[i]%num[0]!=0){
                flag = true;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
        // delete []arr;
    }
    return 0;                                                                                                                                                        
}                                                                      
