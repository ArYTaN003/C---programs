//Recursive Function
Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node *rev=reverseLinkedListRec(head->next);
	head->next->next=head;
	head->next=NULL;
	return rev;
}
//Iterative Function
Node *reverseLinkedList(Node *head) {
    // Write your code here
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node *prev=NULL;
	Node *curr = head;
	Node *next=head->next;
	while(curr->next!=NULL){
		curr->next=prev;
		prev=curr;
		curr=next;
		next=next->next;
	}
	curr->next=prev;
	prev=curr;
	return prev;
}