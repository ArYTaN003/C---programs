#include <iostream>
using namespace std;
float knapsack(int *p,int *w,int n,int m){
    float profit = 0;
    float * r = new float[n];
    int * ind = new int[n];
    for(int i=0;i<n;i++){
        r[i]=((float)p[i])/((float)w[i]);
        cout << r[i] << endl;
        ind[i]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(r[i]<r[j]){
                swap(r[i],r[j]);
                swap(ind[i],ind[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << ind[i]  << " " << p[ind[i]] << " " << r[ind[i]] << endl;
        if(w[ind[i]]<m){
            profit+=p[ind[i]];
            m-=w[ind[i]];
        }else{
            profit+=r[ind[i]]*(m);
            break;
        }
    }
    delete []r;
    delete []ind;
    return profit;
}
int main(){
    int n,m;
    cin >> n;
    int * p = new int[n];
    int * w = new int[n];
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
     for(int i=0;i<n;i++){
        cin >> w[i];
    }
    cin >> m;
    cout << "Profit : " << knapsack(p,w,n,m) << endl;
    delete []p;
    delete []w;
    return 0;
}