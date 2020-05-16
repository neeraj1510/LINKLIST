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
	while (ptr != NULL) 
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
/* Code for delete the node after the ith position */
struct Node * del_ith_pos_recursive(struct Node **head1, int pos)
{
	struct Node *head = *head1;
	struct Node *tmp;

	if (head == NULL)
	{
		return NULL;
	}
	if(pos < 1)
	{
		return *head1;
	}
	if (pos == 1)
	{
		tmp = head->next;
		free(head);
		head = NULL;
		return tmp;
	}
	head->next = del_ith_pos_recursive(&(head->next), pos-1);
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
	head = r(head, 3);	
	head = r(head, 4);	
	head = r(head, 5);	
	head = r(head, 2);	
	head = r(head, 6);	
	head = r(head, 1);	
	head = r(head, 9);	
	head = r(head, -1);	
	printList(head);
	head = del_ith_pos_recursive(&head, 8);
	printList(head);
	return 0; 
} 

