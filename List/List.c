#include <stdio.h>
#include <stdlib.h>

// ��� ����ü

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} NODE;

// ����Ʈ ���� ��� �Լ�

int ListLength(NODE* head) {
    int length = 0;
    NODE* current = head;

    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

// ��� ���� �Լ�

NODE* CreateNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE)); // �� ����� �޸𸮸� ���� �Ҵ�

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// ��� Insert �Լ�

void InsertNode(NODE** head, int data, int position) {
    // �����Ϸ��� position�� ���� ����Ʈ ���̸� �ʰ��ϴ� ��� ���� ���

    int length = ListLength(*head);

    if (position > length) {
        printf("�����Ϸ��� ��ġ�� ����Ʈ ���� ���Դϴ�.\n");
        return;
    }

    // NODE ����

    NODE* newNode = CreateNode(data);

    if (*head == NULL || position == 0) { // ����Ʈ�� ����ְų�, ù ��° ��ġ�� �����ϴ� ���
        if (*head != NULL) {
            newNode->next = *head; // �� NODE�� ���� NODE�� ���� head�� ����
            (*head)->prev = newNode; // ���� head�� ���� NODE�� �� NODE�� ����
        }
        *head = newNode; // �� NODE�� ���ο� head�� ����
        
        return;
    }

    NODE* temp = *head;

    for (int i = 0; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next; // newNode�� temp�� ���� NODE ����Ŵ
    newNode->prev = temp;

    if (temp->next != NULL) { // temp�� ������ NODE�� �ƴ� ��
        temp->next->prev = newNode;
    }

    temp->next = newNode; // �� NODE ���Ե�
}

// ��� Delete �Լ�

void DeleteNode(NODE** head, int position) {
    // ����Ʈ�� ����ִ� ��� ���� ����

    if (*head == NULL) {
        printf("����Ʈ�� ��������Ƿ�, Delete�� �� �����ϴ�");

        return;
    }

    // ��� ����

    NODE* temp = *head;

    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return; // position�� �ش��ϴ� NODE�� �������� ����

    if (temp->prev != NULL) { // ù ��°�� �ƴ� NODE ����
        temp->prev->next = temp->next;
    }
    else { // ù ��° NODE ����
        *head = temp->next;
    }

    if (temp->next != NULL) { // ������ NODE�� ���� NODE ó��
        temp->next->prev = temp->prev;
    }

    free(temp); // �޸� ����
}

// ����Ʈ ���

void PrintList(NODE* head) {
    if (head == NULL) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");

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

    InsertNode(&head, 10, 0); // ����Ʈ�� 10 ����
    InsertNode(&head, 20, 1); // ����Ʈ�� 20 ����
    InsertNode(&head, 30, 2); // ����Ʈ�� 30 ����
    InsertNode(&head, 40, 3); // ����Ʈ�� 40 ����

    InsertNode(&head, 100, 2); // ����Ʈ�� 100 ����

    DeleteNode(&head, 1);     // �� ��° ��� ����

    PrintList(head);

    return 0;
}