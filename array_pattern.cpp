#include <iostream>
#include<cstring>
using namespace std;
int main(){
    int i,j,k,flag,n1,n2;
    
  
    string a,b;
    cout << "Enter String : ";
    cin >> a;
    cout << "Enter Pattern : ";
    cin >> b;
    n1=a.length();
    n2=b.length();
    for(i=0;i<n1;i++){
        cout << i <<endl;
        flag=0;
        for(j=0;j<n2;j++){
            if(a[i+j]!=b[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout << "found"<<endl;
            break;
        }
        else if(j>1){
                i=i+j-1;
            }
        }
    if(flag==1){
        cout << "Not Found" << endl;
    }
}