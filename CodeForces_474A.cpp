#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    char direction;
    string inp;
    cin >> direction;
    cin >> inp;
    string out = "";
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    unordered_map<char,int> map;
    for(int i=0;i<keyboard.length();i++){
        map[keyboard[i]]=i;
    }
    for(int i=0;i<inp.length();i++){
        if(direction=='R'){
            out+=keyboard[map[inp[i]]-1];
        }else{
            out+=keyboard[map[inp[i]]+1];    
        }   
    }
    cout << out << endl;
    return 0;
}