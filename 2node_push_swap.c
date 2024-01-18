/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:00:25 by smoreron          #+#    #+#             */
/*   Updated: 2023/12/29 14:00:25 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int num;
	struct s_list * next;
	struct s_list * prev;
}t_list;

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
	int i;
	count = 0;
	i = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		i++;
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
		while (s[i] == c && s[i])
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

void ft_print(t_list * list)
{
	t_list * p;
	p = list->next;
	while (p != list)
	{
		printf("%d ", p->num);
		p = p->next;
	}
	printf("\n");
}

void ft_insert(t_list *a, t_list * t)
{
	t_list *b;
	//b = malloc(sizeof(t_stack));
	b = a->next;
	t->prev = a;
	t->next = b;
	a->next = t;
	b->prev = t;
}

t_list * ft_push_front(t_list *list, int n)
{
	t_list * new;
	new = malloc(sizeof(t_list));
	new->num = n;
	ft_insert(list, new);
	return (list);
}

void ft_init(t_list * list)
{
	list->next = list;
	list->prev = list;
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

void ft_push_swap(t_list *a, t_list*b, int ac, char **av)
{
	int i;
	i = 0;
	char ** num;
	if (ac == 2)
		num = ft_split(av[1], ' ');
	else
		num = av;
	// while (i < ac)
	// {
	// 	printf("test2: argumetn #%ld = %s\n", i, av[i]);
	// 	i++;
	// }
	i = 1;
	while (i < ac)
	{
		ft_push_front(a, ft_atoi(num[i]));
		i++;
	}
	ft_print(a);	
}

int main(int argc, char * argv[])
{
	// argc = 2;
	// char s[] = "3 4 5";
	// argv = s; 
	t_list *a;
	a = malloc(sizeof(t_list));
	ft_init(a);
	t_list *b;
	b = malloc(sizeof(t_list));
	ft_init(b);

	ft_push_swap(a, b, argc, argv);
	free(a);
	free(b);
	
}