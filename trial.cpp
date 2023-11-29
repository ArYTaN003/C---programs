#include <iostream>
using namespace std;
int partition(int *a,int s,int e){
	int i=s-1;
	for(int j=s;j<e;j++){
		if(a[j]<=a[e]){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[e]);
	for(int i=s;i<=e;i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return i+1;
}
void quickSort(int* a,int s,int e){
	if(s<e){
		int pivot = partition(a,s,e);
		cout << pivot << endl;
		quickSort(a,s,pivot-1);
		quickSort(a,pivot+1,e);
	}
}
int main(){
	int n=9;
	int a[]={15,22,30,10,65,64,3,9,2};
	quickSort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
	//delete []a;
	return 0;
}