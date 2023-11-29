#include <iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val=val;
        next=NULL;
    }
    ~Node(){
        if(next!=NULL) 
            delete next;
    }
};
void insert(Node*& head,int v){
    Node *n = new Node(v);
    if(head==NULL){
        head = n;
    }else{
        Node * p= head;
        while(p->next){
            p=p->next;
        }
        p->next=n;
    }
}
void print(Node*& head){
    Node *p = head;
    while(p){
        cout << p->val << " ";
        p=p->next;
    }
    cout << endl;
}
int connected(Node* head,int* nums,int n){
    unordered_map<int,Node*> mp;
    Node * p = head;
    while(p){
        mp[p->val]=p;
        p=p->next;
    }
    int connected = 0,count=0;
    for(int i=0;i<n-1;i++){
        if(mp[nums[i]]->next->val==nums[i+1]){
            if(count==0) count+=2;
            else count++;
        }else{
            connected+=count;
            count=0;
        }
    }
    connected+=count;
    return count;
}
int main(){
    Node* head = NULL;
    int n,temp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> temp;
        insert(head,temp);
    }
    cin >> n;
    int * nums = new int[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << connected(head,nums,n) << endl;   
    delete []nums;
    delete head;
}