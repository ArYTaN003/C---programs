#include <iostream>
using namespace std;
int maximum_subarray_sum(int *arr,int n){
    int sum = 0;
    int maxx=INT_MIN;
    for(int i=0;i<n;i++){
         if(sum<0){
            sum=0;
        }
        sum+=arr[i];
        maxx=max(maxx,sum);
        //cout << sum << " " << maxx << endl;
    }
    return maxx;
}
int main(){
    int n;
    cin >> n;
    int * arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << maximum_subarray_sum(arr,n) << endl;
    delete []arr;
    return 0;
}