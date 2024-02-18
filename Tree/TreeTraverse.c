#include <stdio.h>
#include <malloc.h>

struct node {
	struct node* left;
	int data;
	struct node* right;
};

typedef struct node NODE;

NODE* CreateNode(int data) {
	NODE* n;

	n = (NODE*)malloc(sizeof(NODE));

	n->left = NULL;
	n->data = data;
	n->right = NULL;

	return n;
}

void Preorder(NODE* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		Preorder(root->left);
		Preorder(root->right);
	}
}

void Postorder(NODE* root) {
	if (root != NULL) {
		Postorder(root->left);
		Postorder(root->right);
		printf("%d ", root->data);
	}
}

void Inorder(NODE* root) {
	if (root != NULL) {
		Inorder(root->left);
		printf("%d ", root->data);
		Inorder(root->right);
	}
}

int main9() {
	NODE* node1 = CreateNode(4);
	NODE* node2 = CreateNode(1);
	NODE* node3 = CreateNode(6);
	NODE* node4 = CreateNode(5);
	NODE* node5 = CreateNode(2);

	node1->left = node2;
	node1->right = node3;

	node2->left = node4;
	node2->right = node5;

	Preorder(node1);
	printf("\n\n");
	Postorder(node1);
	printf("\n\n");
	Inorder(node1);

	return 0;
}