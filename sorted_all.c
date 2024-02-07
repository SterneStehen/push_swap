/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:56:21 by smoreron          #+#    #+#             */
/*   Updated: 2024/02/07 23:56:21 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while (max != 0)
	{
		max = max / 2;
		max_bits++;
	}
	return (max_bits);
}

void	ft_sort_cycle(t_list **a, t_list **b, int size, int max_bits)
{
	int		i;
	int		j;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
			ft_sort_step(a, b, i);
		while (ft_len_stack(*b) != 0)
			pa(a, b);
		i++;
	}
}

void	ft_sort_step(t_list **a, t_list **b, int bit)
{
	t_list	*head_a;
	int		temp;
	int		count;

	head_a = *a;
	temp = head_a->index;
	count = bit;
	while (count > 0)
	{
		temp /= 2;
		count--;
	}
	if ((temp & 1) == 1)
		ra(a);
	else
		pb(a, b);
}

void	ft_sort_all(t_list **a, t_list **b)
{
	t_list	*head_a;
	int		size;
	int		max_bits;

	head_a = *a;
	size = ft_len_stack(head_a);
	max_bits = get_max_bits(a);
	ft_sort_cycle(a, b, size, max_bits);
}

// void	ft_sort_all(t_list **a, t_list **b)
// {
// 	t_list	*head_a;
// 	int		i;
// 	int		j;
// 	int		size;
// 	int		count;
// 	int		temp;
// 	int		max_bits;

// 	i = 0;
// 	head_a = *a;
// 	size = ft_len_stack(head_a);
// 	max_bits = get_max_bits(a);
// 	while (i < max_bits)
// 	{
// 		j = 0;
// 		while (j++ < size)
// 		{
// 			head_a = *a;
// 			temp = head_a->index;
// 			count = i;
// 			while (count > 0)
// 			{
// 				temp /= 2;
// 				count--;
// 			}
// 			if ((temp & 1) == 1)
// 				ra(a);
// 			else
// 				pb(a, b);
// 		}
// 		while (ft_len_stack(*b) != 0)
// 			pa(a, b);
// 		i++;
// 	}
// }
// void ft_sort_all(t_list **a, t_list **b)
// {
//     int min_index;
// 	while (*a)
//     {
//         min_index = ft_min_position(*a);
// 		//min_index - ft_find_min_num(*a);
// 		ft_to_min_element(a, min_index);
//         //bring_to_top(a, min_index);
//         pb(a, b);
//     }
//     while (*b)
//     {
//         pa(a, b);
//     }
// 	//ft_print_Stack(*a);
// }