#include <iostream>
#include <climits>
using namespace std;
 void diji(int **graph,int v){
        int count = 0;
        bool *visited = new bool[v]();
        int *weight = new int[v];
        for(int i=0;i<v;i++){
            weight[i]=INT_MAX;
        }
        weight[0]=0;
        while(count!=v-1){
            int curr_weigh=INT_MAX;
            int ind = -1;
            for(int i=0;i<v;i++){
                if(!visited[i] && weight[i]<curr_weigh){
                    curr_weigh = weight[i];
                    ind = i;
                }
            }
            visited[ind] = true;
            for(int i=0;i<v;i++){
                if(!visited[i] &&  graph[ind][i] && (graph[ind][i]+weight[ind])<weight[i]){
                    weight[i]=weight[ind]+graph[ind][i];
                }
            }
            count++;
        }
        for(int i=0;i<v;i++){
            cout << i << " " << weight[i] << endl;
        }
        delete []visited;
        delete []weight;
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
    diji(graph,v);
     for(int i=0;i<v;i++){
        delete []graph[i];
    }
    delete []graph;
    return 0;
}