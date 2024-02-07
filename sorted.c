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


void ft_sort_3(t_list **a)
{
	int top;
	int mid;
	int low;

	if (a == NULL || *a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
        return;
	top = (*a)->num;
	mid = (*a)->next->num;
	low = (*a)->next->next->num;
	if(top > mid && mid > low)
	{
		ra(a);
		sa(a);
	}
	else if(top > mid && mid < low && top > low)
		ra(a);
	else if(top < mid && mid > low && top > low)
		rra(a);
	// else if(top > mid && mid < low && top < low)
	// 	ra(a);
	else if(top < mid && mid > low && top < low)
	{
		rra(a);
		sa(a);
	}
	else if (top > mid && mid < low && top < low) 
	{
        sa(a);
	}
	//ft_print_Stack(*a);
}

void ft_sort_4(t_list **a, t_list **b)
{
	int len_to_min;
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
	pb(a,b);
	ft_sort_3(a);
	pa(a,b);

}

void ft_sort_5(t_list **a, t_list **b)
{
	int len_to_min;
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
	pb(a,b);
	ft_sort_4(a, b);
	pa(a,b);
	
}

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
	while (max != 0) {
      max = max/2; 
      max_bits++;
	}
	return (max_bits);
}


void ft_sort_all(t_list **a, t_list **b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *a;
	size = ft_len_stack(head_a);
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *a;

			int temp = head_a->index;
			int count = i;

			while (count > 0) 
			{
    			temp /= 2;
    			count--;
			}

			if ((temp & 1) == 1) 
			{
				ra(a);
			}	
			else
			{
				pb(a, b);
				//printf("to_b = %d\n", (*a)->num);
			}
		}
		while (ft_len_stack(*b) != 0)
		{
			pa(a, b);
			//printf("to_a = %d\n", (*a)->num);
		}
		i++;
	}
	//printf("\n---- test6-------\n");
	//ft_print_Stack(*a);
}


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

