/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:07:50 by smoreron          #+#    #+#             */
/*   Updated: 2024/02/03 16:07:50 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **a_list, t_list **b_list) 
{
	t_list *tmp;

	if (a_list == NULL || (*a_list) == NULL) 
	{
		return -1;
	}
	tmp = *a_list;
	*a_list = (*a_list)->next;
	if (*b_list != NULL) 
	{
		tmp->next = *b_list;
	}
	else 
	{
		tmp->next = NULL;
	}
	*b_list = tmp;
	return (0);
}

int pb(t_list **a_list, t_list **b_list) 
{
    int result = push(a_list, b_list);
    if (result == -1)
	{
        return -1;
    }
    ft_putstr_fd("pb\n", 1);
    return 0;
}

int pa(t_list **a_list, t_list **b_list) 
{
    int result = push(b_list, a_list);
    if (result == -1) 
	{
        return -1;
    }
    ft_putstr_fd("pa\n", 1);
    return 0;
}
