#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    vector<int> output;
    int size;
    cin >> size;
    int *arr=new int[size];
    for(int i=0;i<size;i++){
        int ele;
        cin>> ele;
        arr[i]=ele;
    }
    unordered_map<int,bool> present;
    for(int i=0;i<size;i++){
        if(present.count(arr[i])>0){
            continue;
        }
        else{
            pair<int,bool> p(arr[i],true);
            present.insert(p);
            output.push_back(arr[i]);
        }
    }
    for(int i=0;i<output.size();i++){
        cout << output.at(i) << " ";
    }
    cout << endl;
    return 0;

}