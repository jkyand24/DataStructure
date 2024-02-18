#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node* next;
};

struct queue {
	struct node* front, * rear;
};

typedef struct node NODE;

typedef struct queue QUEUE;

NODE* CreateNode2(int k) {
	NODE* temp = (NODE*)malloc(sizeof(NODE));

	temp->key = k;
	temp->next = NULL;

	return temp;
}

QUEUE* CreateQueue() {
	QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));

	q->front = q->rear = NULL;

	return q;
}

void EnQueue(QUEUE* q, int k) {
	NODE* temp = CreateNode2(k);

	if (q->rear == NULL) {
		q->front = q->rear = temp;
		
		return;
	}

	q->rear->next = temp;
	q->rear = temp;
}

void DeQueue(QUEUE* q) {
	if (q->front == NULL) {
		printf("UNDERFLOW");

		return;
	}

	NODE* temp = q->front;

	q->front = q->front->next;

	if (q->front == NULL) {
		q->rear = NULL;
	}

	free(temp);
}

int main8_LinkedQueue() {
	QUEUE* q = CreateQueue();

	EnQueue(q, 10);
	EnQueue(q, 20);
	DeQueue(q);
	DeQueue(q);
	EnQueue(q, 30);
	EnQueue(q, 40);
	EnQueue(q, 50);
	DeQueue(q);

	printf("Queue's front: %d\n", ((q->front != NULL)? (q->front->key) : -1));
	printf("Queue's rear: %d", ((q->rear != NULL)? (q->rear->key) : -1));

	return 0;
}