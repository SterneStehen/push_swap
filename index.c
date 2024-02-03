#include "push_swap.h"

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

t_list *ft_index_stack(t_list *stack) 
{
    t_list *head;
    int index = 0;

    while ((head = ft_min_stack_start(stack))) 
	{  
        head->index = index++;
    }

    return stack;
}