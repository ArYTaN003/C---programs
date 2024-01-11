#include<iostream>
using namespace std;
long long int pow(int x, int p);
int main() {
	// Write your code here
	int n,p=0;
    long long int bin=0;
    cin >> n;
    while(n!=0){
        
        bin+=(n%2)*pow(10,p);
        n=n/2;
        p++;
    }
    cout << bin <<endl;
}
long long int pow(int x, int p){
    long long int pro=1;
    for(int i=1;i<=p;i++){
        pro*=x;
    }
    return pro;
}
