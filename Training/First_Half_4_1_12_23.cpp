#include <iostream>
#include<cmath>
using namespace std;
int min_perfect2(int n){
    if(n==0) return 0;
    int ans = n;
    for(int i=2;i*i<=n;i++){
        ans = min(ans,1+min_perfect2(n-i*i));
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    cout << min_perfect2(n) << endl;
    return 0;
}