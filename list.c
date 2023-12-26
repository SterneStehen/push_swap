#include <stdio.h>

typedef int data;

//typedef struct Node Node;

typedef struct Node
{
	data Data;
	struct Node * next;
}Node;

int main()
{

	Node * list = NULL;
	Node a = {3}, b = {17}, c = {24}, t = {10};
	list = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	Node * p;
	p = list;
	printf("%d\n", a.Data);
	printf("%d\n", b.Data);
	printf("%d\n", c.Data);
	printf("---------------------\n");

	printf("%d\n", p->Data);
	p = p->next;
	printf("%d\n", p->Data);
	p = p->next;
	printf("%d\n", p->Data);
	p = p->next;
	printf("---------------------\n");


	// while (list != NULL)
	// {
	// 	printf("%d\n", list->Data);
	// 	list = list->next;
	// }
}
