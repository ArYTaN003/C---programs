#include <iostream>
using namespace std;
void spiral(int **arr,int n){
    int rs = 0,re=n-1,cs=0,ce=n-1;
    int num = 0;
    while(num<n*n){
        for(int i=cs;i<=ce && num<n*n;i++){
            cout << arr[rs][i] << " ";
            num++;
        }
        rs++;
        for(int i=rs;i<=re && num<n*n;i++){
            cout << arr[i][ce] << " ";
            num++;
        }
        ce--;
        for(int i=ce;i>=cs && num<n*n;i--){
            cout << arr[re][i] << " ";
            num++;
        }
        re--;
        for(int i=re;i>=rs && num<n*n;i--){
            cout << arr[i][cs] << " ";
            num++;
        }
        cs++;
    }
}
int main(){
    int n;
    cin >> n;
    int **arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    spiral(arr,n);
    for(int i=0;i<n;i++){
        delete []arr[i];
    }
    delete []arr;
    return 0;

}