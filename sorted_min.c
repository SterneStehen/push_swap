/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:09:24 by smoreron          #+#    #+#             */
/*   Updated: 2024/02/03 16:09:24 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_sa(t_list **a, int flag)
{
	if (flag == 1)
	{
		rra(a);
		sa(a);
	}
	else if (flag == 2)
	{
		ra(a);
		sa(a);
	}
}

void	ft_sort_3(t_list **a)
{
	int	top;
	int	mid;
	int	low;

	if (*a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
		return ;
	top = (*a)->num;
	mid = (*a)->next->num;
	low = (*a)->next->next->num;
	if (top > mid && mid > low)
		ft_ra_sa(a, 2);
	else if (top > mid && mid < low && top > low)
		ra(a);
	else if (top < mid && mid > low && top > low)
		rra(a);
	else if (top < mid && mid > low && top < low)
		ft_ra_sa(a, 1);
	else if (top > mid && mid < low && top < low)
		sa(a);
}

void	ft_sort_4(t_list **a, t_list **b)
{
	int	len_to_min;

	len_to_min = ft_find_min_num(*a);
	if (len_to_min == 1)
		ra(a);
	else if (len_to_min == 2)
	{
		ra(a);
		ra(a);
	}
	else if (len_to_min == 3)
		rra(a);
	pb(a, b);
	ft_sort_3(a);
	pa(a, b);
}

void	ft_sort_5(t_list **a, t_list **b)
{
	int	len_to_min;

	len_to_min = ft_find_min_num(*a);
	if (len_to_min == 1)
		ra(a);
	else if (len_to_min == 2)
	{
		ra(a);
		ra(a);
	}
	else if (len_to_min == 3)
	{
		rra(a);
		rra(a);
	}
	else if (len_to_min == 4)
	{
		rra(a);
	}
	pb(a, b);
	ft_sort_4(a, b);
	pa(a, b);
}
