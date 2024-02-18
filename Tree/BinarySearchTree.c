#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left, * right;
};

typedef struct node NODE;

// 새 노드 만드는 함수

NODE* CreateNode(int val) {
	NODE* p_node = (NODE*)malloc(sizeof(NODE));

	p_node->data = val;
	p_node->left = p_node->right = NULL;

	return p_node;
}

// In Order Traverse하는 함수

void TraverseInOrder(NODE* p_root) {
	if (p_root != NULL) {
		TraverseInOrder(p_root->left);
		printf("%d ", p_root->data);
		TraverseInOrder(p_root->right);
	}
}

// 노드 삽입하는 함수

NODE* InsertNode(NODE* p_node, int val) {
	// 현재 node가 비어있는 경우: 이 위치에 Insert

	if (p_node == NULL)
		return CreateNode(val);

	// 현재 node에 이미 값이 있는 경우: 재귀적 함수 호출을 통해 더 탐색해야 함

	if (val < p_node->data)
		p_node->left = InsertNode(p_node->left, val); 
	else if (val > p_node->data)
		p_node->right = InsertNode(p_node->right, val);

	return p_node;
}

// 노드 삭제하는 함수

NODE* DeleteNode(NODE* p_node, int val) {
    // 현재 노드가 비어있는 경우

    if (p_node == NULL)
        return p_node;

    // 현재 노드가 비어있지 않은 경우
    
    //// 아직 삭제할 노드에 도달하지 못한 경우: 함수의 재귀적 호출

    if (p_node->data > val) {
        p_node->left = DeleteNode(p_node->left, val);
        return p_node;
    }
    else if (p_node->data < val) {
        p_node->right = DeleteNode(p_node->right, val);
        return p_node;
    }

    //// 현재 노드가 삭제할 노드인 경우

    ////// child 0개인 경우 

    if (p_node->left == NULL && p_node->right == NULL) {
        free(p_node);

        return;
    }

    ////// child 1개 @ 오른쪽인 경우

    else if (p_node->left == NULL) {
        NODE* temp = p_node->right;
        free(p_node);

        return temp;
    }

    ////// child 1개 @ 왼쪽인 경우

    else if (p_node->right == NULL) {
        NODE* temp = p_node->left;
        free(p_node);

        return temp;
    }

    ////// child 2개인 경우
    /* p_smallest_node: p_node의 오른쪽 subtree에서 가장 작은 노드.
    이것의 data를 p_node에 옮긴 뒤,
    이것을 트리 상에서 쫓아낸다. */

    else {
        /* p_node의 오른쪽 subtree에서 가장 작은 값을 찾으려 한다.
        우선 p_node의 오른쪽 node에서부터 시작한다.
        (추후 p_smallest_node의 자손을 p_smallest_node의 부모와 이어야 하기에,
        p_smallest_node의 부모도 p_smallest_node_parent로써 저장한다.) */

        NODE* p_smallest_node = p_node->right;
        NODE* p_smallest_node_parent = p_node; 

        while (p_smallest_node->left != NULL) {
            p_smallest_node_parent = p_smallest_node;
            p_smallest_node = p_smallest_node->left;
        }

        // p_smallest_node_parent는 p_smallest_node를 버리고 손자와 연결된다.

        if (p_smallest_node_parent != p_node)
            p_smallest_node_parent->left = p_smallest_node->right;
        else
            p_smallest_node_parent->right = p_smallest_node->right;

        // p_smallest_node_parent는 p_smallest_node의 data를 가져온다.

        p_node->data = p_smallest_node->data;

        // p_smallest_node는 버려진다.

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

    printf("\n\n1-2. 11 삭제\n");

    p_root = DeleteNode(p_root, 11);

    TraverseInOrder(p_root);

    printf("\n\n1-3. 12 추가\n");

    p_root = InsertNode(p_root, 12);

    TraverseInOrder(p_root);

    return 0;
}