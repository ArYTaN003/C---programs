/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/
Node * reverse(Node *head){
    if(head->next==NULL || head==NULL){
        return head;
    }
    Node *rev=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return rev;
}
Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
     if(head==NULL){
         return head;
     }
    Node *temp=reverse(head);
    Node *h2=temp;
    bool carry=true;
    while(temp->next!=NULL){
         if(carry){
              temp->data=(temp->data+1)%10;
         }           
        
          if(temp->data==0 && carry){
              carry=true;
            }
            else{
                carry=false;
            }
        temp=temp->next;
    }
   if(carry){
        temp->data=(temp->data+1)%10;
       if(temp->data==0){
             Node *car=new Node(1);
             temp->next=car;
        }
   }
   return reverse(h2);
   
}


