#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int num;
	int index;
	struct s_stack * next;
}Stack;


void	ft_lstclear(Stack **lst)
{
	Stack	*tmp;

	if (!lst )
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void ft_print_Stack(Stack * st)
{
	while (st->next != NULL)
	{
		printf("st->num = %d \n", st->num);
		st = st->next;
	}
	//printf("test st->n = %d\n", st->n);
}

Stack	*ft_lstlast(Stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(Stack **lst, Stack *new)
{
	Stack	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

Stack	*ft_lstnew(int content)
{
	Stack	*new_list;

	new_list = (Stack *) malloc(sizeof(Stack));
	if (!new_list)
		return (NULL);
	new_list->num = content;
	new_list->next = NULL;
	return (new_list);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	long	num;

	i = 0;
	num = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			neg = -1 * neg;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (num * neg);
}

void ft_init(Stack * st)
{
	st->num = 0;
	st->index = 0;
	st->next = NULL;
}


Stack * ft_creat()
{
	Stack *st = malloc(sizeof(Stack));
	ft_init(st);
	return st;
}


void ft_creat_push(Stack *a, int ac, char * argv[])
{
	int i;
	int digit;
	Stack * tmp;
	
	i = 1;
	while (i < ac)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}
	
	if(ac > 2)
	{
		i = 1;
		while (i < ac)
		{
			digit = ft_atoi(argv[i]);
			tmp = ft_lstnew(digit);
			i++;
			ft_lstadd_back(&a, tmp);
		}
		i = 0;
		ft_print_Stack(a);
		
	}
	
}

int main(int argc, char *argv[])
{
	Stack *a;
	Stack *b;
	a = ft_creat();
	b = ft_creat();
	ft_creat_push(a, argc, argv);
	ft_lstclear(&a);
	ft_lstclear(&a);
}