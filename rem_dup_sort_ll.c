#include<stdio.h> 
#include<stdlib.h> 

/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 


struct Node *MY_HEAD, list;

// A utility function to print a given linked list terminated by -1
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
struct Node * rem_dup(struct Node *head)
{
	struct Node *f, *s, *t;
	f=head;

	while(f->data != -1)
	{
		s=f;
		f=f->next;

		if(f->data == s->data)
		{
			s->next = f->next;
			t=f;
			f=s;
			free(t);
			t=NULL;
		}
	}
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
	head = r(head, 1);	
	head = r(head, 1);	
	head = r(head, 1);	
	head = r(head, 1);	
	head = r(head, 1);	
	head = r(head, 1);	
	head = r(head, 1);	
	head = r(head, 1);	
	head = r(head, 2);	
	head = r(head, 3);	
	head = r(head, 3);	
	head = r(head, 3);	
	head = r(head, 4);	
	head = r(head, 4);	
	head = r(head, 5);	
	head = r(head, 5);	
	head = r(head, 5);	
	head = r(head, 7);	
	head = r(head, -1);	
	printList(head);
/* linklist is sorted */
	head = rem_dup(head);
	printList(head);
	return 0; 
} 

