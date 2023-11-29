#include <iostream>
#include<vector>
using namespace std;
int cut(int n,vector<int>& price,int index){
    if (index == 0) {
        return n * price[0];
    }
    int exclude = cut(n,price,index-1);
    int include = INT_MIN;
    int rod_length = index + 1;
 
    if (rod_length <= n)
        include = price[index]+ cut(n-rod_length,price,index);
   
    return max(exclude, include);
}
int main(){
    vector<int> arr = {1, 5, 8, 9, 10, 17, 17, 20};
    int n;
    cin >> n;
    cout << cut(n,arr,arr.size()-1) << endl;
    return 0;
}