#include<bits/stdc++.h>
#include<algorithm>
#include<deque>
using namespace std;
int pagefault(int n,int c,int *arr){
    unordered_map<int,bool> mp;
    vector<int> memory;
    for(int i=0;i<n;i++){
        mp[arr[i]]=-1;
    }
    int page_fault=0;
    for(int i=0;i<n;i++){
        if(!mp[arr[i]]){
            if(memory.size()==c){
                mp[memory[0]]=false;
                memory.erase(memory.begin(),memory.begin()+1);
            }
            mp[arr[i]]=true;
            page_fault++;
            memory.push(arr[i]);
        }else{
            memory
        }
    }
    return page_fault;
}
int main(){
    int n;
    cin >> n;
    int c;
    cin >> c;
    int* pages = new int[n];
    for(int i=0;i<n;i++){
        cin >> pages[i];
    }
    cout << pagefault(n,c,pages) << endl;
    delete []pages;
    return 0;
}