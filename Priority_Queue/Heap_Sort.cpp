#include<iostream>
using namespace std;
void upheapify(int arr[],int ind){
    for(int i=ind;i>0;){
        if(arr[i]<arr[(i-1)/2]){
            int temp=arr[i];
            arr[i]=arr[(i-1)/2];
            arr[(i-1)/2]=temp;
            i=(i-1)/2;
        }
        else{
            break;
        }
    }
}
void downheapify(int arr[],int n){
    for(int i=0;i*2+1<n;){
        int min=i;
        if(arr[min]>arr[i*2+1]){
            min=i*2+1;
        }
        if(i*2+2<n && arr[min]>arr[i*2+2]){
            min=i*2+2;
        }
        if(min==i){
          break;
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
        i=min;
    }
}
void heapSort(int arr[], int n) {
    // Write your code
    for (int i = 1; i < n; i++) {
        upheapify(arr,i);
    }
    int size=n;
    while(size!=1){
        int temp=arr[0];
        arr[0]=arr[size-1];
        arr[size-1]=temp;
        size--;
        downheapify(arr, size);
    }

}
int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}