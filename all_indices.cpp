#include <iostream>
using namespace std;
int count=0,k=0;
int allIndexes(int input[],int size,int x,int output[]){
    count++;
  if(size==0){
        return 0;
    }
    if(input[0]==x){
        output[++k]=count;
    }   
    int ans=allIndexes(input+1,size-1,x,output);
    if(ans==0){
        return 0;
    }
    else{
    return ans+1;
    }
}
int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}