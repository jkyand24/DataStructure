#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void InsertElement() {
	int num;
	printf("\n큐에 삽입될 숫자를 입력하세요: ");
	scanf_s("%d", &num);

	if (rear == MAX - 1) {
		printf("\nOVERFLOW");
		
		return;
	}
	else if (front == -1 && rear == -1) {
		front = rear = 0;
	}
	else {
		rear++;
	}

	queue[rear] = num;
}

int DeleteElement() {
	int val;

	if (front == -1 && rear == -1) {
		printf("\nUNDERFLOW");

		return -1;
	}
	else {
		val = queue[front];
		front++;
		if (front > rear) {
			front = rear = -1;
		}

		return val;
	}
}

void Display() {
	int i;
	printf("\n\n");

	if (front == -1 && rear == -1) {
		printf("\nQUEUE IS EMPTY");
	}
	else {
		for (i = front; i <= rear; i++) {
			printf("Queue[%d]: %d \t", i, queue[i]);
		}
	}
}

int main8_ArrayQueue() {
	int val;

	InsertElement();
	InsertElement();
	InsertElement();

	val = DeleteElement();

	if (val != -1) {
		printf("삭제된 숫자는: %d", val);
	}
	Display();

	return 0;
}