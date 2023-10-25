/*
LeetCode Problem : 198

*/
int maxMoneyLooted_DP(int *arr, int n)
{
	//Write your code here
	if(n==0){
		return 0;
	}
	int *dp=new int[n];
	for(int i=n-1;i>=0;i--){
		if(i+2<n){
			dp[i]=arr[i]+dp[i+2];
		}
		if(i+1<n){
			dp[i]=max(dp[i],dp[i+1]);
		}
	}
	int ans=dp[0];
	delete []dp;
	return ans;
}
int maxMoneyLooted(int *arr,int n){
    if(n<=0){
        return 0;
    }
    return max(arr[0]+maxMoneyLooted(arr+2,n-2),maxMoneyLooted(arr+1,n-1));
}