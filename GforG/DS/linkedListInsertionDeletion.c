#include<stdio.h>
#include<stdlib.h>

struct node{
	int item;
	struct node* next;
};

/* Given a reference (pointer to pointer) to the head of a list and 
   an int, inserts a new node on the front of the list. */
void push(struct node** head_ref, int new_data){
	struct node* new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->item = new_data;
	new_node->next = (*head_ref);
	*head_ref = new_node;
}

/* Given a node prev_node, insert a new node after the given 
   prev_node */
void insertAfter(struct node* prev_node, int new_data){
	if(prev_node == NULL){
		printf("prev_node can't be NULL.");
		return;
	}
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->item = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(struct node** header_ref, int new_data){
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->item = new_data;
	new_node->next = NULL;
	struct node* last = *header_ref;
	if(*header_ref == NULL){
		*header_ref = new_node;
		return;
	}
	while(last->next != NULL){
		last = last->next;
	}
	last->next = new_node;
	return;
}

/* Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
void delete(struct node** header_ref, int key){
	struct node* temp = *header_ref;
	struct node* prev_node;
	if(temp != NULL && temp->item == key){
		*header_ref = temp->next;
		free(temp);
		return;
	}

	while((temp != NULL) && (temp->item != key)){ // clever use of shortcircuit operation
		prev_node = temp;
		temp = temp->next;
	}
	if(temp == NULL){
	printf("\nKey is not there in List!\n");
	return;
	}
	prev_node->next = temp->next;
	free(temp);
}

/* Given a reference (pointer to pointer) to the head of a list
   and a position, deletes the node at the given position */

void deleteNode(struct node** header_ref, int position){
	if(*header_ref == NULL)return;
	struct node* temp = *header_ref;
	int i;
	for(i=0;temp!=NULL && i<position-1;i++)temp=temp->next;

	if (temp == NULL || temp->next == NULL)
         return;
	
	struct Node *next = (temp->next)->next;
	
	free(temp->next);
	temp->next=next;
}

void printList(struct node* iter){
	while(iter != NULL) {
		printf("%d",iter->item);
		iter = iter->next; 
	}
}

/* This function counts the total nodes and returns it.*/
int countNode(struct node* header){
	int count = 0;
	while(header != NULL){
		count++;
		header=header->next;
	}
	return count;
}

/* Function to swap nodes x and y in linked list by
   changing links */
void swapNodes(struct node **head_ref, int x, int y)
{
   // Nothing to do if x and y are same
   if (x == y) return;
 
   // Search for x (keep track of prevX and CurrX
   struct node *prevX = NULL, *currX = *head_ref;
   while (currX && currX->item != x)
   {
       prevX = currX;
       currX = currX->next;
   }
 
   // Search for y (keep track of prevY and CurrY
   struct node *prevY = NULL, *currY = *head_ref;
   while (currY && currY->item != y)
   {
       prevY = currY;
       currY = currY->next;
   }
 
   // If either x or y is not present, nothing to do
   if (currX == NULL || currY == NULL)
       return;
 
   // If x is not head of linked list
   if (prevX != NULL)
       prevX->next = currY;
   else // Else make y as new head
       *head_ref = currY;  
 
   // If y is not head of linked list
   if (prevY != NULL)
       prevY->next = currX;
   else  // Else make x as new head
       *head_ref = currX;
 
   // Swap next pointers
   struct node *temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
}
/* Function to reverse the linked list */
void reverse(struct node** head_ref){
	struct node* prev = NULL;	// Initialize with NULL **IMP
	struct node* current = *head_ref;
	struct node* next;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

int main(){
struct node* head = NULL;
push(&head,1);
push(&head,2);
push(&head,3);
push(&head,4);
printList(head);printf("\n");
append(&head,5),append(&head,6),append(&head,7);
printList(head);printf("\n");
delete(&head,3),delete(&head,3),delete(&head,5);
printList(head);printf("\n");
deleteNode(&head,3);
printList(head);
printf("\n");
printf("%d\n",countNode(head));
swapNodes(&head,4,7);
printList(head);
reverse(&head);printf("\n");
printList(head);
return 0;
}
