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
#include <limits.h>

void	ft_input_audit(int ac, char **av)
{
	char		**input;
	int			i;
	long int	digit;

	i = 0;
	if (ac == 2)
	{
		input = ft_split(av[1], ' ');
		if (!input || *(input) == NULL)
			ft_free_split(input, ac, 1);
	}
	else
		input = av + 1;
	while (input[i] != NULL)
	{
		if (input[i][0] == '\0')
			ft_free_split(input, ac, 1);
		digit = ft_atoi(input[i]);
		if (!ft_isnum(input[i]) || !ft_duble(digit, input, i)
			|| digit < -2147483648 || digit > 2147483647)
			ft_free_split(input, ac, 1);
		i++;
	}
	if (ac == 2)
		ft_free_split(input, ac, 0);
}

void	ft_free_split(char **av, int ac, int flag)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[i])
		{
			free(av[i]);
			i++;
		}
		free(av);
	}
	if (flag == 1)
		ft_error();
}

t_list	*ft_creat_stack(t_list *a, int ac, char *argv[])
{
	int		i;
	long	digit;
	t_list	*tmp;
	char	**av;

	i = 0;
	if (ac == 2)
		av = ft_split(argv[1], ' ');
	else
		av = argv + 1;
	while (av[i])
	{
		digit = ft_atoi(av[i]);
		tmp = ft_listnew(digit);
		ft_listadd_back(&a, tmp);
		i++;
	}
	a = ft_index_stack(a);
	if (ac == 2)
		ft_free_split(av, 0, 0);
	return (a);
}
