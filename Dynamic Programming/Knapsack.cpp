
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	if (n == 0 || maxWeight == 0)
{
    return 0;
}
if (weights[n - 1] > maxWeight)
{
    return knapsack(weights, values, n - 1, maxWeight);
}
int includeItem = values[n - 1] + knapsack(weights, values, n - 1, maxWeight - weights[n - 1]);
int excludeItem = knapsack(weights, values, n - 1, maxWeight);
return max(includeItem, excludeItem);
}
int knapsack_dp(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
	int **dp=new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i]=new int[maxWeight+1];
	}
	for(int w=0;w<=maxWeight;w++){
		dp[n][w]=0;
	}
	for(int i=n-1;i>=0;i--){
		for(int w=0;w<=maxWeight;w++){
			if(weight[i]<=w){
				dp[i][w]=max(dp[i+1][w],value[i]+dp[i+1][w-weight[i]]);
			}else{
				dp[i][w]=dp[i+1][w];
			}
		}
	}
	int t=dp[(n+1)%2][maxWeight];
	for(int i=0;i<=n;i++){
		delete []dp[i];
	}
	delete []dp;
	return t;
}