/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
class Node{
    public:
    int data;
    Node *next;
    Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
};
Node *middle(Node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node *fast=head->next;
	Node *slow=head;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}
Node *merge(Node *head1,Node*head2){
  if (head1 == NULL && head2 == NULL) {
    return head1;
  } else if (head1 == NULL) {
    return head2;
  } else if (head2 == NULL) {
    return head1;
  }
  Node *fh = NULL;
  Node *ft = NULL;
  while (head1 != NULL && head2 != NULL) {
    if (head1->data <= head2->data) {
      if (fh == NULL) {
        fh = head1;
        ft = head1;
      } else {
        ft->next = head1;
        ft = ft->next;
      }
      head1 = head1->next;
    } else {
      if (fh == NULL) {
        fh = head2;
        ft = head2;
      } else {
        ft->next = head2;
        ft = ft->next;
      }
      head2 = head2->next;
    }
  }
  if (head2 == NULL && head1 != NULL) {
    ft->next = head1;
  } else if (head1 == NULL && head2 != NULL) {
    ft->next = head2;
  }
  return fh;
}
Node *mergeSort(Node *head)
{
	//Write your code here
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node *mid = middle(head);
	Node *second_half=mid->next;
	mid->next=NULL;
	Node *first_half = mergeSort(head);
	second_half = mergeSort(second_half);
	return merge(first_half, second_half);
}