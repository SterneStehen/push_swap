/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:04:54 by smoreron          #+#    #+#             */
/*   Updated: 2024/02/03 16:04:54 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_list **list)
{
	t_list	*current;
	t_list	*second_last;
	t_list	*last;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return (-1);
	second_last = NULL;
	current = *list;
	while (current->next != NULL)
	{
		second_last = current;
		current = current->next;
	}
	if (second_last == NULL)
		return (0);
	last = current;
	second_last->next = NULL;
	last->next = *list;
	*list = last;
	return (0);
}

int	rra(t_list **a_list)
{
	int	result;

	result = reverse_rotate(a_list);
	if (result == -1)
		return (-1);
	ft_putstr_fd("rra\n", 1);
	return (0);
}

int	rrb(t_list **b_list)
{
	int	result;

	result = reverse_rotate(b_list);
	if (result == -1)
		return (-1);
	ft_putstr_fd("rrb\n", 1);
	return (0);
}

int	rrr(t_list **a_list, t_list **b_list)
{
	int	result;

	if ((a_list == NULL || *a_list == NULL || (*a_list)->next == NULL)
		|| (b_list == NULL || *b_list == NULL || (*b_list)->next == NULL))
	{
		return (-1);
	}
	result = reverse_rotate(a_list);
	if (result == -1)
		return (-1);
	result = reverse_rotate(b_list);
	if (result == -1)
		return (-1);
	ft_putstr_fd("rrr\n", 1);
	return (0);
}
