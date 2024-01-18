#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int num;
	int index;
	struct s_list * next;
}t_list;

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

void ft_print_Stack(t_list * st)
{
	while (st != NULL)
	{
		printf("st->num = %d \n", st->num);
		st = st->next;
	}
	//printf("test st->n = %d\n", st->n);
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

void ft_creat_push(t_list *a, int ac, char * argv[])
{
	int i;
	int count;
	int digit;
	t_list * tmp;
	char **av;
	//av = malloc(sizeof(char));

	count = 0;
	i = 0;
	if (ac == 2)
	{
		av = ft_split(argv[1], ' ');
		//printf("%s\n", *av);
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
		//tmp = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(&a, tmp);
		i++;
		//ft_print_Stack(a);
	}
	ft_print_Stack(a);
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
	arg[1] = (char*)"7 8 9 10 11 12";

	a = ft_creat();
	b = ft_creat();
	
	ft_creat_push(a, argc, arg);
	ft_lstclear(&a);
	ft_lstclear(&b);
}