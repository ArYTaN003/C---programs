#include <iostream>
#include <cstring>
#include<vector>
using namespace std;
int main(){
    cout << "{";
    for(int i=0;i<26;i++){
        cout << "{";
        cout << "\"" << i+1 << "\""<< ",";
        cout << "\"" << (char)('A'+i) << "\"";
        cout <<  "},";  
    }
    cout << "}";
    return 0;
}