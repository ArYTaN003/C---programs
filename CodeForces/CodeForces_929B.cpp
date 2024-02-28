/*
     ∞
   MaCTaN 
     ∞
Aryan S Tandon
Keep Going On, Keep Coding 
Never Stop Flowing
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,tan;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        tan = 0;             
        int *arr = new int[n];
        for(int j=0;j<n;j++){
            cin >> arr[j];
            tan+=arr[j];
        }
        if(tan%3==0) cout << 0 << endl;
        else if(tan%3==2) cout << 1 << endl;
        else{
            bool flag = false;
            for(int j=0;j<n;j++){
                if((tan-arr[j])%3==0){
                    flag = true;
                    cout << 1 << endl;
                    break;
                }
            }
            if(!flag) cout << 2 << endl;
        }
        delete []arr;
    }
    return 0;                                                                                                                                                        
}                                                                      
