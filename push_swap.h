#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct t_list
{
	int	num;
	int	index;
	struct	t_list * next;
}t_list;


//list.c
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_putstr_fd(char *s, int fd);
void ft_print_Stack(t_list * st);

//index.c
t_list *ft_min_stack_start(t_list *list);
t_list *ft_index_stack(t_list *stack);

//split.c
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_world_count( char const *str, char c);
char	**ft_split(char const *s, char c);

//rev_rotate.c
int reverseRotate(t_list **list);
int rra(t_list **a_list);
int rrb(t_list **b_list);
int rrr(t_list **a_list, t_list **b_list);

//rotate.c
int rotate(t_list **list); 
int ra(t_list **a_list);
int rb(t_list **b_list);
int rr(t_list **a_list, t_list **b_list);

//push.c
int push(t_list **a_list, t_list **b_list); 
int pb(t_list **a_list, t_list **b_list);
int pa(t_list **a_list, t_list **b_list);

//swap.c
int swap(t_list **list);
int sa(t_list **list);
int sb(t_list **list);
int ss(t_list **lista, t_list **listb);

//count.c
int ft_len_stack(t_list *list);
int	ft_atoi(const char *nptr);


//find
int ft_sorted(t_list * list);
int ft_min_position(t_list *a);
int ft_is_empty(t_list *st);
void ft_to_min_element(t_list **list, int min_position);
int ft_find_min_num(t_list *a);


//sort.c
void ft_sort_3(t_list **a);
void ft_sort_4(t_list **a, t_list **b);
void ft_sort_5(t_list **a, t_list **b);
void ft_sort_all(t_list **a, t_list **b);


//creat_stack.c
t_list * ft_creat()
t_list *ft_creat_stack(t_list *a, int ac, char * argv[]);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);


//push_swap.c
void ft_push_swap(t_list **a, t_list **b);

#endif

