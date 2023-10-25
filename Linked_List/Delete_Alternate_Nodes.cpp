
/*********************************************************
 
    // Following is the node structure

    class Node {
    public:
        int data;
        Node * next;
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
    
        ~Node() {
            if(next) {
                delete next;
            }
        }
    };

*********************************************************/

void deleteAlternateNodes(Node *head) {
    //Write your code here
    if(head==NULL || head->next==NULL){
        return ;
    }
    Node *temp=head;
    while(temp!=NULL){
        Node *n=temp->next;
        temp->next=temp->next->next;
        n->next=NULL;     
        delete n;
        temp=temp->next;
    }
}