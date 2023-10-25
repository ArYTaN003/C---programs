#include <iostream>
using namespace std;
void DFS(bool **&graph,int start,bool*&visited,int v){
    if(visited[start]){
        return ;
    }
    visited[start]=true;
    for(int i=0;i<v;i++){
        if(graph[start][i] && !visited[i]){
            DFS(graph,i,visited,v);
        }
    }
}
bool isConnected(bool **&graph,int start,int v){
    bool *Visited = new bool[v];
    DFS(graph,start,Visited,v);
    int i;
    for(i=0;i<v;i++){
        if(!Visited[i]){
            break;
        }
    }
    delete []Visited;
    return i==v?true:false;
}
int main() {
    // Write your code here
      int v,e;
    cin >> v >> e;
    bool** graph=new bool*[v];
    for (int i = 0; i < v; i++) {
      graph[i] = new bool[v];
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        graph[a][b]=true;
        graph[b][a]=true; 
    }
    bool res = isConnected(graph,0,v);
    if(res) cout << "true" << endl;
    else cout << "false" <<endl;
    for(int i=0;i<v;i++){
        delete []graph[i];
    }
    delete []graph;
    graph=NULL;
    return 0;
}