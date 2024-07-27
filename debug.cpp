#include <bits/stdc++.h>
using namespace std;
/*
Initial Thoughts , we basically need to traverse the source string and find the min cost to convert source[i] to target[i] , if they are not equal , if we cannot do this , it means we cannot convert source into target
*/

long long getMinCostToChange(char source,char& target,vector<vector<int>>& change_cost){
    if(source==target) return 0;
    long long min_cost_to_Change = INT_MAX,current_cost;
    for(int i=0;i<26;i++){
        if(change_cost[source-'a'][i]!=INT_MAX){
            current_cost = getMinCostToChange(i+'a',target,change_cost);
            if(current_cost!=INT_MAX){
                min_cost_to_Change = min(change_cost[source-'a'][i]+current_cost,min_cost_to_Change);
            }
        }
    }
    return min_cost_to_Change;
}
long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    long long min_cost = 0;
    vector<vector<int>> change_cost(26,vector<int>(26,INT_MAX));
    int n = original.size();
    for(int i=0;i<n;i++){
        change_cost[original[i]-'a'][changed[i]-'a'] = min(change_cost[original[i]-'a'][changed[i]-'a'],cost[i]);
    }
    // for(int i=0;i<26;i++){
    //     cout << (char)(i+'a') << ":";
    //     for(int j=0;j<26;j++){
    //         if(change_cost[i][j]==INT_MAX) continue;
    //         cout << "{" << (char)('a'+j) << "," << change_cost[i][j] << "} ";
    //     }
    //     cout << endl;
    // }
    int string_length = source.length();
    for(int i=0;i<string_length;i++){
        if(source[i]!=target[i]){
            long long cost_to_change = getMinCostToChange(source[i],target[i],change_cost);
            cout << i << " " << cost_to_change << endl;
            if(cost_to_change!=INT_MAX){
                min_cost+=cost_to_change;
            }else{
                return -1;
            }
        }
    }
    return min_cost;
}
int main(){
    string source = "aaaabadaaa";
    string target = "dbdadddbad";
    vector<char> original = {'c', 'a', 'c', 'a', 'a', 'b', 'b', 'b', 'd', 'd', 'c'};
    vector<char> changed = {'a','c','b','d','b','c','a','d','c','b','d'};
    vector<int> cost = {7,8,11,9,7,6,4,6,9,5,9};
    cout << minimumCost(source,target,original,changed,cost) << endl; 
}
