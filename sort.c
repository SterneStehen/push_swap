
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct t_list
{
	int	num;
	int	index;
	struct	t_list * next;
}t_list;


t_list * ft_creat()
{
	t_list * creat;
	creat = (t_list *)malloc(sizeof(t_list));
	creat = NULL;

	// t_list *st = malloc(sizeof(t_list));
	// ft_init(st);
	return creat;
}

void ft_sort_all(t_list **a, t_list **b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		len;
	int		max_bits;
	int		len_digit;

	len_digit = 3;
	head_a = *a;
	i = 0;
	j = 0;
	
	len = ft_len_stack(head_a);
	while (j < len_digit)
	{
		while (i<10)
		{
		if(head_a->num%10 == i)
			pb(a, b);
		else
			ra(a);
		i++;
		}
		while (ft_len_stack(*b) != 0)
		{
			pa(a, b);
			printf("to_a = %d\n", (*a)->num);
		}
		j++;

	}
}
int main()
{

	t_list *a;
	t_list *b;
	a = ft_creat();
	b = ft_creat();
	a->num = 108;
	a->next->num = 422;
	a->next->next = NULL;
}

	
	
