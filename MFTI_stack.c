#include <stdio.h>

#define SIZE 8

typedef int data;

typedef struct 
{
	data a[SIZE];
	unsigned int n;
}Stack;

void ft_print(Stack * st)
{
	int i;

	i = 0;
	while (i < st->n)
	{
	printf("%d , i = %d \n", st->a[i], i);
	i++;
	}
}

int main()
{
	Stack s = {{7,4,1}, 3};
	Stack *st = &s;
	unsigned int i;

	ft_print(st);

	
	
	
}