/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minim.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:23:21 by smoreron          #+#    #+#             */
/*   Updated: 2024/02/03 16:23:21 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min_num(t_list *a)
{
	int	count;
	int	resul;
	int	min;

	if (a == NULL)
		return (-1);
	min = a->num;
	count = 0;
	resul = 0;
	while (a != NULL)
	{
		if (a->num < min)
		{
			min = a->num;
			resul = count;
		}
		a = a->next;
		count++;
	}
	return (resul);
}

void	ft_to_min_element(t_list **list, int min_position)
{
	int	len;
	int	i;

	i = 0;
	len = ft_len_stack(*list);
	if (len / 2 > min_position)
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

int	ft_min_position(t_list *a)
{
	t_list	*stack;
	int		min_index;
	int		position;
	int		i;

	if (a == NULL)
		return (-1);
	i = 0;
	position = 0;
	min_index = a->index;
	stack = a;
	while (stack != NULL)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

t_list	*ft_min_stack_start(t_list *list)
{
	t_list	*node;
	t_list	*min_stack;

	min_stack = NULL;
	node = list;
	while (node)
	{
		if (node->index == -1 && (min_stack == NULL
				|| node->num < min_stack->num))
		{
			min_stack = node;
		}
		node = node->next;
	}
	return (min_stack);
}
