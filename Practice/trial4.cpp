#include <iostream>
#include<unordered_map>
#include<map>
#include<string>
using namespace std;
int main(){
    map<pair<int,int>,unordered_map<double,int>> mp;
    mp[{1,1}][1.1]=1;
    mp[{1,1}][0]=1;
    auto it = mp[{1,1}];
    cout << it.begin()->second << endl;
}   