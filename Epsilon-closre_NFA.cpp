#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void epsilon_closure(int state,unordered_map<int,unordered_map<int,vector<int>>>&mp,vector<vector<int>>& out,vector<bool>& visited){
    if(visited[state]) return ;
    visited[state] = true;
    int t;
    for(int i=0;i<mp[state][-1].size();i++){
        t = mp[state][-1][i];
        if(t==state) out[state].push_back(state);
        else{
            epsilon_closure(mp[state][-1][i],mp,out,visited);
            for(int j=0;j<out[t].size();j++){
                out[state].push_back(out[t][j]);
            }
        } 
    }
}
int main(){
    int n,inp,t;
    cout << "Enter Number of States : ";
    cin >> n;
    cout << "Enter Number of Inputs : ";
    cin >> inp;
    unordered_map<int,unordered_map<int,vector<int>>> mp;
    for(int i=0;i<n;i++){
        cout << "Enter Transition for q" << i << " state" << endl;
        for(int j=0;j<inp;j++){
            cout << "Enter Transition for input " << j << "(If no transition then enter -1): ";
            cin >> t; 
            if(t!=-1){
                mp[i][j].push_back(t);
            }
        }
        mp[i][-1].push_back(i);
        cout << "Enter number of epsilon transiotions for this state : ";
        cin >> t;
        int m;
        for(int j=0;j<t;j++){
            cout << "Enter transition state : ";
            cin >> m;
            mp[i][-1].push_back(m); 
        }
    }
    vector<vector<int>> out(n,vector<int>());
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            epsilon_closure(i,mp,out,visited);
        }
    }
    cout << "Epsilon Cloure : " << endl;
    for(int i=0;i<n;i++){
        cout << "q" << i << ": ";
        for(int j=0;j<out[i].size();j++){
            cout << "q" << out[i][j] << " "; 
        }
        cout << endl;
    }
    return 0;
}