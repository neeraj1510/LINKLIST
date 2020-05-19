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

struct Node * rev(struct Node *head)
{
	struct Node *curr = head;
	struct Node *fast = head;
	struct Node *prev = NULL;
	while(curr != NULL)
	{
		fast = curr->next;
		curr->next = prev;
		prev = curr;
		curr = fast;
	}
	return prev;
}

struct Node * rev_recc(struct Node *head)
{
	if(head->next == NULL)
	{
		return head;
	}
	struct Node *node = rev_recc(head->next);
	head->next->next = head;
	head->next = NULL;
	return node;
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
	printList(head);
	/* recursive */
	head = rev_recc(head);
	printList(head);
	/* Iterative */
	head = rev(head);
	printList(head);
	return 0; 
} 

