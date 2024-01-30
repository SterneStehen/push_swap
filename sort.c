
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
	if(top < mid && mid > low && low > top)
	{
		sa(a);
		ra(a);
	}
	else if(top > mid && mid < low && low > top)
		sa(a);
	else if(top < mid && mid > low && low < top)
		rra(a);
	else if(top > mid && mid < low && low < top)
		ra(a);
	else if(top > mid && mid > low && low < top)
	{
		sa(a);
		rra(a);
	}
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

void ft_sort_all(t_list **a, t_list **b)
{
    int min_index;
	while (*a)
    {
        min_index = ft_min_position(*a);
		//min_index - ft_find_min_num(*a);
		ft_to_min_element(a, min_index);
        //bring_to_top(a, min_index);
        pb(a, b);
    }
    while (*b)
    {
        pa(a, b);
    }
	ft_print_Stack(*a);
}