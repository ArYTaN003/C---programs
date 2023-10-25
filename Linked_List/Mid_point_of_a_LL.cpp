/*
Here we have implemented a function to find the MID POINT OF A LL without finding the length

of the LL , the approach we have used here is that we have used 2 pointers

SLOW and FAST , as the name suggests the idea is that the slow pointer is going to traverse the linked list

one node at at a time, whereas the fast pointer is going to traverse the linked list by 2 nodes at a time,

so whats gonna happen is as soon as our fast pointer reaches NULL(while(fast!=NULL)), our slow pointer will be at the middle node,

as it is moving at half the speed of fast pointer , the only case that we need to handle is when the number of nodes

is even , as then the fast pointer is gonna reach the last node, and our code will give an error cause when the

instruction - fast=fast->next->next executes , as we are trying to go to the next node after null, i.e. we are trying to do

null->next , as fast->next is null, so we check the condition fast->next!=NULL in the while loop as well.
*/
#include<iostream>
using namespace std;
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
Node *midPoint(Node *head,Node *tail)
{
    // Write your code here
	if(head==NULL){
		return head;
	}
	Node *slow=head;
	Node *fast=head->next;
	while(fast!=tail && fast->next!=tail){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		Node *temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		Node *mid=midPoint(head,temp);
		cout << mid->data;
	}

	return 0;
}
void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}