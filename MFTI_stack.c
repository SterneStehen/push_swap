#include <stdio.h>

#define SIZE 8

typedef int data;

typedef struct 
{
	data a[SIZE];
	unsigned int n;
}Stack;

void ft_init(Stack * st)
{
	st->n = 0;
}

void ft_push(Stack * st, data x)
{
	st->a[st->n] = x;
	st->n++;
}

void ft_print(Stack * st)
{
	int i;

	i = 0;
	while (i < st->n)
	{
	printf("%d , i = %d \n", st->a[i], i);
	i++;
	}
	printf("test st->n = %d\n", st->n);
}

int main()
{
	Stack s = {{7,4,1}, 3};
	Stack *st = &s;
	unsigned int i;

	if(st->n < 0)
		ft_init(st);
	ft_push(st, 5);
	ft_push(st, 17);
	ft_push(st, -3);

	ft_print(st);

	
	
	
}