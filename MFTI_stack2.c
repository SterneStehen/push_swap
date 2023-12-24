#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef int data;

typedef struct 
{
	data *a;
	unsigned int n;
	size_t SIZE;
}Stack;


int ft_is_empty(Stack *st)
{
		return (st->n == 0);
}

int ft_is_full(Stack *st)
{
	return(st->n == st->SIZE);
}

void ft_init(Stack * st)
{
	st->n = 0;
	st->SIZE = 0;
	st->a = NULL;
}

Stack * ft_creat()
{
	Stack *st = malloc(sizeof(Stack));
	ft_init(st);
	return st;
}

void ft_destroy(Stack *st)
{
	free(st->a);
	free(st);
	ft_init(st);
}

void ft_push(Stack * st, data x)
{
	if(ft_is_full(st))
	{
		free(st->a);
		st->SIZE += N;
		//st->a = realloc(st->a, sizeof(data)*st->SIZE);
		st->a = malloc(sizeof(data)*st->SIZE);
	}
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

data ft_pop(Stack * st)
{
	data resul;
	st->n--;
	resul = st->a[st->n];
	
	//st->a[st->n] = 0;
	
	return resul;
}



int main()
{
	//Stack s;
	//Stack *st = &s;
	data p;
	unsigned int i;

	i = 2;
	//ft_init(st);
	Stack *st = ft_creat();
	printf("is_empty %s\n", ft_is_empty(st) ? "YES" : "NO");
	printf("is_full %s\n", ft_is_full(st) == 0 ? "YES" : "NO");
	
	while (i < 7)
	{
		ft_push(st, i);
		i++;
	}

	ft_print(st);
	printf("is_empty %s\n", ft_is_empty(st) ? "YES" : "NO");
	printf("is_full %s\n", ft_is_full(st) == 0 ? "YES" : "NO");
	while (st->n > 0)
	{
		p = ft_pop(st);
		printf("%d\n", p);
	}
	printf("\n-------------------\n");
	ft_print(st);
	ft_destroy(st);
	return 0;
	
}