#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct t_list
{
	int num;
	int index;
	struct t_list * next;
}t_list;

void ft_print_Stack(t_list * st)
{
	while (st != NULL)
	{
		printf("st->num = %d  st->index = %d\n", st->num, st->index);
		st = st->next;
	}
	//printf("test st->n = %d\n", st->n);
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

t_list * swap(t_list *list)
{
	if (list == NULL || list->next == NULL) 
	{
        return list;
    }
	
	t_list *tmp;
	size_t num;
	size_t index;

	tmp = list->next;
	num = tmp->num;
	index = tmp->index;
	tmp->num = list->num;
	tmp->index = list->index;
	list->num = num;
	list->index = index;
	return (list);

}

void sa (t_list *list)
{
	list = swap(list);

	ft_putstr_fd("sa\n", 1);
}

int ft_len_stack(t_list *list)
{
	while (list)
	{
		list = list->next;
	}
	return (list->index);
}

void ft_simple_swap(t_list *list)
{
	//if(ft_len_stack(list) == 2)
	sa(list);

}

void ft_push_swap(t_list *a, t_list *b)
{
	//if(ft_len_stack(a) < 5)
	ft_simple_swap(a);
	//else
	//	ft_big_swap(a, b);
}

t_list *ft_min_stack(t_list *list) 
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

    while ((head = ft_min_stack(stack))) 
	{  
        head->index = index++;
    }

    return stack;
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
	creat = (t_list *)malloc(sizeof(t_list));
	creat = NULL;

	// t_list *st = malloc(sizeof(t_list));
	// ft_init(st);
	return creat;
}

t_list *ft_creat_stack(t_list *a, int ac, char * argv[])
{
	int i;
	int count;
	int digit;
	t_list * tmp;
	char **av;

	count = 0;
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
	return (a);
}

//int main(int argc, char*argv[])
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
	arg[1] = (char*)"7 8  10  11 12 9";

	a = ft_creat();
	b = ft_creat();
	
	a = ft_creat_stack(a, argc, arg);
	ft_print_Stack(a);
	if (!ft_sorted(a))
	{
		ft_push_swap(a, b);
		ft_print_Stack(a);
	}
	
	
	ft_lstclear(&a);
	ft_lstclear(&b);
}