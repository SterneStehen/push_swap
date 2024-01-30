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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct t_list
{
	int	num;
	int	index;
	struct	t_list * next;
}t_list;

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst )
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	//free(lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void ft_print_Stack(t_list * st)
{
	while (st != NULL)
	{
		printf("st->num = %d  st->index = %d\n", st->num, st->index);
		st = st->next;
	}
	//printf("test st->n = %d\n", st->n);
}

int reverseRotate(t_list **list)
{
    t_list *current;
    t_list *second_last;
    t_list *last;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return (-1); 

    second_last = NULL;
    current = *list;

    while (current->next != NULL)
    {
        second_last = current;
        current = current->next;
    }
    if (second_last == NULL)
        return (0);

    last = current;
    second_last->next = NULL;
    last->next = *list;
    *list = last;
    return (0);
}

int rra(t_list **a_list)
{
	int result;
	result = reverseRotate(a_list);
	if(result == -1)
		return(-1);
	ft_putstr_fd("rra\n", 1);
	return (0);
}

int rrb(t_list **b_list)
{
	int result;
	result = reverseRotate(b_list);
	if(result == -1)
		return(-1);
	ft_putstr_fd("rrb\n", 1);
	return (0);
}

int rrr(t_list **a_list, t_list **b_list)
{
	int result;
	if ((a_list == NULL || *a_list == NULL || (*a_list)->next == NULL) ||
        (b_list == NULL || *b_list == NULL || (*b_list)->next == NULL)) 
	{
        return -1;
    }
	result = reverseRotate(a_list);
	if(result == -1)
		return(-1);
	result = reverseRotate(b_list);
	if(result == -1)
		return(-1);
	ft_putstr_fd("rrr\n", 1);
	return (0);
}

int rotate(t_list **list) 
{
    if (list == NULL || *list == NULL || (*list)->next == NULL) 
        return -1;
    t_list *tmp;
	t_list *end;
	tmp = *list;
    *list = (*list)->next;
    end = ft_lstlast(tmp);
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

int push(t_list **a_list, t_list **b_list) 
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
    return 0;
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

int swap(t_list **list)
{
	if ((*list) == NULL || (*list)->next == NULL) 
	{
        return(-1);
    }
	
	t_list *tmp;
	size_t num;
	size_t index;

	tmp = (*list)->next;
	num = tmp->num;
	index = tmp->index;
	tmp->num = (*list)->num;
	tmp->index = (*list)->index;
	(*list)->num = num;
	(*list)->index = index;
	return (0);
}

int sa(t_list **list) 
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
        return -1;
    }
    swap(list);
    ft_putstr_fd("sa\n", 1);
    return 0;
}

int sb(t_list **list) 
{
    if (list == NULL || *list == NULL || (*list)->next == NULL) 
	{
        return -1;
    }
    swap(list);
    ft_putstr_fd("sb\n", 1);
    return 0;
}

