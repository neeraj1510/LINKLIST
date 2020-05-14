#include<stdio.h> 
#include<stdlib.h> 

/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 


struct Node *MY_HEAD, list;
/* Print length of LL recursive*/
int length_ll(struct Node *head)
{
	if(head== NULL)
		return 0;

	return (1+length_ll(head->next));

}
/* Add node to Linklist*/
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
/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 
	struct Node* tail = NULL; 
	int i, pos; 
	for (i=10; i>0; i--) 
	{ 
		push(&head, i); 
	}
	printList(head);
	int len = length_ll(head);
	printf("length = %d\n", len);
	return 0; 
} 

