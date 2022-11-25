/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:58:03 by mliew             #+#    #+#             */
/*   Updated: 2022/11/25 15:59:55 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib42/includes/libft.h"
# include "lib42/includes/ft_printf.h"
# include "lib42/includes/get_next_line_bonus.h"

// functions.c
void	errormsg(void);
int		check_num(char *arg);
int		check_arg(char *arg);
t_list	*fill_stack(int ac, char **av);
void	check_dup(t_list *stack);
t_list	*assign_index(t_list *stack, int index);
void	set_position(t_list *stack);

// operators.c
void	swap(t_list **stacka, int c);
void	rotate(t_list **stack, int c);
void	reverse_rotate(t_list **stack, int c);
void	push(t_list **from, t_list **pushto, int c);
void	ss(t_list **stacka, t_list **stackb, int c);
void	rr(t_list **stacka, t_list **stackb, int c);
void	rrr(t_list **stacka, t_list **stackb, int c);

void	quick_sort_a(t_list **stacka, t_list **stackb, int size);
void	quick_sort_b(t_list **stackb, t_list **stacka);

#endif