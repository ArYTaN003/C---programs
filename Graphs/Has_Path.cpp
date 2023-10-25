#include <iostream>
using namespace std;
bool hasPath(bool**& graph,int v1,int v2,bool*& visited,int v){
    if(graph[v1][v2]){
        return true;
    }
    visited[v1]=true;
    for(int i=0;i<v;i++){
        if(graph[v1][i] && !visited[i]){
            visited[i]=true;
            if(hasPath(graph, i, v2,visited,v)){
                 return true;
            }
        }
    }
    return false;
}
int main() {
    // Write your code here
    /*Sample Input
    5 8
    0 1
    0 4
    1 2
    2 0
    2 4
    3 0
    3 2
    4 3
    4 1
    */
    int v,e;
    cin >> v >> e;
    if(v==0){
        return 0;
    }
    bool** graph=new bool*[v];
    for(int i=0;i<v;i++){
        graph[i]=new bool[v];
    }
    bool* visited=new bool[v];
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        graph[a][b]=true;
        graph[b][a]=true; 
    }
    int v1,v2;
    cin >> v1 >> v2;
    cout << ((hasPath(graph, v1, v2,visited,v))?"true":"false")<< endl;
    delete []visited;
    for(int i=0;i<v;i++){
        delete []graph[i];
    }
    delete []graph;
    return 0;
}