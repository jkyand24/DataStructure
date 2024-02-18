#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // ť�� �ִ� ũ�� ����

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// ť �ʱ�ȭ �Լ�
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// ť�� ��� �ִ��� Ȯ���ϴ� �Լ�
int isEmpty(Queue* q) {
    return q->front == -1;
}

// ť�� ���� á���� Ȯ���ϴ� �Լ�
int isFull(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// ť�� ���� ���� �Լ�
void insert(Queue* q, int element) {
    if (isFull(q)) {
        printf("Queue is full.\n");
    }
    else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->items[q->rear] = element;
    }
}

// ť���� ���� ���� �Լ�
int delete(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    else {
        int data = q->items[q->front];
        if (q->front == q->rear) {  // ť�� �ϳ��� ���Ҹ� �ִ� ���
            initializeQueue(q);     // ť�� �ʱ�ȭ
        }
        else {
            q->front = (q->front + 1) % MAX_SIZE;
        }
        return data;
    }
}

// ť�� ������ ����ϴ� �Լ�
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue: ");
        for (int i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", q->items[i]);
        }
        printf("%d\n", q->items[q->rear]);
    }
}

int main() {
    Queue q;
    initializeQueue(&q);

    insert(&q, 10);
    insert(&q, 20);
    insert(&q, 30);

    printQueue(&q);

    printf("Deleted element: %d\n", delete(&q));
    printf("Deleted element: %d\n", delete(&q));

    printQueue(&q);

    return 0;
}
