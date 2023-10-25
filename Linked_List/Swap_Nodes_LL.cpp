class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
Node *swapNodes(Node *head, int i_n, int j_n)
{
	//Write your code here
	if(head==NULL || i_n==j_n){
		return head;
	}
	if(i_n==0 || j_n==0){
		int count=0;
		Node *iprev=NULL;
		Node *jprev=NULL;
		Node *i=NULL;
		Node *j=NULL;
		Node *temp=head;
		if(i_n==0){
			i=head;
			while(temp!=NULL){
				if(count==j_n-1){
					jprev=temp;
				}
				else if(count==j_n){
					j=temp;
				}
				temp=temp->next;
				count++;
			}
			jprev->next=i;
			Node *next=j->next;
			j->next=i->next;
			i->next=next;
			head=j;
		}
		if(j_n==0){
			j=head;
			while (temp != NULL) {
				if (count == i_n - 1) {
				iprev = temp;
				}
				else if(count==i_n){
					i=temp;
				}
				temp = temp->next;
				count++;
			}
			iprev->next = j;
			Node *next = j->next;
			j->next = i->next;
			i->next = next;
			head = i;
        }
		return head;
	}
	else if(i_n-j_n==-1 || i_n-j_n==1){
		int count = 0;
		Node *iprev = NULL;
		Node *jprev = NULL;
		Node *i = NULL;
		Node *j = NULL;
		Node *temp = head;
		while(temp!=NULL){
			if(count==i_n-1){
				iprev=temp;
			}
			if(count==i_n){
				i=temp;
			}
			if(count==j_n-1){
				jprev=temp;
			}
			if(count==j_n){
				j=temp;
			}
			temp=temp->next;
			count++;
		}
		if(i_n<j_n){
			iprev->next=j;
			i->next=j->next;
			j->next=i;
		}
		else{
			jprev->next=i;
			j->next=i->next;
			i->next=j;
		}
		return head;
    }
	else{
      int count = 0;
      Node *iprev = NULL;
      Node *jprev = NULL;
      Node *i = NULL;
      Node *j = NULL;
      Node *temp = head;
      while (temp != NULL) {
        if (count == i_n - 1) {
          iprev = temp;
        }
        if (count == i_n) {
          i = temp;
        }
        if (count == j_n - 1) {
          jprev = temp;
        }
        if (count == j_n) {
          j = temp;
        }
        temp = temp->next;
        count++;
      }
	  jprev->next=i;
	  iprev->next=j;
	  Node *next=i->next;
	  i->next=j->next;
	  j->next=next;
	  return head;
    }
}