int ss(t_list **lista, t_list **listb) {
    int res1 = 0; 
	int res2 = 0;
    if (lista && *lista && (*lista)->next != NULL) 
	{
        swap(lista);
    } 
	else 
	{
        res1 = -1;
    }
    if (listb && *listb && (*listb)->next != NULL) 
	{
        swap(listb);
    } 
	else 
	{
        res2 = -1;
    }
    ft_putstr_fd("ss\n", 1);
    if(res1 == 0 && res2 == 0)
	{
		return (0);
	}
	else
	{
		return (-1);
	}
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

int ft_find_min_num(t_list *a)
{
	//t_list *list;
	int count;
	int resul;
	int min;

	if(a == NULL)
		return (-1);
	//list = a;
	min = a->num;
	count = 0;
	resul = 0;

	while (a != NULL)
	{
		if(a->num < min)
		{
			min = a->num;
			resul = count;
		}
		a = a->next;
		count++;
	}
	return (resul);
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

// static int	get_max_bits(t_list **stack)
// {
// 	t_list	*head;
// 	int		max;
// 	int		max_bits;
// 	head = *stack;
// 	max = head->index;
// 	max_bits = 0;
// 	while (head)
// 	{
// 		if (head->index > max)
// 			max = head->index;
// 		head = head->next;
// 	}
// 	while (max != 0) 
// 	{
//       max = max/2; 
//       max_bits++;
// 	}
// 	return (max_bits);
// }

void ft_to_min_element(t_list **list, int min_position)
{
	int len;
	int i;

	i = 0;
	len = ft_len_stack(*list);
	if(len/2 > min_position)
	{
		while (i < min_position)
		{
			ra(list);
			i++;
		}
	}
	else
	{
		while (i < len - min_position)
		{
			rra(list);
			i++;
		}
		
	}
	
}

int ft_min_position(t_list *a)
{
	t_list *stack;
	int min_index;
	int position;
	int i;

	if (a == NULL)
        return -1;

	i = 0;
	position = 0;

	min_index = a->index;
	stack = a;
	
	while (stack != NULL)
	{
		if(stack->index < min_index)
		{
			min_index = stack->index;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return position;
}

// int find_min_index(t_list *stack)
// {
//     int min_index_pos = 0;
//     int current_pos = 0;
//     int min_index;
//     if (stack == NULL)
//         return -1;
//     min_index = stack->index;
//     t_list *current = stack;
//     while (current != NULL)
//     {
//         if (current->index < min_index)
//         {
//             min_index = current->index;
//             min_index_pos = current_pos;
//         }
//         current = current->next;
//         current_pos++;
//     }
//     return min_index_pos;
// }


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

void ft_push_swap(t_list **a, t_list **b)
{
	int len;

	len = ft_len_stack(*a);
	printf("len = %d\n", len);
	if(len == 2)
		sa(a);
	if(len == 3)
	{
		ft_sort_3(a);	
	}
	if(len == 4)
	{
		ft_sort_4(a, b);	
	}
	if(len == 5)
	{
		ft_sort_5(a, b);	
	}
	else
	{
		ft_sort_all(a, b);
	}
	ft_lstclear(a);
	ft_lstclear(b);
	//if(ft_len_stack(a) < 5)
	//ft_simple_swap(a, b);
	// pb(a, b);
	// pb(a, b);
	// pb(a, b);
	// pa(a, b);
	// ft_print_Stack(*a);
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

t_list *ft_min_stack_start(t_list *list) 
{
    t_list *node;
    t_list *min_stack = NULL;
    node = list;

    while (node) 
	{
        if (node->index == -1 && (min_stack == NULL || node->num < min_stack->num)) 
		{
            min_stack = node;
        }
        node = node->next;
    }
    return min_stack;
}

t_list *ft_index_stack(t_list *stack) {
    t_list *head;
    int index = 0;

    while ((head = ft_min_stack_start(stack))) 
	{  
        head->index = index++;
    }

    return stack;
}

int ft_is_empty(t_list *st)
{
		return (st->num == 0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(1);
		if (substr)
			substr[0] = '\0';
		return (substr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *) malloc (len + 1);
	if (!substr)
		return (NULL);
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	ft_world_count( char const *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == c)
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		world_count;	
	int		i;
	int		j;
	int		start;
	char	**result;

	i = 0;
	j = 0;
	world_count = ft_world_count(s, c);
	result = (char **)malloc(sizeof(char *) * (world_count + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while ((s[i] == c) && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (i > start)
			result[j++] = ft_substr(s, start, (i - start));
	}
	result[j] = NULL;
	return (result);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*new_list;

	new_list = (t_list *) malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->num = content;
	new_list->index = -1;
	new_list->next = NULL;
	return (new_list);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	long	num;

	i = 0;
	num = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			neg = -1 * neg;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (num * neg);
}

t_list * ft_creat()
{
	t_list * creat;
	//creat = (t_list *)malloc(sizeof(t_list));
	creat = NULL;
	return creat;
}

t_list *ft_creat_stack(t_list *a, int ac, char * argv[])
{
	int i;
	int digit;
	t_list * tmp;
	char **av;

	i = 0;
	if (ac == 2)
	{
		av = ft_split(argv[1], ' ');
	}
	else
	{
		av = argv;
		i = 1;
	}
	while (av[i])
	{
		digit = ft_atoi(av[i]);
		tmp = ft_lstnew(digit);
		ft_lstadd_back(&a, tmp);
		i++;
	}
	a = ft_index_stack(a);
	if (ac == 2) 
	{
    	i = 0;
    	while (av[i]) 
		{
        	free(av[i]);
        	i++;
    	}
    	free(av);
	}

	return (a);
}

int main()
{
	t_list *a;
	t_list *b;
	int argc = 2;
    char* arg[2]; 
    arg[0] = (char*)"name";
    // arg[1] = (char*)"7";
	// arg[2] = (char*)"8";
 	// arg[3] = (char*)"9";
	// arg[4] = (char*)"10";
	//arg[1] = (char*)"3179, 3674, 1287, 3007, 1726, 4589, 2170, 2883, 2771, 4815, 1160, 915, 1911, 4333, 751, 1625, 2058, 2879, 1619, 676, 4317, 4550, 789, 992, 2539, 3931, 2971, 4296, 4726, 403, 3682, 2316, 4751, 4538, 2470, 4564, 3661, 1114, 4704, 3838, 355, 3666, 4249, 2219, 3853, 1570, 2043, 4146, 3020, 2680, 639, 3445, 4874, 1776, 1364, 760, 1623, 4540, 3968, 861, 2458, 2193, 4548, 2936, 1967, 3885, 159, 1097, 2590, 4432, 489, 931, 2157, 467, 4567, 4709, 96, 892, 4221, 2314, 3376, 2237, 130, 1323, 2126, 542, 4108, 4390, 4506, 613, 3371, 1488, 2709, 2760, 3834, 2083, 1579, 1300, 2727, 1047, 4555, 3471, 3876, 2154, 897, 959, 4339, 2404, 3781, 2835, 2886, 1372, 2631, 234, 2298, 767, 4144, 1621, 3043, 2454, 1396, 821, 1642, 4885, 1840, 1054, 4872, 4557, 3616, 703, 1391, 1658, 129, 4844, 2958, 4536, 1411, 4251, 3222, 4271, 3982, 1014, 3502, 836, 2561, 4518, 1754, 1682, 1510, 1468, 4953, 3608, 525, 3985, 2836, 1479, 3508, 1150, 318, 1465, 666, 3255, 3399, 2731, 2123, 4581, 3951, 3115, 936, 4384, 2448, 4476, 4678, 2723, 1808, 2577, 241, 835, 3649, 3734, 362, 1211, 4349, 4264, 3368, 643, 2227, 1246, 7, 1802, 4474, 4600, 1028, 1819, 3883, 4768, 211, 3547, 2342, 1480, 367, 2998, 2984, 443, 1043, 4794, 1639, 4444, 2311, 1955, 4069, 2429, 3672, 4242, 2538, 87, 2770, 2875, 2752, 335, 4022, 233, 3342, 1673, 4240, 4991, 3872, 2073, 2701, 42, 2811, 2090, 3971, 4901, 267, 1763, 4071, 1416, 3945, 4884, 126, 3071, 1238, 2079, 3832, 3135, 1898, 4407, 461, 3181";
	arg[1] = (char*)"108 422 423 354 576 777";

	a = ft_creat();
	b = ft_creat();
	
	a = ft_creat_stack(a, argc, arg);
	ft_print_Stack(a);
	printf("--------start-------\n");
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