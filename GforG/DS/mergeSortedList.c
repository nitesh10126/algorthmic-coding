#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
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

void printList(struct node* iter){
	if(iter == NULL){
		printf("List is empty.");
		return;	
	}
	while(iter != NULL) {
		printf("%d ",iter->item);
		iter = iter->next; 
	}
}
void moveNode(struct node** destRef, struct node** sourceRef){
	struct node* newNode = *sourceRef;
	assert(newNode != NULL);
	*sourceRef = newNode->next;
	newNode->next = NULL;// newNode->next = *destRef;
	*destRef = newNode;
}

struct node* mergeSortedList(struct node* a, struct node* b){
	if(a==NULL)return b;
	if(b==NULL)return a;
	struct node dummy;
	struct node* tail = &dummy;
	dummy.next = NULL;
	while(1){
		if(a == NULL){
			tail->next = b; break;
		}
		else if(b == NULL){
			tail->next = a; break;
		}
		if(a->item <= b->item)
			moveNode(&(tail->next),&a);
		else
			moveNode(&(tail->next),&b);
		tail = tail->next;	
	}	
	return dummy.next;	
}

int main(){
struct node* head1 = NULL;
struct node* head2 = NULL;
push(&head1,20);
push(&head1,11);
push(&head1,7);
push(&head1,1);
printList(head1);printf("\n");
push(&head2,17);
push(&head2,12);
push(&head2,9);
push(&head2,6);
printList(head2);printf("\n");
struct node* head3 = mergeSortedList(head1,head2);
printList(head3);
return 0;
}
