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
int find_index(struct Node *head1, int val)
{
	static int count =0;
	
	if(head1 == NULL)
		return -1;
	if(head1->data == val)
	{
		return count;
	}
	count++;
	find_index(head1->next, val);
	return count;
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
	int res; 
	head = r(head, 3);	
	head = r(head, 4);	
	head = r(head, 5);	
	head = r(head, 2);	
	head = r(head, 6);	
	head = r(head, 1);	
	head = r(head, 9);	
	head = r(head, -1);	
	printList(head);
	res = find_index(head, 6);
	if(res ==  -1)
	{
		printf("Number not present\n");
	}
	else
	{
		printf("Number present at Index %d\n", res);
	}
	return 0; 
} 

