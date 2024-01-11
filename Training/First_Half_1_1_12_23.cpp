#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
Node * insert(Node * head,int v){
    if(head==NULL){
        head = new Node(v);
        head->next=head;
        return head;
    }else{
        Node * p =head;
        while(p->next!=head){
            p=p->next;
        }
        p->next=new Node(v);
        p=p->next;
        p->next=head;
        return head;
    }
}
void print(Node * head){
    if(head==NULL) return ;
    Node * curr = head;
    Node * n = head->next;
    while(n!=head){
        cout << curr->data << " ";
        curr = curr->next;
        n=n->next;
    }
    cout << curr->data << endl;
}
pair<Node*,Node*> split(Node * head){
    if(head==NULL) return {NULL,NULL};
    Node * slow = head;
    Node * fast = head->next;
    while(fast!=head && fast->next!=head){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node * h2 = slow->next;
    slow->next=head;
    Node * p = h2;
    while(p->next!=head){
        p=p->next;
    }
    p->next=h2;
    return {head,h2};
}
int main(){
    Node * head=NULL;
    head = insert(head,1);
    head = insert(head,2);
    head = insert(head,3);
    head = insert(head,4);
    head = insert(head,5);
    head = insert(head,6);
    print(head);
    pair<Node*,Node*> p = split(head);
    print(p.first);
    print(p.second);
    //cout << p.first->data << " " << p.second->data << endl;
    return 0;
}