#include<stdio.h>

// Type declarations for linked list

typedef struct node *note_ptr;
struct node
{
	int element;
	node_ptr next;
}

typedef node_ptr LIST;
typedef node_ptr position;

/* function to test whether linked list is empty */

int is_empty(LIST L)
{
	return (L->next == NULL);
}


/* Function to test whether current position is the last in a linked list */

int is_last(postion p, LIST L)
{
	return (p->next == NULL);
}

/* Return position of x in L; NULL if not found */

position find(int x, LIST L)
{
	position p;
	p = L->next;
	while((p != NULL)&&(p->element != x))
		p = p->next;
	return p;	
}

/* Function to Delete first occurance of element x in LIST */

void delete(int x, LIST L)
{
	position p,temp;
	p=find_previous(x, LIST L);
	if(p->next != NULL){
		temp=p->next;
		p->next=tempt->next;
		free(temp);
	}
}

/* Function to find position of previous node for a element x */

position find_previous(int x,LIST L)
{
	position p, temp;
	p = L->next;
	while((p->next != NULL)&&(p->element != x)) p = p->next;
	return p;
}

/* Insertion Routine for Linked List*/
void insert(int x, LIST L, position p)
{
	position temp_cell;
	temp_cell = (position) malloc(sizeof(struct node));
	if(temp_cell == NULL) printf("OUT OF SPACE!!");
	else
	{
		temp_cell->element = x;
		temp_cell->next = p->next;
		p->next=temp_cell;
	}
}

/*Function to delete List*/

void delete_list(LIST L)
{
position p;
	p=p->next;
	L->next = NULL;
	while(p!=NULL){
		temp=p->next;
		free(p);		
		p=temp;
	}
}

int main(){

}
