#include <iostream>
using namespace std;
void rotate(int **arr,int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    int i=0;
    while(i<n/2){
        swap(arr[i],arr[n-i-1]);
        i++;
    }
}
int main(){
    int n;
    cin >> n;
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    rotate(arr,n);
    cout << "\nRotated : " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<n;i++){
        delete []arr[i];
    }
    delete []arr;
    return 0;
}