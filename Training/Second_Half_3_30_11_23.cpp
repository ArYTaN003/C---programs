#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool formed(string& s,vector<int>&arr){
    for(int i=0;i<s.length();i++){
        if(arr[s[i]-'a']==0){
            return false;
        }
    }
    return true;
}
void words(vector<string>& dictionary,vector<int>& arr){
    for(int i=0;i<dictionary.size();i++){
        if(formed(dictionary[i],arr)){
            cout << dictionary[i] << " ";
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<string> dictionary(n);
    for(int i=0;i<n;i++){
        cin >> dictionary[i];
    }
    vector<int> arr(26,0);
    cin >> n;
    char a;
    for(int i=0;i<n;i++){
        cin >> a;
        arr[a-'a']++;
    }
    words(dictionary,arr);
    return 0;
}