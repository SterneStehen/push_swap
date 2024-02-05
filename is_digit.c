/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:32:08 by smoreron          #+#    #+#             */
/*   Updated: 2024/02/05 20:32:08 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_error(char *c)
{
	ft_putstr_fd(c, 1);
	exit(0);
}

int ft_duble(int digit, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == digit)
			return (0);
		i++;
	}
	return (1);
}