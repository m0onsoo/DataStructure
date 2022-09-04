#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)

typedef struct node {
	char elem;
	int n;
	struct node *prev, *next;
}node;

node *getnode() {
	node *newnode = (node *)malloc(sizeof(node));

	if (newnode == NULL)
		return -1;
	newnode->prev = newnode->next = NULL;
	return newnode;
}
char putnode(node *p) {
	char e = p->elem;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);

	return e;
}
void initList(node *header, node *trailer) {
	header->next = trailer;
	trailer->prev = header;
	header->n = 0;
}

void invalid() {
	printf("invalid position\n");
}
void addNodeBefore(node *p, char e) {
	node *newnode = getnode();

	newnode->elem = e;
	newnode->prev = p->prev;
	newnode->next = p;
	p->prev->next = newnode;
	p->prev = newnode;
}
void add(node *header, int rank, char e) {
	node *p = header;
	int i;

	if (rank < 1 || rank > header->n + 1) {
		invalid();
		return -1;
	}
	for (i = 0; i < rank; i++)
		p = p->next;
	addNodeBefore(p, e);
	header->n += 1;
}

void delete(node *header, int rank) {
	node *p = header;
	int i;

	if (rank < 1 || rank > header->n) {
		invalid();
		return -1;
	}

	for (i = 0; i < rank; i++)
		p = p->next;
	putnode(p);
	header->n -= 1;
}

char get(node *header, int rank) {
	node *p = header;
	int i;

	if (rank <1 || rank > header->n) {
		invalid();
		return NULL;
	}

	for (i = 0; i < rank; i++)
		p = p->next;
	
	return p->elem;
}
void print(node *header, node *trailer) {
	node *p = header->next;

	while (p != trailer) {
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
}

int main() {
	node *header=getnode(), *trailer = getnode();
	int n, i, rank;
	char ch, e;

	initList(header, trailer);


	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &ch);

		switch (ch) {
		case 'A':
			scanf("%d %c", &rank, &e);
			add(header, rank, e);
			break;
		case 'D':
			scanf("%d", &rank);
			delete(header, rank);
			break;
		case 'G':
			scanf("%d", &rank);
			e = get(header, rank);
			if(e != NULL)
				printf("%c", e);
			break;
		case'P':
			print(header, trailer);
			break;
		default:
			break;
		}

	}

	return 0;

}

