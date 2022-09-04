#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)

typedef struct node {
	int elem;
	struct node *left, *right;
}node;

node *getnode() {
	node *newnode = (node *)malloc(sizeof(node));

	if (newnode == NULL)
		return -1;
	newnode->left = newnode->right = NULL;
	return newnode;
}
int putnode(node *p) {
	int e = p->elem;
	free(p);

	return e;
}
node *leftChild(node *p) {
	if (p->left != NULL)
		return p->left;
	return NULL;
}
node *rightChild(node *p) {
	if (p->right != NULL)
		return p->right;
	return NULL;
}

void preOrder(node *p) {
	int x, y, z;
	//visit
	scanf("%d %d %d", &x, &y, &z);
	p->elem = x;

	if (y != 0) {
		p->left = getnode();
		preOrder(leftChild(p));
	}
	if (z != 0) {
		p->right = getnode();
		preOrder(rightChild(p));
	}
}


int main() {
	node *root = getnode(), *p;
	char str[101], ch;
	int n, i, idx;

	scanf("%d", &n);
	preOrder(root);

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", str);
		idx = 0;
		p = root;
		printf(" %d", p->elem);
		while (*(str + idx) != NULL) {
			ch = *(str + idx++);
			
			p = (ch == 'L') ? leftChild(p) : rightChild(p);
			printf(" %d", p->elem);
		}
		printf("\n");
	}

	return 0;

}

