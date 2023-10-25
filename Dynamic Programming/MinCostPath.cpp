#include <climits>
#include <iostream>
using namespace std;
int minCost_memoization(int **input, int i, int j, int m, int n, int **ans)
{
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }
    if (ans[i][j] != -1)
    {
        return ans[i][j];
    }
    int x = minCost_memoization(input, i + 1, j, m, n, ans);
    int y = minCost_memoization(input, i, j + 1, m, n, ans);
    int z = minCost_memoization(input, i + 1, j + 1, m, n, ans);
    ans[i][j] = input[i][j] + min(x, min(y, z));
    return ans[i][j];
}
int minCostPath_DP(int **input, int m, int n)
{
    // Write your code here
    int **ans = new int *[m];
    for (int i = 0; i < m; i++)
    {
        ans[i] = new int[n];
    }
    ans[m - 1][n - 1] = input[m - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        ans[m - 1][i] = ans[m - 1][i + 1] + input[m - 1][i];
    }
    for (int i = m - 2; i >= 0; i--)
    {
        ans[i][n - 1] = ans[i + 1][n - 1] + input[i][n - 1];
    }
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            ans[i][j] = input[i][j] + min(ans[i + 1][j], min(ans[i + 1][j + 1], ans[i][j + 1]));
        }
    }
    int temp = ans[0][0];
    for (int i = 0; i < n; i++)
    {
        delete[] ans[i];
    }
    delete[] ans;
    return temp;
}
int minCost(int **input, int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }
    int x = INT_MAX;
    int y = INT_MAX;
    int z = INT_MAX;
    if (i < m - 1)
    {
        x = minCost(input, i + 1, j, m, n);
    }
    if (j < n - 1)
    {
        y = minCost(input, i, j + 1, m, n);
    }
    if (i < m - 1 && j < n - 1)
    {
        z = minCost(input, i + 1, j + 1, m, n);
    }
    return input[i][j] + min(x, min(y, z));
}
int minCostPath(int **input, int m, int n)
{
    return minCost(input, 0, 0, m, n);
}
int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath_DP(arr, n, m) << endl;
}