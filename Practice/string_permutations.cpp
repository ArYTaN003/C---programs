 #include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
int fact(int n){
	if(n<=1){
		return 1;
	}
	else{
		return n*fact(n-1);
	}
}
 int returnPermutations(string input, string output[], int sc=0) {
    /* Don't write main() function.
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question
     */
    if (input.length() == 1 || sc == input.length()) {
      output[0] = input;
      return fact(input.length());
    }
    int size=returnPermutations(input.substr(0,sc)+input.substr(sc+1),output);
	for(int i=0;i<size;i++){
		output[i]=input[sc]+output[i];
	}
	int size1=returnPermutations(input, output+size, sc+1);
  	return fact(input.length());
}
int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}