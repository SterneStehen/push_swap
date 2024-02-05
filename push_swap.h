/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:57:50 by smoreron          #+#    #+#             */
/*   Updated: 2024/02/03 15:57:50 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

# include "./libft/libft.h"

// typedef struct t_list
// {
// 	int	num;
// 	int	index;
// 	struct	t_list * next;
// }t_list;

void	ft_listclear(t_list **lst);
t_list	*ft_listlast(t_list *lst);
void	ft_putstr_fd(char *s, int fd);
void ft_print_Stack(t_list * st);
int reverseRotate(t_list **list);
int rra(t_list **a_list);
int rrb(t_list **b_list);
int rrr(t_list **a_list, t_list **b_list);
int rotate(t_list **list);
int ra(t_list **a_list);
int rb(t_list **b_list);
int rr(t_list **a_list, t_list **b_list);
int push(t_list **a_list, t_list **b_list);
int pb(t_list **a_list, t_list **b_list);
int pa(t_list **a_list, t_list **b_list);
int swap(t_list **list);
int sa(t_list **list);
int sb(t_list **list);
int ss(t_list **lista, t_list **listb);
int ft_len_stack(t_list *list);
int ft_sorted(t_list * list);
void ft_sort_3(t_list **a);
int ft_find_min_num(t_list *a);
void ft_sort_4(t_list **a, t_list **b);
void ft_sort_5(t_list **a, t_list **b);
void ft_to_min_element(t_list **list, int min_position);
int ft_min_position(t_list *a);
void ft_sort_all(t_list **a, t_list **b);
void ft_push_swap(t_list **a, t_list **b);
t_list *ft_min_stack_start(t_list *list);
t_list *ft_index_stack(t_list *stack);
int ft_is_empty(t_list *st);
//size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_word_count( char const *str, char c);
//char	**ft_split(char const *s, char c);
void	ft_listadd_back(t_list **lst, t_list *new);
t_list	*ft_listnew(int content);
//int	ft_atoi(const char *nptr);
int	ft_is_digit(int c);
t_list * ft_creat();
t_list *ft_creat_stack(t_list *a, int ac, char * argv[]);
int	ft_isnum(char *num);
void	ft_error(char *c);
int ft_duble(int digit, char **av, int i);

#endif