#include <stdio.h>
#include <stdlib.h>

// 노드 구조체

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} NODE;

// 리스트 길이 계산 함수

int ListLength(NODE* head) {
    int length = 0;
    NODE* current = head;

    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

// 노드 생성 함수

NODE* CreateNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE)); // 새 노드의 메모리를 동적 할당

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// 노드 Insert 함수

void InsertNode(NODE** head, int data, int position) {
    // 삽입하려는 position이 현재 리스트 길이를 초과하는 경우 에러 출력

    int length = ListLength(*head);

    if (position > length) {
        printf("삽입하려는 위치가 리스트 길이 밖입니다.\n");
        return;
    }

    // NODE 삽입

    NODE* newNode = CreateNode(data);

    if (*head == NULL || position == 0) { // 리스트가 비어있거나, 첫 번째 위치에 삽입하는 경우
        if (*head != NULL) {
            newNode->next = *head; // 새 NODE의 다음 NODE를 현재 head로 설정
            (*head)->prev = newNode; // 현재 head의 이전 NODE를 새 NODE로 설정
        }
        *head = newNode; // 새 NODE를 새로운 head로 설정
        
        return;
    }

    NODE* temp = *head;

    for (int i = 0; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next; // newNode가 temp의 다음 NODE 가리킴
    newNode->prev = temp;

    if (temp->next != NULL) { // temp가 마지막 NODE가 아닐 때
        temp->next->prev = newNode;
    }

    temp->next = newNode; // 새 NODE 삽입됨
}

// 노드 Delete 함수

void DeleteNode(NODE** head, int position) {
    // 리스트가 비어있는 경우 에러 생성

    if (*head == NULL) {
        printf("리스트가 비어있으므로, Delete할 수 없습니다");

        return;
    }

    // 노드 삭제

    NODE* temp = *head;

    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return; // position에 해당하는 NODE가 존재하지 않음

    if (temp->prev != NULL) { // 첫 번째가 아닌 NODE 삭제
        temp->prev->next = temp->next;
    }
    else { // 첫 번째 NODE 삭제
        *head = temp->next;
    }

    if (temp->next != NULL) { // 삭제할 NODE의 다음 NODE 처리
        temp->next->prev = temp->prev;
    }

    free(temp); // 메모리 해제
}

// 리스트 출력

void PrintList(NODE* head) {
    if (head == NULL) {
        printf("리스트가 비어있습니다.\n");

        return;
    }

    NODE* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// main

int main2() {
    NODE* head = NULL;

    InsertNode(&head, 10, 0); // 리스트에 10 삽입
    InsertNode(&head, 20, 1); // 리스트에 20 삽입
    InsertNode(&head, 30, 2); // 리스트에 30 삽입
    InsertNode(&head, 40, 3); // 리스트에 40 삽입

    InsertNode(&head, 100, 2); // 리스트에 100 삽입

    DeleteNode(&head, 1);     // 두 번째 노드 삭제

    PrintList(head);

    return 0;
}