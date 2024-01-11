#include <iostream>
using namespace std;
int main(){
    char input1[]={"aab"},input2[]={"aaa"};    
    int arr[26];
    for(int i=0;i<26;i++){
        arr[i]=0;
    }
    for(int i=0;input1[i]!='\0';i++){
        arr[input1[i]-97]++;
    }
    
    for(int i=0;input2[i]!='\0';i++){
        arr[input2[i]-97]--;
    }
    for(int i=0;i<26;i++){
        cout << (char)(i+97) << ':' << arr[i] << endl;
    }
    
}