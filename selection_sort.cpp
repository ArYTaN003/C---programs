#include <iostream>
using namespace std;
int selection_sort(int a[],int n, int start){
    if(start<n-1){
        int min=a[start],mini=start;
        int j=start+1;
        for(;j<n;j++){
            if(min>a[j]){
                min=a[j];
                mini=j;
            }
        }
        int temp=a[start];
        a[start]=min;
        a[mini]=temp;
        start++;
        selection_sort(a,n,start);
    }
    else{
        return -1;
    }
}
int main(){
    int a[100],n,temp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    selection_sort(a,n,0);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}