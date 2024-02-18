#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

typedef struct node NODE;

int main6_6() {
	NODE* head = malloc(sizeof(NODE));

	NODE* node1 = malloc(sizeof(NODE));
	head->next = node1;
	node1->data = 10;

	NODE* node2 = malloc(sizeof(NODE));
	node1->next = node2;
	node2->data = 20;
	
	node2->next = NULL;

	NODE* curr = head->next;
	while(curr != NULL) {
		printf("%d \n", curr->data);
		curr = curr->next;
	}
	
	free(node2);
	free(node1);
	free(head);

	return 0;
}