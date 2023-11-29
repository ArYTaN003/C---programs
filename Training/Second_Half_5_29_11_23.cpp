#include <iostream>
#include<vector>
using namespace std;
bool connected(vector<vector<int>>& adj,vector<bool>& visited,int v,int n,int curr){
    if(n==v){
        return true;
    }
    bool temp;
    visited[curr]=true;
    for(auto it:adj[curr]){
        if(!visited[it]){
            temp = connected(adj,visited,v,n+1,it);
            if(temp) return true;
        }
    }
    return false;
}
bool cycle(vector<vector<int>>& adj,vector<int>& visited,int v,int curr){
    visited[curr]++;
    for(auto it:adj[curr]){
        if(visited[it]==0){
            if(cycle(adj,visited,v,it)) return true;
        }else if(visited[curr]==3){
            
        }
    }
    return false;
}
void hamiltonian(vector<vector<int>>& adj,int v,int e){

}
int main(){
    int  v,e;
    cin >> v >> e;
    vector<vector<int>> adj(v,vector<int>());
    int a,b;
    for(int i=0;i<e;i++){
        cin >>a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    hamiltonian(adj,v,e);
    return 0;
}