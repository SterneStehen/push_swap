/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:01 by smoreron          #+#    #+#             */
/*   Updated: 2024/02/03 16:24:01 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_list *ft_index_stack(t_list *stack) {
    t_list *head;
    int index = 0;

    while ((head = ft_min_stack_start(stack))) 
	{  
        head->index = index++;
    }

    return stack;
}


int ft_len_stack(t_list *list) 
{
    int count = 0;
    while (list) 
	{
        count++;
        list = list->next;
    }
    return (count);
}
