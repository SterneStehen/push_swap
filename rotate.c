/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:05:36 by smoreron          #+#    #+#             */
/*   Updated: 2024/02/03 16:05:36 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rotate(t_list **list) 
{
    if (list == NULL || *list == NULL || (*list)->next == NULL) 
        return -1;
    t_list *tmp;
	t_list *end;
	tmp = *list;
    *list = (*list)->next;
    end = ft_listlast(tmp);
    end->next = tmp;
    tmp->next = NULL;
    return 0;
}

int ra(t_list **a_list)
{
	int result;
	result = rotate(a_list);
	if(result == -1)
		return(-1);
	ft_putstr_fd("ra\n", 1);
	return (0);
}

int rb(t_list **b_list)
{
	int result;
	result = rotate(b_list);
	if(result == -1)
		return(-1);
	ft_putstr_fd("rb\n", 1);
	return (0);
}


int rr(t_list **a_list, t_list **b_list)
{
	if ((a_list == NULL || *a_list == NULL || (*a_list)->next == NULL) ||
        (b_list == NULL || *b_list == NULL || (*b_list)->next == NULL)) 
	{
        return -1;
    }
	int result;
	result = rotate(a_list);
	if(result == -1)
		return(-1);
	result = rotate(b_list);
	if(result == -1)
		return(-1);
	ft_putstr_fd("rr\n", 1);
	return (0);
}
