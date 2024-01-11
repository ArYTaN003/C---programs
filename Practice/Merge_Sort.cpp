#include <iostream>
using namespace std;
void merge(int input[], int si, int ei) {
  int i = si;
  int mid = (si + ei) / 2;
  int j = mid + 1;
  int l = ei - si + 1;
  int *c = new int[l], k = 0;
  while (i <= mid && j <= ei) {
    if (input[i] <= input[j]) {
      c[k] = input[i];
      i++;
      k++;
    } else {
      c[k] = input[j];
      j++;
      k++;
    }
  }
  while (i <= mid) {
    c[k] = input[i];
    i++;
    k++;
  }
  while (j <= ei) {
    c[k] = input[j];
    k++;
    j++;
  }
  for (int p = si,m=0; p <=ei && m<l; p++,m++) {
    input[p] = c[m];
  }
  delete []c;
}
void mergesort(int input[],int si,int ei){
	if(si>=ei){
		return ;
	}
	int mid=(si+ei)/2;
	mergesort(input, si, mid);
	mergesort(input,mid+1,ei);
	merge(input,si,ei);
}

void mergeSort(int input[], int size) {
  // Write your code here
  mergesort(input, 0, size - 1);
}
int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}