#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    if(n>=2){
        int max_index=0;
        for(int i=0;i<n;i++){
            if(arr[i]>=arr[max_index]){
                max_index=i;
            }
        }
        int second_max_index=INT_MIN;
        for(int i=0;i<n;i++){
            if(i!=max_index && second_max_index==INT_MIN){
                second_max_index = i;
            }
           else if(i!=max_index && arr[i]>=arr[second_max_index] && arr[i]<=arr[max_index]){
                second_max_index=i;
            }
        }
        cout << "Second Largest Number is : " << arr[second_max_index]  << " At Index : " << second_max_index << endl;
    }else{
        cout << "None" << endl;
    }
    delete []arr;
    return 0;
}