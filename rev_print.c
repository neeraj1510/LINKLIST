#include<stdio.h> 
#include<stdlib.h> 

/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

// A utility function to print a given linked list in reverse order 
int printList_rev(struct Node *head) 
{
	struct Node *ptr = head;
	if(head == NULL)
	{
		return 0;

	}
	printList_rev(head->next);
	printf("%d->", head->data);
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
/*create the node and fill data */
struct Node * creat(int val)
{
	struct Node * tmp = malloc(sizeof(struct Node));
	if(tmp == NULL)
		return NULL;
	tmp->next = NULL;
	tmp->data=val;
	return tmp;
}
/*attac node at end with tail pointer*/ 
struct Node * insert_head_tail(struct Node **head1,struct Node *tail,int val)
{
	if((*head1 == NULL))
	{
		*head1 = creat(val);
		tail=*head1;
		return tail;
	}
	tail->next= creat(val);
	if(tail->next == NULL)
		return NULL;
	tail = tail->next;
	return tail;
}
/* main */
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 
	struct Node* tail = NULL; 
	int i, val; 
	for (i=7; i>0; i--) 
	{ 
		tail  = insert_head_tail(&head,tail,i);
	}
	printList(head);
	printList_rev(head);
	printf("NULL\n");

	return 0; 
} 

