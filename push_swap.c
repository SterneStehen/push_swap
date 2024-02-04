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

void ft_push_swap(t_list **a, t_list **b)
{
	int len;

	len = ft_len_stack(*a);
	if(len == 2)
		sa(a);
	else if(len == 3)
	{
		ft_sort_3(a);	
	}
	else if(len == 4)
	{
		ft_sort_4(a, b);	
	}
	else if(len == 5)
	{
		ft_sort_5(a, b);	
	}
	else
	{
		ft_sort_all(a, b);
	}
	//ft_print_Stack(*a);
	ft_listclear(a);
	ft_listclear(b);
	//if(ft_len_stack(a) < 5)
	//ft_simple_swap(a, b);
	// pb(a, b);
	// pb(a, b);
	// pb(a, b);
	// pa(a, b);
	
	// printf("_______________\n");
	// ft_print_Stack(*b);
	// rotate(b);
	// printf("_______________\n");
	//ft_print_Stack(*b);
	// rerotate(a);
	// rotate(a);
	// rotate(a);
	// printf("_______________\n");
	// ft_print_Stack(*a);
	// reverseRotate(a);
	// reverseRotate(a);
	// printf("_______________\n");
	// ft_print_Stack(*a);
	//else
	//	ft_big_swap(a, b);
}

int main(int ac, char *av[])
{
	t_list *a;
	t_list *b;
	
	if (ac < 2)
		return (-1);

	a = ft_creat();
	b = ft_creat();
	
	a = ft_creat_stack(a, ac, av);
	//ft_print_Stack(a);
	//printf("--------start-------\n");
	if (!ft_sorted(a))
	{
	
		ft_push_swap(&a, &b);
		//  printf("----test origin-----\n");
		// ft_test_sort_3(&a);
		//ft_print_Stack(a);
		//ft_print_Stack(b);
	}
	
	//ft_lstclear(&a);
	//ft_lstclear(&b);
}