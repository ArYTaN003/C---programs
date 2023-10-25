#include <cstring>
#include <iostream>
using namespace std;
int editDistance(string s1,string s2, int **output){
	if(s1.length()==0 || s2.length()==0){
		output[s1.length()][s2.length()]=max(s1.length(),s2.length());
		return output[s1.length()][s2.length()];
	}
	int m=s1.length();
	int n=s2.length();
	if(output[m][n]!=-1){
		return output[m][n];
	}
	if(s1[0]==s2[0]){
		output[m][n]=editDistance(s1.substr(1),s2.substr(1),output);
	}else{
		int replace=editDistance(s1.substr(1),s2.substr(1),output);
		int del=editDistance(s1, s2.substr(1),output);
		int insert=editDistance(s1.substr(1),s2,output);
		output[m][n]=1+min(replace,min(del,insert));
	}
	return output[m][n];
}
int editDistance_DP(string s1, string s2)
{
	//Write your code here
	int m=s1.length();
	int n=s2.length();
	int **output=new int*[m+1];
	for(int i=0;i<=m;i++){
		output[i]=new int[n+1];
		memset(output[i],-1,sizeof(int)*(n+1));
	}
	for(int i=0;i<=n;i++){
		output[0][i]=i;
	}
	for(int j=0;j<=m;j++){
		output[j][0]=j;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s1[m-i]==s2[n-j]){
				output[i][j]=output[i-1][j-1];
			}
			else{
				output[i][j]=1+min(output[i-1][j-1],min(output[i-1][j],output[i][j-1]));
			}
		}
	}
	int t=output[m][n];
	for(int i=0;i<=m;i++){
		delete []output[i];
	}
	delete []output;
	return t;
}
int editDistance_mem(string s1, string s2)
{
	//Write your code here
	int **output=new int*[s1.size()+1];
	for(int i=0;i<=s1.size();i++){
		output[i]=new int[s2.size()+1];
		memset(output[i],-1,sizeof(int)*(s2.size()+1));
	}
	int t=editDistance(s1, s2, output);
	for(int i=0;i<=s1.size();i++){
		delete []output[i];
	}
	delete []output;
	return t;
}
int editDistance(string s1, string s2) {
	// Write your code here
	if(s1.length()==0 || s2.length()==0){
		return max(s1.length(),s2.length());
	}
	if(s1[0]==s2[0]){
		return editDistance(s1.substr(1),s2.substr(1));
	}
	int replace=editDistance(s1.substr(1),s2.substr(1));
	int del=editDistance(s1, s2.substr(1));
	int insert=editDistance(s1.substr(1),s2);
	return 1+min(replace,min(del,insert));
}
int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;
    cout << editDistance_DP(s1,s2);
    cout << editDistance_mem(s1,s2);
    cout << editDistance(s1, s2);
}