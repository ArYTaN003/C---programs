#include <iostream>
#include<vector>
using namespace std;
bool num_digit(int n){
    int l = 0;
    do{
        n=n/10;
        l++;
    }while(n && l<3);
    return l==3;
}
bool stable(int n){
    vector<int> digit(10,0);
    while(n){
        digit[n%10]++;
        n=n/10;
    }
    for(int i=1;i<=9;i++){
        if(digit[i]!=0 && digit[i-1]!=0 && digit[i]!=digit[i-1]){
            return false;
        }
    }
    return true;
}
int password(int *arr,int n){
    int stable_sum=0,unstable_sum=0;
    for(int i=0;i<n;i++){
        if(num_digit(arr[i])){
            if(stable(arr[i])){
                stable_sum+=arr[i];
            }else{
                unstable_sum+=arr[i];
            }
        }
    }
    //cout << stable_sum << endl;
    //cout << unstable_sum << endl;
    return stable_sum-unstable_sum;
}
int main(){
    int n;
    cin >> n;
    int * arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }    
    cout << password(arr,n) << endl;
    delete []arr;
    return 0;
}