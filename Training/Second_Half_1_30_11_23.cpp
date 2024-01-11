#include <iostream>
using namespace std;
void flip(string &s,int i,int k){
    for(int j=i;j<i+k;j++){
        if(s[j]=='1') s[j]='0';
        else s[j]='1';
    }
}
int count_flip(string& s,int k){
    int count = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            if(i+k<=s.length()){
                flip(s,i,k);
                count++;
            }else{
                return -1;
            }
        }
    }
    return count;
}
int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << count_flip(s,k) << endl;
    //cout << s;
    return 0;
}