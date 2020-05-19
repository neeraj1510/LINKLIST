#include<stdio.h> 
#include<stdlib.h> 

/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 


struct Node *MY_HEAD, list;


/* Function to get the middle of the linked list*/
void printMiddle(struct Node *head) 
{ 
	struct Node *slow_ptr = head; 
	struct Node *fast_ptr = head; 

	if (head!=NULL) 
	{ 
		while (fast_ptr != NULL && fast_ptr->next != NULL) 
		{ 
			fast_ptr = fast_ptr->next->next; 
			slow_ptr = slow_ptr->next; 
		} 
		printf("The middle element is [%d]\n\n", slow_ptr->data); 
	} 
} 
/* Print length of LL recursive*/
int length_ll(struct Node *head)
{
	if(head== NULL)
		return 0;

	return (1+length_ll(head->next));

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
/* Insert node at end*/

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
/*merge two linklist*/
struct Node * merge(struct Node *list1, struct Node *list2, int len1, int len2)
{
	struct Node *tmp = NULL,*list3 = NULL, *list;
	if((list1 == NULL) || (list2 == NULL))
		return NULL;

	while(list1 !=NULL && list2 != NULL)
	{

		if(list1->data < list2->data)
		{
			tmp = creat(list1->data); 
			len1--;
			list1=list1->next;
		}
		else
		{
			tmp = creat(list2->data); 
			len2--;
			list2=list2->next;
		}
		if(list3==NULL)
		{
			list3 = tmp;
			list=list3;
		}
		else
		{
			list3->next = tmp;
			list3=list3->next;
		}

	}
	while(len1>len2)
	{
		list3->next = creat(list1->data);
		list3=list3->next;
		list1=list1->next;
		len1--;
	}
	while(len2>len1)
	{
		list3->next = creat(list2->data);
		list3=list3->next;
		list2=list2->next;
		len2--;
	}
	return list;
}
/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head1 = NULL; 
	struct Node* head2 = NULL; 
	struct Node* head3 = NULL; 
	int l1, l2; 
	head1 = r(head1, 1);	
	head1 = r(head1, 3);	
	head1 = r(head1, 5);	
	head1 = r(head1, 7);	
	head1 = r(head1, 7);	
	head1 = r(head1, 7);	
	head1 = r(head1, 17);	
	printf("LL 1 : ");
	printList(head1);
	head2 = r(head2, 2);	
	head2 = r(head2, 4);	
	head2 = r(head2, 6);
	head2 = r(head2, 8);
	head2 = r(head2, 10);
	head2 = r(head2, 12);
	printf("LL 2 : ");
	printList(head2);
	l1 = length_ll(head1);
	l2 = length_ll(head2);
	printf("l1 = %d l2 = %d\n", l1, l2);
	head3=merge(head1, head2, l1, l2);
	printf(">l1 = %d l2 = %d\n", l1, l2);
	printList(head3);
	return 0; 
} 

