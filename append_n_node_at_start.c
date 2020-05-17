#include<stdio.h> 
#include<stdlib.h> 

/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 


struct Node *MY_HEAD, list;

// A utility function to print a given linked list 
void printList(struct Node *head) 
{ 
	struct Node *ptr = head;
	if(head == NULL)
	{
		printf("Linklist is Empty\n");
		exit(0);
	}
	while (ptr->data != -1) 
	{ 
		printf("%d->", ptr->data); 
		ptr = ptr->next; 
	} 
	printf("NULL\n"); 
} 
/* Craete the node and fill the data */
struct Node * creat(int val)
{
	struct Node * tmp = malloc(sizeof(struct Node));
	if(tmp == NULL)
		return NULL;
	tmp->next = NULL;
	tmp->data=val;
	return tmp;
}
/* Append Last n node at head */
struct Node * append_n_at_head(struct Node *head1, int n)
{
	/* Assume the length > n */
	struct Node *head, *fast, *slow, *tmp;
	tmp = head = fast = slow = head1;
	int pos = n-1;
	if(head == NULL)
	{
		return NULL;
	}
	while(pos > 0)
	{
		fast = fast->next;
		pos--;
	}	
	fast=fast->next;
	while(fast->next->data != -1)
	{
		fast = fast->next;
		slow = slow->next;
	}
	head = slow->next;
	slow->next = fast->next;
	fast->next = tmp;
	return head;

}
struct Node *r(struct Node *head, int val)
{
	struct Node *tmp = head;
	if (tmp == NULL)
	{
		/* create the node */
		tmp=creat(val);
		head = tmp;
		return tmp;
	}
	tmp->next = r(tmp->next, val);

}
/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 
	struct Node* tail = NULL; 
	int i, pos; 
	head = r(head, 1);	
	head = r(head, 2);	
	head = r(head, 3);	
	head = r(head, 4);	
	head = r(head, 5);	
	head = r(head, -1);	
	printList(head);
	/* length of linklist is 5 terminated by -1, so given pos always less than 5*/

	pos  = 3;
	head = append_n_at_head(head, pos);
	printList(head);
	return 0; 
} 

