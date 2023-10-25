/*
You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
 Output format :
For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true
Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true
Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.

For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.
*/
#include <iostream>

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

using namespace std;
int length(Node *head){
	int l=0;
	while(head!=NULL){
  l++;
  head = head->next;
	}
	return l;
}
Node * reverse(Node * head){
	Node *temp=NULL;
	while(head!=NULL){
          if (temp == NULL) {
            temp = new Node(head->data);
          } else {
            Node *n = new Node(head->data);
            n->next = temp;
            temp=n;
          }
        head = head->next;
    }
	return temp;
}
bool isPalindrome(Node *head)
{
    //Write your code here
    if (head == NULL || head->next==NULL) {
      return true;
	}
	int l=length(head),mid;
	if(l%2==0){
		mid=(l-1)/2;
	}
	else{
		mid=l/2;
	}
	int count=0;
	Node *temp=head;
	while(count<=mid){
		count++;
		temp=temp->next;
	}
    Node *secondhead = reverse(temp);
	temp=head;
          while (temp->data == secondhead->data && secondhead->next!=NULL) {
            temp = temp->next;
            secondhead = secondhead->next;
          }
         if(secondhead->next==NULL && temp->data==secondhead->data){
			 return true;
		 }
		 else{
			 return false;
		 }
	
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
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}