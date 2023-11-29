#include <iostream>
#include<vector>
using namespace std;
bool can_partition(int *arr,int n,int curr_sum,int rest_sum,int index,vector<vector<int>>& memo){
    if(index==n){
        return curr_sum==rest_sum;
    }
    if(memo[index][curr_sum]!=-1){
        return memo[index][curr_sum];
    }
    //include
    //cout << index << " " << curr_sum << " " << rest_sum << endl;
    return memo[index][curr_sum]=can_partition(arr,n,curr_sum+arr[index],rest_sum-arr[index],index+1,memo) || can_partition(arr,n,curr_sum,rest_sum,index+1,memo);
}
void partition(int* arr,int n){
    if(n<=1){
        cout << "NO" << endl;
        return ;
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    vector<vector<int>> memo(n,vector<int>(sum+1,-1));
    if(can_partition(arr,n,0,sum,0,memo)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    partition(arr,n);
    delete []arr;
    return 0;
}