/*
     ∞
   MaCTaN
     ∞
Aryan S Tandon
Keep Going On, Keep Coding
Never Stop Flowing
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    for (int p = 0; p < t; p++)
    {
        cin >> n;
        int ary = INT_MAX;
        int diff;
        for(int i=0;i<=5;i++){
            for(int j=0;j<=5;j++){
                for(int k=0;k<=5;k++){
                    for(int l=0;l<=5;l++){
                        diff = n-(i+j*3+k*6+l*10);
                        if(diff>=0 && diff%15==0){
                            ary = min(ary,i+j+k+l+diff/15);
                        }
                    }
                }
            }
        }
        cout << ary << endl;
    }
    return 0;
}