#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // 큐의 최대 크기 정의

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// 큐 초기화 함수
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// 큐가 비어 있는지 확인하는 함수
int isEmpty(Queue* q) {
    return q->front == -1;
}

// 큐가 가득 찼는지 확인하는 함수
int isFull(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// 큐에 원소 삽입 함수
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

// 큐에서 원소 삭제 함수
int delete(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    else {
        int data = q->items[q->front];
        if (q->front == q->rear) {  // 큐에 하나의 원소만 있는 경우
            initializeQueue(q);     // 큐를 초기화
        }
        else {
            q->front = (q->front + 1) % MAX_SIZE;
        }
        return data;
    }
}

// 큐의 내용을 출력하는 함수
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
