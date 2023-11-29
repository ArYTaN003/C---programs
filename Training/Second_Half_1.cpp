#include <iostream>
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
};
Node* reverse(Node *h){
        if(h==NULL || h->next==NULL) return h;
        Node * rev = reverse(h->next);
        h->next->next=h;
        h->next=NULL;
        return rev;
}
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
Node * addLL(Node *h1,Node* h2){
    Node * h = NULL;
    Node * p1 = reverse(h1);
    Node * p2 = reverse(h2);
    int carry =  0,temp;
    Node *n;
    while(p1!=NULL && p2!=NULL){
        temp = (p1->val+p2->val+carry);
        n = new Node(temp%10);
        carry = temp/10;
        if(h==NULL){
            h = n;
        }else{
            n->next = h;
            h=n;
        }
        p1=p1->next;
        p2=p2->next;
    }
    while(p1!=NULL){
        temp = (p1->val+carry);
        n = new Node(temp%10);
        carry = temp/10;
        if(h==NULL){
            h = n;
        }else{
            n->next = h;
            h=n;
        }
        p1=p1->next;
    }
    while(p2!=NULL){
        temp = (p2->val+carry);
        n = new Node(temp%10);
        carry = temp/10;
        if(h==NULL){
            h = n;
        }else{
            n->next = h;
            h=n;
        }
        p2=p2->next;
    }
    if(carry){
        n = new Node(carry);
        n->next = h;
        h=n;
    }
    return h;
}
int main(){
    Node *h1=NULL;
    Node *h2=NULL;
    int n1,temp;
    cout << "Enter Number nodes in first list : ";
    cin >> n1;
    cout << "Enter elements : " <<endl;
    for(int i=0;i<n1;i++){
        cin >> temp;
        insert(h1,temp);
    }
    cout << "Enter Number nodes in second list : ";
    cin >> n1;
    cout << "Enter elements : " << endl;
    for(int i=0;i<n1;i++){
        cin >> temp;
        insert(h2,temp);
    }
    Node * add = addLL(h1,h2);
    print(add);
    //print(h1);
    //print(h2);
}