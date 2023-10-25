#include<vector>
#include<bits/stdc++.h>
class PriorityQueue{
    std::vector<int> pq;
    int next_Index=-1;
    void upheapify(std::vector<int> &p){
        if(p.size()==1){
            return ;
        }
        int ind=next_Index-1;
        while(p.at(ind)<p.at((ind-1)/2) && ind!=0){
            std::iter_swap(p.begin()+(ind-1)/2,p.begin()+ind);
            ind=(ind-1)/2;
        }
    }
    void downheapify(std::vector<int> &p){
        if(p.size()<=1){
            return ;
        }
        int ind=0;
        int lc=1;
        int rc=2;
        int temp;
        int minIndex;
        while(lc<p.size()){
            minIndex=ind;
            if(p.at(minIndex)>pq.at(lc)){
                minIndex=lc;
            }
            if(rc<p.size() && p.at(minIndex)>p.at(rc)){
                minIndex=rc;
            }
            if(minIndex==ind){
                break;
            }
            std::iter_swap(pq.begin()+ind,pq.begin()+minIndex);
            ind=minIndex;
            lc=ind*2+1;
            rc=ind*2+2;
        }
    }
    public:
    PriorityQueue(){
        next_Index++;
    }
    void insert(int data){
        pq.push_back(data);
        next_Index++;
        upheapify(pq);
    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq.at(0);
    }
    void removeMin(){
        if(isEmpty()){
            return ;
        }
        std::iter_swap(pq.begin(),pq.begin()+next_Index-1);
        pq.pop_back();
        next_Index--;
        downheapify(pq);
    }
};