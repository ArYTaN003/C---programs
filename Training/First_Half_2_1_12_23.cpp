#include <iostream>
using namespace std;
class Node{
    public:
    char data;
    Node * next;
    Node(char val){
        data=val;
        next=NULL;
    }
    ~Node(){
        if(next)
            delete next;
    }
};
Node * insert(Node * head,int v){
    if(head==NULL){
        head = new Node(v);
        return head;
    }else{
        Node * p =head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=new Node(v);
        return head;
    }
}
void print(Node * head){
    if(head==NULL) return ;
    Node * curr = head;
    while(curr!=NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
Node * rev(Node * head){
    if(head==NULL || head->next==NULL) return head;
    Node * r = rev(head->next);
    head->next->next=head;
    head->next=NULL;
    return r;
}
bool palindrome(Node * head){
    Node * slow = head;
    Node * fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast=fast->next->next;
    }
    Node *h2 = slow->next;
    h2=rev(h2);
    slow->next=NULL;
    Node *p1=head;
    Node *p2 =h2;
    while(p1 && p2){
        if(p1->data!=p2->data){
            return false;
        }
        p1=p1->next;
        p2=p2->next;
    }
    return true;
}
int main(){
    Node * head = NULL;
    string st;
    cin >>st;
    for(int i=0;i<st.length();i++){
        head = insert(head,st[i]);
    }
    print(head);
    if(palindrome(head)){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
    return 0;   
}