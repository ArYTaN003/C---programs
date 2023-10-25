#include "Linked_List.cpp"
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
	if(head1==NULL && head2==NULL){
		return head1;
	}
	else if(head1==NULL){
		return head2;
	}
	else if(head2==NULL){
		return head1;
	}
	Node *fh=NULL;
	Node *ft=NULL;
	while(head1!=NULL && head2!=NULL){
		if(head1->data <= head2->data){
			if(fh==NULL){
				fh=head1;
				ft=head1;
			}
			else{
				ft->next=head1;
				ft=ft->next;
			}
			head1=head1->next;
		}
		else{
			if(fh==NULL){
				fh=head2;
				ft=head2;
			}
			else{
				ft->next=head2;
				ft=ft->next;
			}
			head2=head2->next;
		}
	}
	if(head2==NULL && head1!=NULL){
		ft->next=head1;
	}
	else if(head1==NULL && head2!=NULL){
		ft->next=head2;
	}
	return fh;
}