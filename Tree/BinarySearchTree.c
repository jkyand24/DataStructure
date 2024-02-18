#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left, * right;
};

typedef struct node NODE;

// �� ��� ����� �Լ�

NODE* CreateNode(int val) {
	NODE* p_node = (NODE*)malloc(sizeof(NODE));

	p_node->data = val;
	p_node->left = p_node->right = NULL;

	return p_node;
}

// In Order Traverse�ϴ� �Լ�

void TraverseInOrder(NODE* p_root) {
	if (p_root != NULL) {
		TraverseInOrder(p_root->left);
		printf("%d ", p_root->data);
		TraverseInOrder(p_root->right);
	}
}

// ��� �����ϴ� �Լ�

NODE* InsertNode(NODE* p_node, int val) {
	// ���� node�� ����ִ� ���: �� ��ġ�� Insert

	if (p_node == NULL)
		return CreateNode(val);

	// ���� node�� �̹� ���� �ִ� ���: ����� �Լ� ȣ���� ���� �� Ž���ؾ� ��

	if (val < p_node->data)
		p_node->left = InsertNode(p_node->left, val); 
	else if (val > p_node->data)
		p_node->right = InsertNode(p_node->right, val);

	return p_node;
}

// ��� �����ϴ� �Լ�

NODE* DeleteNode(NODE* p_node, int val) {
    // ���� ��尡 ����ִ� ���

    if (p_node == NULL)
        return p_node;

    // ���� ��尡 ������� ���� ���
    
    //// ���� ������ ��忡 �������� ���� ���: �Լ��� ����� ȣ��

    if (p_node->data > val) {
        p_node->left = DeleteNode(p_node->left, val);
        return p_node;
    }
    else if (p_node->data < val) {
        p_node->right = DeleteNode(p_node->right, val);
        return p_node;
    }

    //// ���� ��尡 ������ ����� ���

    ////// child 0���� ��� 

    if (p_node->left == NULL && p_node->right == NULL) {
        free(p_node);

        return;
    }

    ////// child 1�� @ �������� ���

    else if (p_node->left == NULL) {
        NODE* temp = p_node->right;
        free(p_node);

        return temp;
    }

    ////// child 1�� @ ������ ���

    else if (p_node->right == NULL) {
        NODE* temp = p_node->left;
        free(p_node);

        return temp;
    }

    ////// child 2���� ���
    /* p_smallest_node: p_node�� ������ subtree���� ���� ���� ���.
    �̰��� data�� p_node�� �ű� ��,
    �̰��� Ʈ�� �󿡼� �ѾƳ���. */

    else {
        /* p_node�� ������ subtree���� ���� ���� ���� ã���� �Ѵ�.
        �켱 p_node�� ������ node�������� �����Ѵ�.
        (���� p_smallest_node�� �ڼ��� p_smallest_node�� �θ�� �̾�� �ϱ⿡,
        p_smallest_node�� �θ� p_smallest_node_parent�ν� �����Ѵ�.) */

        NODE* p_smallest_node = p_node->right;
        NODE* p_smallest_node_parent = p_node; 

        while (p_smallest_node->left != NULL) {
            p_smallest_node_parent = p_smallest_node;
            p_smallest_node = p_smallest_node->left;
        }

        // p_smallest_node_parent�� p_smallest_node�� ������ ���ڿ� ����ȴ�.

        if (p_smallest_node_parent != p_node)
            p_smallest_node_parent->left = p_smallest_node->right;
        else
            p_smallest_node_parent->right = p_smallest_node->right;

        // p_smallest_node_parent�� p_smallest_node�� data�� �����´�.

        p_node->data = p_smallest_node->data;

        // p_smallest_node�� ��������.

        free(p_smallest_node);

        return p_node;
    }
}

// main

int main() {
    NODE* p_root = NULL;

    printf("1-1.\n");

    p_root = InsertNode(p_root, 11);
    p_root = InsertNode(p_root, 6);
    p_root = InsertNode(p_root, 8);
    p_root = InsertNode(p_root, 19);
    p_root = InsertNode(p_root, 4);
    p_root = InsertNode(p_root, 10);
    p_root = InsertNode(p_root, 5);
    p_root = InsertNode(p_root, 17);
    p_root = InsertNode(p_root, 43);
    p_root = InsertNode(p_root, 49);
    p_root = InsertNode(p_root, 31);

    TraverseInOrder(p_root);

    printf("\n\n1-2. 11 ����\n");

    p_root = DeleteNode(p_root, 11);

    TraverseInOrder(p_root);

    printf("\n\n1-3. 12 �߰�\n");

    p_root = InsertNode(p_root, 12);

    TraverseInOrder(p_root);

    return 0;
}