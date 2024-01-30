
#include "push_swap.h"

int ft_sorted(t_list * list)
{
	if(!list)
		return (1);
	while (list->next)
	{
		if(list->num > list->next->num)
			return (0);
		list = list->next;
	}
	return (1);
	
}

int ft_min_position(t_list *a)
{
	t_list *stack;
	int min_index;
	int position;
	int i;

	if (a == NULL)
        return -1;

	i = 0;
	position = 0;

	min_index = a->index;
	stack = a;
	
	while (stack != NULL)
	{
		if(stack->index < min_index)
		{
			min_index = stack->index;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return position;
}

int ft_is_empty(t_list *st)
{
		return (st->num == 0);
}



void ft_to_min_element(t_list **list, int min_position)
{
	int len;
	int i;

	i = 0;
	len = ft_len_stack(*list);
	if(len/2 > min_position)
	{
		while (i < min_position)
		{
			ra(list);
			i++;
		}
	}
	else
	{
		while (i < len - min_position)
		{
			rra(list);
			i++;
		}
		
	}
	
}

int ft_find_min_num(t_list *a)
{
	//t_list *list;
	int count;
	int resul;
	int min;

	if(a == NULL)
		return (-1);
	//list = a;
	min = a->num;
	count = 0;
	resul = 0;

	while (a != NULL)
	{
		if(a->num < min)
		{
			min = a->num;
			resul = count;
		}
		a = a->next;
		count++;
	}
	return (resul);
}