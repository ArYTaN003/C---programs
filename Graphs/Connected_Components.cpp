#include <iostream>
using namespace std;
void DFS(bool **&graph,bool*&visited,int curr,int total,bool *&out){
    visited[curr]=true;
    out[curr]=true;
    for(int i=0;i<total;i++){
        if(graph[curr][i] && !visited[i]){
            DFS(graph,visited,i, total,out);
        }
    }
}
void isConnected(bool **&Graph,int v){
    bool *visited=new bool[v]();
    for(int i=0;i<v;i++){
        if(!visited[i]){
            bool *out=new bool[v]();
            DFS(Graph,visited,i,v,out);
            for(int j=i;j<v;j++){
                if(out[j]) cout << j << " ";
            }
            cout << endl;
            delete []out;
        }
    }
    delete []visited;
}
int main() {
    // Write your code here
    int v,e;
    cin >> v >> e;
    bool **graph=new bool*[v];
    for(int i=0;i<v;i++){
        graph[i]=new bool[v];
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        graph[a][b]=true;
        graph[b][a]=true;
    }
    isConnected(graph,v);
    for(int i=0;i<v;i++){
        delete []graph[i];
    }
    delete []graph;
    graph=NULL;
    return 0; 
}