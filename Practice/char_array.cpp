#include <iostream>

using namespace std;
void reverseStringWordWise(char input[]) {
    // Write your code here
    int count=-1;
    //count the total number of characters
    for(int i=0;input[i]!='\0';i++){
        count++;
    }
    //reverse the array
    for(int i=0,j=count;i<=j;i++,j--){
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
    }
   int l=0;//points to the starting index of a word, since the first word will start at 0 , its initial value is 0.
    for(int i=0;input[i]!='\0';i++){
        if(input[i+1]=='\0'){//the last word will have null character to indicate its end.
          int r = i ;
          for (; l <= r; r--, l++) {
            char temp = input[r];
            input[r] = input[l];
            input[l] = temp;
          }
        }
        // space indicates a word has ended except for the last word
        if(input[i]==' '){ 
            int r=i-1;//points to the index of the last character of the word
            //reverse the word
            for (; l <= r; r--, l++) { 
              char temp = input[r];
              input[r] = input[l];
              input[l] = temp;
            }
            l = i + 1; // points to the starting index of next word
        }
    }
}
int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
