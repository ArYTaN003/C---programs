#include <iostream>
#include<climits>
using namespace std;
void prims(int ** graph,int v){
    bool *visited = new bool[v]();
    int *weight = new int[v];
    int *parent = new int[v];
    parent[0]=-1;
    weight[0]=0;
    for(int i=1;i<v;i++){
        weight[i]=INT_MAX;
    }
    int count =0;
    while(count!=v-1){
        int curr_weigh = INT_MAX;
        int ind = -1;
        for(int i=0;i<v;i++){
            if(!visited[i] && weight[i]<curr_weigh){
                ind = i;
                curr_weigh=weight[i];
            }
        }
        visited[ind]=true;
        for(int i=0;i<v;i++){
            if(!visited[i] && graph[ind][i] && graph[ind][i]<weight[i]){
                weight[i]=graph[ind][i];
                parent[i]=ind;
            }
        }
        count++;
    }
    for(int i=1;i<v;i++){
            if(parent[i]<i){
                cout << parent[i] << " " << i << " " << weight[i];
            }else{
                cout << i << " " << parent[i] << " " << weight[i]; 
            } 
            cout << endl;
    }
    delete []visited;
    delete []weight;
    delete []parent;
}
int main() {
    // Write your code here
    int v,e;
    cin >> v >> e;
    int** graph = new int*[v];
    for(int i=0;i<v;i++){
        graph[i]= new int[v];
    }
    for(int i=0;i<e;i++){
        int a,b,w;
        cin >> a >> b >> w;
        graph[a][b]=w;
        graph[b][a]=w;
    }
    prims(graph,v);
    for(int i=0;i<v;i++){
        delete []graph[i];
    }
    delete []graph;
    return 0;
}