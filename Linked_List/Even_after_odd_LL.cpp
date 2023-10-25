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

Node *evenAfterOdd(Node *head)
{
	//write your code here
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node *oh=NULL;Node *ot=NULL;Node *eh=NULL;Node *et=NULL;
	while(head!=NULL){
		if(head->data%2==0){
			if(eh==NULL){
				eh=head;
				et=head;
			}
			else{
				et->next=head;
				et=et->next;
			}
		}
		else{
			if (oh == NULL) {
			oh = head;
			ot = head;
			} else {
			ot->next = head;
			ot = ot->next;
			}
        }
		head=head->next;
	}
	if(oh!=NULL && eh!=NULL){
		ot->next=eh;
		et->next=NULL;
		return oh;
	}
	else if(oh!=NULL){
		ot->next=NULL;
		return oh;
	}
	else{
		et->next=NULL;
		return eh;
	}
}