/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:58:03 by mliew             #+#    #+#             */
/*   Updated: 2022/12/09 16:37:56 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib42/includes/libft.h"
# include "lib42/includes/ft_printf.h"
# include "lib42/includes/get_next_line_bonus.h"

// functions.c
t_list	*fill_stack(int ac, char **av);
t_list	*assign_index(t_list *stack);
void	set_size(t_list *stack);

// check.c
void	errormsg(void);
int		check_num(char *arg);
int		check_arg(char *arg);
void	check_dup(t_list *stack);

// operators.c
void	swap(t_list **head, int c);
void	rotate(t_list **stack, int c);
void	reverse_rotate(t_list **stack, int c);
void	push(t_list **from, t_list **pushto, int c);
void	ss(t_list **stacka, t_list **stackb, int c);
void	rr(t_list **stacka, t_list **stackb, int c);
void	rrr(t_list **stacka, t_list **stackb, int c);

// sort.c
int		is_sorted(t_list **stack);
void	sort_two(t_list **stacka);
void	sort_three(t_list **stacka);
void	sort_five(t_list **stacka, t_list **stackb);
void	quick_sort_a(t_list **stacka, t_list **stackb, int size);
void	quick_sort_b(t_list **stackb, t_list **stacka, int size);
void	sort_a(t_list **stacka, t_list **stackb, int size);
void	sort_b(t_list **stackb, t_list **stacka, int size);

#endif