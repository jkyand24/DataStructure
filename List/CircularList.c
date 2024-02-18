#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} NODE;

// 노드 생성 함수

NODE* CreateNodeCir(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));

    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;

    return newNode;
}

// 리스트 길이 계산 함수

int ListLengthCir(NODE* head) {
    int length = 0;
    NODE* current = head;

    if (current != NULL) {
        do {
            length++;
            current = current->next;
        } 
        while (current != head);
    }

    return length;
}

// 노드 Insert 함수

void InsertNodeCir(NODE** head, int data, int position) {
    // 삽입하려는 position이 현재 리스트 길이를 초과하는 경우 에러 출력

    int length = ListLengthCir(*head);

    if (position > length) {
        printf("삽입하려는 위치가 리스트 길이 밖입니다.\n");

        return;
    }

    // 새 NODE 생성

    NODE* newNode = CreateNodeCir(data);

    if (*head == NULL) {
        *head = newNode;

        return;
    }

    // 리스트의 마지막 NODE 찾기

    NODE* last = *head;

    while (last->next != *head) {
        last = last->next;
    }

    // 새 NODE 삽입

    if (position == 0) { // 첫 번째 위치에 삽입하는 경우
        newNode->next = *head;
        newNode->prev = last;
        (*head)->prev = newNode;
        last->next = newNode;
        *head = newNode; // 새 노드를 새로운 시작 노드로 설정
    }
    else {
        NODE* temp = *head;

        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}


// 노드 Delete 함수

void DeleteNodeCir(NODE** head, int position) {
    // 리스트가 비어있는 경우 에러 생성

    if (*head == NULL) { 
        printf("리스트가 비어있으므로, Delete할 수 없습니다");

        return;
    }

    // 리스트에 단 하나의 NODE만 있는 경우

    if ((*head)->next == *head && position == 0) { 
        free(*head);
        *head = NULL;

        return;
    }

    // NODE 삭제

    NODE* temp = *head;

    for (int i = 0; i < position; i++) {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (position == 0) *head = temp->next;

    free(temp);
}

// 리스트 출력

void PrintListCir(NODE* head) {
    if (head == NULL) {
        printf("리스트가 비어있습니다.\n");

        return;
    }

    NODE* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } 
    while (temp != head); // 시작 노드로 돌아오면 종료

    printf("\n");
}

// main

int main() {
    NODE* head = NULL;

    InsertNodeCir(&head, 10, 0); // 리스트에 10 삽입
    InsertNodeCir(&head, 20, 1); // 리스트에 20 삽입
    InsertNodeCir(&head, 30, 2); // 리스트에 30 삽입
    InsertNodeCir(&head, 40, 3); // 리스트에 40 삽입

    InsertNodeCir(&head, 100, 2); // 리스트에 100 삽입

    DeleteNodeCir(&head, 1);     // 두 번째 노드 삭제

    PrintListCir(head);

    return 0;
}
