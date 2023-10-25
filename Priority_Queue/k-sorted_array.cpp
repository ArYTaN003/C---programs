#include<iostream>
#include<queue>
using namespace std;
void sort(int *arr,int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        arr[i]=pq.top();
        pq.pop();
        if(i+k<n){
            pq.push(arr[i+k]);
        }
    }
}
int main(){
    int input[]={10,12,15,6,7,9,2};
    int n=7,k=3;    
    sort(input,n,k);
    for(int i=0;i<n;i++){
        cout << input[i] << " "; 
    }
    cout <<endl;
    return 0;
}