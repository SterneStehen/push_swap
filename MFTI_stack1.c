#include <stdio.h>

#define SIZE 4

typedef int data;

typedef struct 
{
	data a[N];
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
	//printf("test st->n = %d\n", st->n);
}

int ft_is_empty(Stack *st)
{
		return (st->n == 0);
}

int ft_is_full(Stack *st)
{
	if (st->n == N)
		return 0;
	else
		return -1;
}

data ft_pop(Stack * st)
{
	data resul;
	st->n--;
	resul = st->a[st->n];
	st->a[st->n] = 0;
	
	return resul;
}


int main()
{
	Stack s = {{7,4,1}, 3};
	Stack *st = &s;
	data p, p1, p2;
	unsigned int i;

	i = 0;
	ft_init(st);
	printf("is_empty %s\n", ft_is_empty(st) ? "YES" : "NO");
	printf("is_full %s\n", ft_is_full(st) == 0 ? "YES" : "NO");
	
	while (ft_is_full(st) != 0)
	{
		ft_push(st, i);
		i++;
	}
	
	// ft_push(st, 5);
	// ft_push(st, 17);
	// ft_push(st, -3);
	// ft_push(st, 10);
	ft_print(st);
	printf("is_empty %s\n", ft_is_empty(st) ? "YES" : "NO");
	printf("is_full %s\n", ft_is_full(st) == 0 ? "YES" : "NO");
	while (st->n >0)
	{
		p = ft_pop(st);
	}
	ft_print(st);
	
	
}