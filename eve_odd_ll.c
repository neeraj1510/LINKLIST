#include<stdio.h> 
#include<stdlib.h> 

/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 


struct Node *MY_HEAD, list;
/* Function to saperate out the even and odd number in linked list */
struct Node *eve_odd(struct Node *head)
{
	struct Node *headeve = NULL;
	struct Node *headodd = NULL;
	struct Node *lasteve = NULL;
	struct Node *lastodd = NULL;
	struct Node *curr = head;
	int flag = 0;
	while(curr != NULL)
	{
		if(curr->data % 2 == 0)
		{
			if(headeve == NULL)
			{
				headeve = lasteve = curr;
			}
			else
			{
				lasteve->next = curr;
				lasteve = curr;
			}
		}
		else
		{
			if(headodd == NULL)
			{
				headodd = lastodd = curr;
			}
			else
			{
				lastodd->next = curr;
				lastodd = curr;
			}
		}
		curr = curr->next;
	}
	if(headeve == NULL)
	{
		if(headeve == NULL)
		{
			head=headodd;
		}
		else 
		{
			head=headeve;
			lastodd->next = NULL;
			lasteve->next = headodd;
		}
	}
	else
	{
		if(headodd == NULL)
		{
			head=headeve; 
		}
		else 
		{
			head=headodd;
			lasteve->next = NULL;
			lastodd->next = headeve;
		}
	}
	return head;

}
void push(struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = 
		(struct Node*) malloc(sizeof(struct Node)); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

// A utility function to print a given linked list 
void printList(struct Node *head) 
{ 
	struct Node *ptr = head;
	if(head == NULL)
	{
		printf("Linklist is Empty\n");
		exit(0);
	}
	while (ptr != NULL) 
	{ 
		printf("%d->", ptr->data); 
		ptr = ptr->next; 
	} 
	printf("NULL\n"); 
} 

struct Node * creat(int val)
{
	struct Node * tmp = malloc(sizeof(struct Node));
	if(tmp == NULL)
		return NULL;
	tmp->next = NULL;
	tmp->data=val;
	return tmp;
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
/* Driver program to test below function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 
	struct Node* tail = NULL; 
	int i, pos; 
	head = r(head, 1);	
	head = r(head, 11);	
	head = r(head, 3);	
	head = r(head, 6);	
	head = r(head, 8);	
	head = r(head, 0);	
	head = r(head, 9);	
	printList(head);
	head = eve_odd(head);
	printList(head);
	return 0; 
} 

