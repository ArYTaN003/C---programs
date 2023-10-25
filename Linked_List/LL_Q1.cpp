#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    static int length;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    ~Node(){
        Node::length--;
    }
    static void Inc(){
        Node::length++;
    }
};


void print(Node *head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
Node* takeInput(){
    char ch='y';
    Node * head=NULL,*tail=NULL;
    while(ch!='n'){
        int element;
        cout << "Enter Data : ";
        cin >> element;
        Node *n=new Node(element);
        if(head==NULL){
            head=n;
            tail=head;
        }
        else{
            tail->next=n;
            tail=tail->next;
        }
       // Node::Inc();
        cout << "Do you want to enter more elements ? (y/n) : ";
        cin >> ch;
    }
    return head;
}

int main(){
    Node *n1=takeInput();
    print(n1);
    //cout << n1->length << endl;
}