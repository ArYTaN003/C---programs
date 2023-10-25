/*
        Note:
        To get all the test cases accepted, make recursive calls in following
   order: Top, Down, Left, Right. This means that if the current cell is (x, y),
   then order of calls should be: top cell (x-1, y), down cell (x+1, y), left
   cell (x, y-1) and right cell (x, y+1).
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
void paths(int **&matrix, int n, int row, int col, vector<int> &temp) {
  if (row == n - 1 && col == n - 1) {
    temp[row * n + col] = 1;
    for (int i = 0; i < temp.size(); i++) {
      cout << temp[i] << " ";
    }
    cout << endl;
    temp[row * n + col] = 0;
    return;
  }
  if (row < 0 || row >= n || col < 0 || col >= n || matrix[row][col] == 0 ||
      temp[row * n + col] == 1) {
    return;
  }
  temp[row * n + col] = 1;

  paths(matrix, n, row - 1, col, temp);

  paths(matrix, n, row + 1, col, temp);

  paths(matrix, n, row, col - 1, temp);

  paths(matrix, n, row, col + 1, temp);

  temp[row * n + col] = 0;
}
int main() {
  int n;
  cin >> n;
  int **mat = new int *[n];
  for (int i = 0; i < n; i++) {
    mat[i] = new int[n];
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }
  vector<int> temp(n * n, 0);
  paths(mat, n, 0, 0, temp);

  // Write your code here
  return 0;
}
