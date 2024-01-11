#include <iostream>
using namespace std;
int main(){
    int m,n;
    cout << "Enter No. of Rows : ";
    cin >> m >> n;
    int **p=new int*[m];
    for(int i=0;i<m;i++){
        p[i]=new int[n];
    }
    cout << "Memory Created" << endl;
   for(int i=0;i<m;i++){
        delete [] p[i];
    }
    delete [] p;
    cout << "Memory Deleted" <<endl;
}