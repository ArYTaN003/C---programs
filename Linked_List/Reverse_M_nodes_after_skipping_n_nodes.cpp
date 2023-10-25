#include<iostream>
using namespace std;
#include "Linked_List.cpp"
Node* reverse(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *ch = reverse(head->next);
    head->next->next = head;
    head->next=NULL;
    return ch;
}
Node* reverse_M_nodes_skip_N_Nodes(Node* head,int& m,int& n){
    if(head==NULL || head->next==NULL || n==0){
        return head;
    }
    Node* curr = head;
    Node* temp=NULL;
    Node* prev=NULL;
    Node* prev2=NULL;
    int count;
    for(count=0;count<m && curr!=NULL;count++){
        prev = curr;
        curr = curr->next;
    }
    if(curr!=NULL){
        // cout << "Curr ";
        // if(prev==NULL) cout << "-1 ";
        // else cout << prev->data << " ";
        // cout << curr->data << endl;
        prev2 = prev;
        temp = curr;
        for(count=0;count<n && temp!=NULL;count++){
            prev2 = temp;
            temp=temp->next;
        }
        /*cout << "second ";
        if(prev2==NULL) cout << "-1 ";
        else cout << prev2->data << " ";
        cout << temp->data << endl;*/
        if(prev2!=NULL) prev2->next=NULL;
        if(prev!=NULL) prev->next = reverse(curr);
        else head = reverse(curr);
        curr->next=reverse_M_nodes_skip_N_Nodes(temp,m,n);
    }
    return head;
}
int main(){
    Node* head = takeinput();
    int m,n;
    cin >> m>> n;
    head=reverse_M_nodes_skip_N_Nodes(head,m,n);
    print(head);
}