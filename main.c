/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:51:59 by smoreron          #+#    #+#             */
/*   Updated: 2024/01/23 14:51:59 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_list **a, t_list **b)
{
	int	len;

	len = ft_len_stack(*a);
	if (len == 2)
		ra(a);
	else if (len == 3)
	{
		ft_sort_3(a);
	}
	else if (len == 4)
	{
		ft_sort_4(a, b);
	}
	else if (len == 5)
	{
		ft_sort_5(a, b);
	}
	else
	{
		ft_sort_all(a, b);
	}
	ft_listclear(a);
	ft_listclear(b);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (-1);
	ft_input_audit(argc, argv);
	a = ft_creat();
	b = ft_creat();
	a = ft_creat_stack(a, argc, argv);
	if (!ft_sorted(a))
		ft_push_swap(&a, &b);
	else
	{
		ft_listclear(&a);
		ft_listclear(&b);
	}
	return (0);
}
