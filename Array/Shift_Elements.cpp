/*
WAP to shift all equal elements in an array in front of the array and the unique elements in the end of array

Testcase 
Original array - 2 1 2 3 4 5 3 5
Modified array - 2 2 3 3 5 5 1 4
*/
#include<vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void shift(vector<int>& arr){
    sort(arr.begin(),arr.end());
    vector<int> unique;
    int last_filled=0;
    for(int i=0;i<arr.size();i++){
        int j=i+1;
        while(j<arr.size() && arr[j]==arr[i]){
            j++;
        }
        if(j==i+1){
            unique.push_back(arr[i]);
        }else{
            if(i==0 && j==arr.size()-1){
                break;
            }
            for(int k=i;k<j;k++){
                arr[last_filled++]=arr[k];
            }
            i=j-1;
        }
    }
    for(int k=0;k<unique.size();k++){
        arr[last_filled++]=unique[k];
    }
}
int main(){
    vector<int> inp={1,2,3,4,5,6,7,8,9,9,1,2,2,3};
    shift(inp);
    for(auto i:inp){
        cout << i << " ";
    }
    cout << endl;
    return 0;

}