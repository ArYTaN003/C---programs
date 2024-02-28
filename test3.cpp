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
void rec(vector<int>&a,vector<int>&b,int i,int j,vector<int>&temp,vector<vector<int>>& out){
    if(i==a.size() || b.size()==j) return ;
    if(temp.size()>0 && temp.back()>a[i]){
        rec(a,b,i+1,j,temp,out);
        return ;
    } 
    // cout << a[i] << " " << b[j] << endl;
    if(a[i]<b[j]){
       temp.push_back(a[i]);
       temp.push_back(b[j]);
       out.push_back(temp);
       rec(a,b,i+1,j+1,temp,out); 
       temp.pop_back();
       temp.pop_back();
    }
    rec(a,b,i,j+1,temp,out);
}
int main(){
    int m=3,n=4;
    vector<int> a={10,15,25};
    vector<int> b={1,5,20,30};
    vector<vector<int>> out;
    vector<int> temp;
    for(int i=0;i<m;i++){
        rec(a,b,i,0,temp,out);
    }                             
    for(int i=0;i<out.size();i++){
        for(int j=0;j<out[i].size();j++){
            cout << out[i][j] << " ";
        }
        cout << endl;
    }                                                                                                          
}                                                                      
