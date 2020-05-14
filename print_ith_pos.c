#include<stdio.h> 
#include<stdlib.h> 

/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 


struct Node *MY_HEAD, list;

int print_ith_node(struct Node *head, int pos)
{
	struct Node *tmp =head;
	int count =0;

	if(head== NULL)
		return -1;
/* As soon as the pos founf in the Linklist, print data and exit*/
	while(tmp != NULL)
	{
		if(count == pos)
		{
			printf("value at %d position is %d\n", pos, tmp->data);
			return 0;
		}
		++count;
		tmp =tmp->next;
	}
	return -1;

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



/* Drier program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 
	struct Node* tail = NULL; 
	int i, pos; 
	for (i=7; i>=0; i--) 
	{ 
		push(&head, i); 
	}

	/* Printf the linklist */
	printList(head);
	/* statically given the data */
	pos = 3;
	if((print_ith_node(head,pos) <0 ))
		printf("position not present in lisklist\n");

	return 0; 
} 

