#include<stdio.h> 
#include<stdlib.h> 

/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 


struct Node *MY_HEAD, list;
/* LL enter with NULL */
void showll(struct Node *head) 
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
/* Remove Dulpicate node using Hashing*/
struct Node * hash_rem_dup(struct Node *head)
{
	int flag = 0;
	struct Node *hash = malloc(sizeof(struct Node));
	if(hash == NULL)
	{
		return NULL;
	}
	hash->data = head->data;
	hash->next = NULL;
	head=head->next;
	struct Node *tmp = hash;
	struct Node *slow = hash;
	while(head->data !=-1)
	{
		flag = 0;
		while(hash != NULL)
		{
			if(head->data == hash->data)
			{
				flag =0;
				break;
			}
			else
				flag = 1;
				slow = hash;
				hash=hash->next;
		}
		if(flag == 1)
		{
			slow->next = creat(head->data);
		}
		hash=tmp;
		head = head->next;
	}
	hash=tmp;
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
	head = r(head, 1);	
	head = r(head, 1);	
	head = r(head, 1);	
	head = r(head, 2);	
	head = r(head, 3);	
	head = r(head, 0);	
	head = r(head, 5);	
	head = r(head, 4);	
	head = r(head, 5);	
	head = r(head, 5);	
	head = r(head, 2);	
	head = r(head, -1);	
	printList(head);
	/* linklist is unsorted */
	/* Hashing*/
	printf("Hashing method\n");
	head = hash_rem_dup(head);
	showll(head);
	return 0; 
} 

