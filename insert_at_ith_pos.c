#include<stdio.h> 
#include<stdlib.h> 

/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 


struct Node *MY_HEAD, list;

struct Node * creat(int val)
{
        struct Node * tmp = malloc(sizeof(struct Node));
        if(tmp == NULL)
                return NULL;
        tmp->next = NULL;
        tmp->data=val;
        return tmp;
}


int ins_at_ith_node(struct Node *head, int pos, int val)
{
	struct Node *tmp =head;
	struct Node *prev =NULL;
	int count =0;

	if(head== NULL)
	{
		head=creat(val);
		return 0;
	}
	/* As soon as the pos found in the Linklist, insert the node */
	while(tmp != NULL)
	{
		prev = tmp;
		tmp=tmp->next;
		++count;
		if(count == pos)
		{
			prev->next = creat(val);
			prev->next->next = tmp;
			return 0;
		}
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
	pos = 24;
	if((ins_at_ith_node(head,pos, 88) <0 ))
		printf("position not present in lisklist\n");
	printList(head);

	return 0; 
} 

