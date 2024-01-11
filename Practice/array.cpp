#include<iostream>
#include <climits>
using namespace std;

int main(){
    /* Read input as specified in the question.
     * Print output as specified in the question.
     */
     int c=0,size1=4,size2=2,input1[]={6,9,8,5},input2[]={1,3};
    int outsize = 1 + max(size1, size2);

		int *output = new int[outsize];
     int k, *inputn,s;
     int m=max(size1,size2);
     inputn=new int[m];
    if(m==size1){
        k=size1;
        s=size1-1;
        inputn=new int[size1];
        int l=size2-1;
        while(s>=0){
            if(l>=0){
            inputn[s]=input2[l];
            l--;
            }
            else{
                inputn[s]=0;
            }
            s--;
        }
        s=size1;
        for(int i=s-1;i>-1;i--){
        output[k]=(input1[i]+inputn[i]+c)%10;
        if ((input1[i] + inputn[i]) >=10) {
          c = 1;
        } else {
          c = 0;
        }
        k--;
    }
    }
    else if(m==size2){
        k=size2;
        s=size2-1;
        inputn = new int[size2];
        int l = size1-1;
        while(s>=0){
            if(l>=0){
            inputn[s]=input1[l];
            l--;
            }
            else{
                inputn[s]=0;
            }
            s--;
        }
        s=size2;
        for(int i=s-1;i>-1;i--){
        output[k]=(inputn[i]+input2[i]+c)%10;
        if ((inputn[i] + input2[i]) >=10) {
          c = 1;
        } else {
          c = 0;
        }
        k--;
    }
    }
    else{
        k=size1;
        s=size1;
        for(int i=s-1;i>-1;i--){
        output[k]=(input1[i]+input2[i]+c)%10;
        if ((input1[i] + input2[i]) >=10) {
          c = 1;
        } else {
          c = 0;
        }
        k--;
    }
    }
   
   
    output[0]=c;

    for(int i=0;i<outsize;i++){
        cout << output[i] << " ";
    }
    cout <<  endl;
    return 0;
}