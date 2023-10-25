#include <iostream>
using namespace std;
int main(){
    
     int count=0,cloop=0,input[]={5,0,0,7,4,8,1,3,0,7,2,0},size=12;
    for(int i=size-1;input[i]!=0;i--){
            count++;
    }
    for(int pos=0;pos<size-count;pos++){
        if(input[pos]==0){
            int prev=pos+1;
            for(;prev<size;prev++){
                input[prev-1]=input[prev];
            }
            input[prev]=0;
            if(input[pos+1]==0){
                pos--;
            }
        }

    }
    for(int i=0;i<size;i++){
        cout << input[i] << " ";
    }
    cout << endl;
    return 0;
}