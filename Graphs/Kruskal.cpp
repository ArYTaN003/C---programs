#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int source,destination,weight;
    Edge(int source,int destination,int weight){
        this->source=source;
        this->destination=destination;
        this->weight=weight;
    }
};
bool Comparator(Edge e1,Edge e2){
        return e1.weight<e2.weight;
}
int findParent(int v,vector<int>&parent){
    if(parent[v]==v){
        return v;
    }
    return findParent(parent[v], parent);
}
int main() {
    // Write your code here
    int v,e;
    cin >> v >> e;
    vector<Edge> inp;
    vector<Edge> output;
    vector<int> parent(v);
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    for(int i=0;i<e;i++){
        int a,b,w;
        cin >> a >> b >> w;
        Edge ed(a,b,w);
        inp.push_back(ed);
    }
    sort(inp.begin(),inp.end(),Comparator);
    int count =0;
    int i=0;
    while(count<v-1){
       int a=findParent(inp[i].source,parent);
       int b=findParent(inp[i].destination,parent);
        if(a!=b){
            parent[a]=b;
            output.push_back(inp[i]);
            count++;
        }
        i++;
    }
    for(int i=0;i<v-1;i++){
        if(output[i].source<=output[i].destination){
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl; 
        }else{
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl; 
        }
    }
    return 0;
}
