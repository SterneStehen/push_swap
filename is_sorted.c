/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:25:37 by smoreron          #+#    #+#             */
/*   Updated: 2024/02/03 16:25:37 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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



int ft_is_empty(t_list *st)
{
		return (st->num == 0);
}
