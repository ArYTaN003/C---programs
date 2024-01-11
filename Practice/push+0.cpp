#include <iostream>
using namespace std;
void primMST(int**graph,int v){
    int *weight = new int[v];
    int *parent = new int[v];
    int *visited = new int[v];
    for(int i=0;i<v;i++){
        weight[i]=INT_MAX;
        visited[i]=0;
    }
    weight[0]=0;
    parent[0]=-1;
    for(int p=0;p<v-1;p++){
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
            if(!visited[i] && graph[ind][i]!=0 && graph[ind][i]<weight[i]){
                weight[i]=graph[ind][i];
                parent[i]=ind;
            }
        }
    }
    cout << "Edge" << "  " << "Weight" << endl;
    for(int i=0;i<v;i++){
        if(parent[i]!=-1){
            cout << parent[i] << "-" << i << "    " << weight[i] << endl;
        }
    }
    delete []parent;
    delete []weight;
    delete []visited;
}
int main(){ 
    int v;
    cin >> v;
    int** graph = new int*[v];
    for(int i=0;i<v;i++){
        graph[i] = new int[v];
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin >> graph[i][j];
        }
    }
    primMST(graph,v);
    for(int i=0;i<v;i++){
        delete []graph[i];
    }
    delete []graph;
    return 0;
}