#include <iostream>
using namespace std;
void shellsort(int *arr,int n){
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i += 1) 
        { 
            int temp = arr[i]; 
            int j=i;             
            while(j >= gap && arr[j - gap] > temp){
                arr[j] = arr[j - gap];
                j-=gap;    
            }
            arr[j] = temp; 
        } 
    } 
}
int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    shellsort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    delete []arr;
    return 0;
}