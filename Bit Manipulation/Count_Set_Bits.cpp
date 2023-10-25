#include<iostream>
using namespace std;
int count_1(int n){
    int count=0;
    while(n!=0){
        count+=n&1;
        n=n>>1;
    }
    return count;
}
//Brian Kernighan’s Algorithm
int count_2(int n){
    int count=0;
    while(n){
        count++;
        n=(n)&(n-1);
    }
    return count;
}
int main(){ 
    int n;
    cin >> n;
    cout << "Number of Set Bits are: " << count_1(n) << endl;
    cout << "Number of Set Bits are: " << count_2(n) << endl;
    return 0;
}
