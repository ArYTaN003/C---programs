#include <bits/stdc++.h>
#include <vector>
using namespace std;
int matrix[11][11];
bool canPlace(int n,int row,int i) {
  for(int p=row-1;p>=0;p--){
    if(matrix[p][i]!=0){
      return false;
    }
  }
  for (int p = row - 1, j = i - 1; p >= 0 && j >= 0; p--, j--) {
    if (matrix[p][j] == 1) {
      return false;
    }
  }
  for (int p = row - 1, j = i + 1; p >= 0 && j < n; p--, j++) {
    if (matrix[p][j] != 0) {
      return false;
    }
  }
  return true;
}
void nqueen(int n, int row) {
  if (row == n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << matrix[i][j] << " ";
      }
    }
    cout << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (canPlace( n,row,i)) {
      matrix[row][i] = 1;
      nqueen( n, row + 1);
    }
    matrix[row][i] = 0;
  }
}
int main() {
  int n;
  cin >> n;
  memset(matrix,0,11*11*sizeof(int));
  nqueen(n, 0);
  // write your code here
  return 0;
}