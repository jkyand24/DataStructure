#include <stdio.h>
#include <stdlib.h>

// ��� ����ü 

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} NODE;

// ��� ���� �Լ�

NODE* CreateNodeCir(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));

    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;

    return newNode;
}

// ����Ʈ ���� ��� �Լ�

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

// ��� Insert �Լ�

void InsertNodeCir(NODE** head, int data, int position) {
    // �����Ϸ��� position�� ���� ����Ʈ ���̸� �ʰ��ϴ� ��� ���� ���

    int length = ListLengthCir(*head);

    if (position > length) {
        printf("�����Ϸ��� ��ġ�� ����Ʈ ���� ���Դϴ�.\n");

        return;
    }

    // �� NODE ����

    NODE* newNode = CreateNodeCir(data);

    if (*head == NULL) {
        *head = newNode;

        return;
    }

    // ����Ʈ�� ������ NODE ã��

    NODE* last = *head;

    while (last->next != *head) {
        last = last->next;
    }

    // �� NODE ����

    if (position == 0) { // ù ��° ��ġ�� �����ϴ� ���
        newNode->next = *head;
        newNode->prev = last;
        (*head)->prev = newNode;
        last->next = newNode;
        *head = newNode; // �� ��带 ���ο� ���� ���� ����
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


// ��� Delete �Լ�

void DeleteNodeCir(NODE** head, int position) {
    // ����Ʈ�� ����ִ� ��� ���� ����

    if (*head == NULL) { 
        printf("����Ʈ�� ��������Ƿ�, Delete�� �� �����ϴ�");

        return;
    }

    // ����Ʈ�� �� �ϳ��� NODE�� �ִ� ���

    if ((*head)->next == *head && position == 0) { 
        free(*head);
        *head = NULL;

        return;
    }

    // NODE ����

    NODE* temp = *head;

    for (int i = 0; i < position; i++) {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (position == 0) *head = temp->next;

    free(temp);
}

// ����Ʈ ���

void PrintListCir(NODE* head) {
    if (head == NULL) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");

        return;
    }

    NODE* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } 
    while (temp != head); // ���� ���� ���ƿ��� ����

    printf("\n");
}

// main

int main() {
    NODE* head = NULL;

    InsertNodeCir(&head, 10, 0); // ����Ʈ�� 10 ����
    InsertNodeCir(&head, 20, 1); // ����Ʈ�� 20 ����
    InsertNodeCir(&head, 30, 2); // ����Ʈ�� 30 ����
    InsertNodeCir(&head, 40, 3); // ����Ʈ�� 40 ����

    InsertNodeCir(&head, 100, 2); // ����Ʈ�� 100 ����

    DeleteNodeCir(&head, 1);     // �� ��° ��� ����

    PrintListCir(head);

    return 0;
}
