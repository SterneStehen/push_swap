
#include "push_swap.h"

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
