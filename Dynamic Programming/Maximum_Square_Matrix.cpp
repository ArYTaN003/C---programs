int findMaxSquareWithAllZeros(int **arr, int rows, int cols)
{
    // Write your code here
    int **dp = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        dp[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        dp[i][0] = (arr[i][0] == 0 ? 1 : 0);
    }
    for (int i = 0; i < cols; i++)
    {
        dp[0][i] = (arr[0][i] == 0 ? 1 : 0);
    }
    int ans = 0;
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (arr[i][j] == 0)
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
            else
            {
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    for (int i = 0; i < rows; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}