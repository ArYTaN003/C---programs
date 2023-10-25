#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void DFSHelper(bool**& graph,int i,int v,bool*& visited){
    visited[i]=true;
    cout << i << " ";
    for(int j=0;j<v;j++){
        if(graph[i][j] && !visited[j]){
            DFSHelper(graph,j,v,visited);
        }
    }
}
void DFS(bool**& graph,int v){
    bool* visited=new bool[v];
    memset(visited,false,v*sizeof(bool));
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            DFSHelper(graph, i, v, visited);
        }
    }
    delete  []visited;

}
int main(){
    int v,e;
    cin >> v >> e;
    bool **graph=new bool*[v];
    for(int i=0;i<v;i++){
        graph[i]=new bool[v];
        memset(graph[i],false,v*sizeof(bool));
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin >>a >>b;
        graph[a][b]=true;
        graph[b][a]=true;
    }
    DFS(graph,v);
    for(int i=0;i<v;i++){
        delete []graph[i];
    }
    delete []graph;
    return 0;
}