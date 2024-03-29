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

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		reverse_rotate(t_list **list);
int		rra(t_list **a_list);
int		rrb(t_list **b_list);
int		rrr(t_list **a_list, t_list **b_list);
int		rotate(t_list **list);
int		ra(t_list **a_list);
int		rb(t_list **b_list);
int		rr(t_list **a_list, t_list **b_list);
int		push(t_list **a_list, t_list **b_list);
int		pb(t_list **a_list, t_list **b_list);
int		pa(t_list **a_list, t_list **b_list);
int		swap(t_list **list);
int		sa(t_list **list);
int		sb(t_list **list);
int		ss(t_list **lista, t_list **listb);
int		ft_len_stack(t_list *list);
int		ft_sorted(t_list *list);
int		ft_find_min_num(t_list *a);
int		ft_min_position(t_list *a);
int		ft_is_empty(t_list *st);
int		ft_is_digit(int c);
int		ft_isnum(char *num);
int		get_max_bits(t_list **stack);
int		ft_duble(int digit, char **av, int i);
int		ft_word_count( char const *str, char c);
void	ft_listadd_back(t_list **lst, t_list *new);
void	ft_error(void);
void	ft_free_split(char **av, int ac, int flag);
// void	ft_free_split1(char **av);
void	ft_input_audit(int ac, char **av);
void	ft_sort_cycle(t_list **a, t_list **b, int size, int max_bits);
void	ft_sort_step(t_list **a, t_list **b, int bit);
void	ft_sort_all(t_list **a, t_list **b);
void	ft_push_swap(t_list **a, t_list **b);
void	ft_listclear(t_list **lst);
void	ft_putstr_fd(char *s, int fd);
void	ft_print_Stack(t_list *st);
void	ft_sort_4(t_list **a, t_list **b);
void	ft_sort_5(t_list **a, t_list **b);
void	ft_to_min_element(t_list **list, int min_position);
void	ft_sort_3(t_list **a);
void	ft_ra_sa(t_list **a, int flag);
t_list	*ft_min_stack_start(t_list *list);
t_list	*ft_index_stack(t_list *stack);
t_list	*ft_listlast(t_list *lst);
t_list	*ft_listnew(int content);
t_list	*ft_creat(void);
t_list	*ft_creat_stack(t_list *a, int ac, char *argv[]);

#endif