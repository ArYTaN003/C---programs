#include <bits/stdc++.h> 
#include<vector>
#include<iostream>
using namespace std;
int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
    int secondL=INT_MIN,Largest=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>Largest){
            secondL=Largest;
            Largest=arr[i];
        }else if(arr[i]>secondL && arr[i]<Largest){
            secondL=arr[i];
        }
    }
    return secondL!=INT_MIN && secondL!=Largest?secondL:-1;
}
int main(){
    int t;
    cin >> t;
    int n;vector<int> arr;
    for (size_t i = 0; i < t; i++)
    {
        cin >> n;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            arr.push_back(a);
        }
        cout << "Second Largest Element is : "<< findSecondLargest(n,arr) << endl;
        arr.clear();
    }
    return 0;
}