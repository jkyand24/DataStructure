#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

typedef struct node NODE;

NODE* insert_after(NODE* start) {
	NODE* new_node, * ptr, * preptr;
	int num, val;

	printf("\nEnter the data: ");
	scanf_s("%d", &num);
	printf("\nEnter the value after which the data is inserted: ");
	scanf_s("%d", &val);

	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = num;

	ptr = start;
	preptr = ptr;

	while(preptr -> data != val) {
		preptr = ptr;
		ptr = ptr->next;
	}

	preptr->next = new_node;
	new_node->next = ptr;

	return start;
}

NODE* delete_after(NODE* start) {
	NODE* ptr, * preptr;
	int val;

	printf("\nEnter the value after which the node is will be deleted: ");
	scanf_s("%d", &val);

	ptr = start;
	preptr = ptr;

	while(preptr->data != val) {
		preptr = ptr;
		ptr = ptr->next;
	}

	preptr->next = ptr->next;
	free(ptr);

	return start;
}

int main6_26() {
	NODE* head = malloc(sizeof(NODE));

	NODE* node1 = malloc(sizeof(NODE));
	head->next = node1;
	node1->data = 10;

	NODE* node2 = malloc(sizeof(NODE));
	node1->next = node2;
	node2->data = 20;

	node2->next = NULL;

	insert_after(head);
	delete_after(head);

	NODE* curr = head->next;
	while (curr != NULL) {
		printf("%d \n", curr->data);
		curr = curr->next;
	}

	return 0;
}