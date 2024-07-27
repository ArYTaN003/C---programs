#include <bits/stdc++.h>
using namespace std;
string find_winner(vector<int>& a,vector<int>& p,int& n,int& k,int ps,int pb){
    long long bodya_score = 0,sasha_score = 0;
    unordered_map<int,pair<long long,long long>> mp_b;
    int curr = pb-1;
    long long moves = 0;
    long long score = 0;
    while(moves<k){
        if(mp_b.count(curr)) break;
        score+=a[curr];
        moves++;
        mp_b[curr] = {score,moves};
        curr = p[curr]-1;
    }
    curr = ps-1;
    score = 0;
    moves = 0;
    unordered_map<int,pair<long long,long long>> mp_s;
    while(moves<k){
        if(mp_s.count(curr)) break;
        score+=a[curr];
        moves++;
        mp_s[curr] = {score,moves};
        curr = p[curr]-1;
    }
    for(auto it:mp_b){
        bodya_score = max(bodya_score,it.second.first+(k-it.second.second)*a[it.first]);
    }
    for(auto it:mp_s){
        sasha_score = max(sasha_score,it.second.first+(k-it.second.second)*a[it.first]);
    }
    if(bodya_score>sasha_score){
        return "Bodya";
    }else if(bodya_score<sasha_score){
        return "Sasha";
    }else{
        return "Draw";
    }
}
int main(){
    int t;
    cin >> t;
    int n,k,pb,ps;
    vector<int> a;
    vector<int> p;
    for(int i=0;i<t;i++){
        cin >> n >> k >> pb >> ps;
        a.resize(n);
        p.resize(n);
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        cout << find_winner(a,p,n,k,ps,pb) << endl;
    }
    return 0;
}