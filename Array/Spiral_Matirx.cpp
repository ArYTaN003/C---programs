#include <iostream>
using namespace std;
void spiral(int** matrix,int m,int n){
    int row_start = 0;
    int row_end = m-1;
    int column_start =  0;
    int column_end =  n-1;
    int count = 0;
    int total = m*n;
    while(count!=total){
        for(int i=column_start;count!=total && i<=column_end;i++){
            //if(count%n==0) cout << endl;
            cout << matrix[row_start][i] << " ";
            count++;
        }
        row_start++;
        for(int i=row_start;i<=row_end && count!=total;i++){
            //if(count%n==0) cout << endl;
            cout << matrix[i][column_end] <<  " ";        
            count++;
        }
        column_end--;
        for(int i=column_end;count!=total && i>=column_start;i--){
            // if(count%n==0) cout << endl;
            cout << matrix[row_end][i] << " ";
            count++;
        }
        row_end--;
        for(int i=row_end;count!=total && i>=row_start;i--){
            // if(count%n==0) cout << endl;
            cout << matrix[i][column_start] << " ";
            count++;
        }
        column_start++;
    }
}
int main(){
    int m,n;
    cin >> m >> n;
    int** matrix = new int*[m];
    for(int i=0;i<m;i++){
        matrix[i] = new int[n];
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];
        }
    }
    spiral(matrix,m,n);
    for(int i=0;i<m;i++){
        delete []matrix[i];
    }
    delete []matrix;
}