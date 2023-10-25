int helper(int *arr,int n,int currMax){
	if(n==0){
		return 0;
	}
	int include=0,exclude=0;
	if(arr[0]>currMax){
		include=1+helper(arr+1,n-1,arr[0]);
	}
	exclude=helper(arr+1,n-1,currMax);
	return max(include,exclude);
}
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
	return helper(arr,n,INT_MIN);
}