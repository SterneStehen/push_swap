/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:27:41 by smoreron          #+#    #+#             */
/*   Updated: 2024/02/03 16:27:41 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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