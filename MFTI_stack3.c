#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

typedef int data;

typedef struct 
{
	
	unsigned int n;
	size_t SIZE;
	data a[1];
}Stack;



void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*str1;
	const unsigned char	*str2;

	if (n == 0 || (!dest && !src))
		return (dest);
	i = 0;
	str1 = (unsigned char *)dest;
	str2 = (const unsigned char *)src;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dest);
}

void* ft_realloc(void* ptr, size_t newSize) 
{
    if (newSize == 0) {
        free(ptr);
        return NULL;
    }
    void* newPtr = malloc(newSize);
    if (newPtr == NULL) {
        return NULL; 
    }
    if (ptr != NULL) {
        ft_memcpy(newPtr, ptr, newSize);
        free(ptr);
    }
    return newPtr;
}


int ft_is_empty(Stack *st)
{
		return (st->n == 0);
}

int ft_is_full(Stack *st)
{
	return(st->n == st->SIZE);
}

// void ft_init(Stack * st)
// {
// 	st->n = 0;
// 	st->SIZE = 0;
// 	st->a = NULL;
// }

Stack * ft_creat()
{
	Stack *st = malloc(sizeof(Stack) + (sizeof(data) * N));
	//ft_init(st);
	st->n = 0;
	st->SIZE = 0;
	st->a[0] = 0;
	return st;
}

void ft_destroy(Stack *st)
{
	free(st);
	//free(st);
	//ft_init(st);
}

void ft_push(Stack ** pst, data x)
{
	if(ft_is_full(*pst))
	{
		(*pst)->SIZE += N;
		*pst = ft_realloc(*pst, sizeof(data)*(*pst)->SIZE + sizeof(Stack));
	}
	Stack *st = *pst;
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
	
	while (i < 99)
	{
		ft_push(&st, i);
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