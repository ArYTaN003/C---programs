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
    int t,a,b,l;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> a >> b >> l;
        int ans = 0;
        set<int> st;
        for(int i=1;i<=l;i*=a){
            for(int j=1;i*j<=l;j*=b){
                if(l%(i*j)==0){
                    st.insert(l/(i*j));
                }
            }
        }
        cout << st.size() << endl;
            
    }
    return 0;                                                                                                                                                        
}                                                                      