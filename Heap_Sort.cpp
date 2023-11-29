#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
 
    int largest = i;
 
    int left = 2 * i + 1;
 
    int right = 2 * i + 2;
 
    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
        
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, i, largest);
    }
}
void heap_sort(int * arr,int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}
int main(){
    int arr[]={12,56,3,5,10,23};
    int n = 6;
    heap_sort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }   
    cout << endl;
    return 0;
}