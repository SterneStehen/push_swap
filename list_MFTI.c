#include <stdio.h>
#include <stdlib.h>

typedef int data;

//typedef struct Node Node;

typedef struct Node
{
	data Data;
	struct Node * next;
}Node;

Node * ft_push(Node * list, data x)
{
	Node * p;
	p = malloc(sizeof(Node));
	p->Data = x;
	p->next = list;
	list = p;
	return(p);
}

void ft_push_v2(Node ** plist, data x)
{
	Node * p;
	p = malloc(sizeof(Node));
	p->Data = x;
	p->next = *plist;
	*plist = p;
}

data ft_pop(Node ** list)
{
	data 	num;
	Node * ptr;
	num = (*list)->Data; //list
	ptr = (*list)->next;
	*list = ptr;
	return(num);
}

void ft_print(Node * list)
{
	Node * p;
	p = list;
	while (p != NULL)
	{
		printf("%d\n", p->Data);
		p = p->next;
	}
	printf("---------------------\n");
}

int main()
{

	Node * list = NULL;
	data arr[] = {5, 18, 25, 66, 78, 55};
	size_t i;
	i = 0;

	while (i  < sizeof(arr)/sizeof(arr[0]))
	{
		ft_push_v2(&list, arr[i]);
		i++;
	}
	

	// Node a = {3}, b = {17}, c = {24}, t = {10};
	// list = &a;
	// a.next = &b;
	// b.next = &c;
	// c.next = NULL;

	
	ft_print(list);

	// t.next = &a;
	// list = &t;
	// ft_print(list);
	// Node * p;
	// p = &t;
	// p->next = list;
	// list = p;
	// ft_print(list);

	list = ft_push(list, 33);
	ft_print(list);
	ft_push_v2(&list, 12);
	ft_print(list);

	// Node * 	p;
	// p = list; //list
	// list = &t;
	// list->next = &a;
	data num;
	num = ft_pop(&list);
	printf("list after pop:\n");
	ft_print(list);
	printf("num = %d\n", num);
	

	// printf("%d\n", a.Data);
	// printf("%d\n", b.Data);
	// printf("%d\n", c.Data);
	// printf("---------------------\n");

	// 	Node * p;
	// p = list;
	// printf("%d\n", p->Data);
	// p = p->next;
	// printf("%d\n", p->Data);
	// p = p->next;
	// printf("%d\n", p->Data);
	// p = p->next;
	// printf("---------------------\n");
	// p = list;
	
	
	
}
