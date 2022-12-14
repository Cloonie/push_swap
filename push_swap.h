/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:58:03 by mliew             #+#    #+#             */
/*   Updated: 2022/12/28 22:12:35 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib42/includes/libft.h"
# include "lib42/includes/ft_printf.h"
# include "lib42/includes/get_next_line_bonus.h"

typedef struct s_info
{
	int	both_stacks;
	int	stack;
	int	rotates;
	int	median;
	int	btm_half_len;
	int	top_half_len;
	int	start_rr;
}	t_info;

// init.c
t_list	*bracket_arg(char **av);
t_list	*fill_stack(int ac, char **av);
t_list	*assign_index(t_list *stack, int i);
t_info	*init_info(t_info *info, t_list *stacka);

// helper.c
void	errormsg(void);
int		low_index(t_list **stack);
int		max_index(t_list **stack);
void	sort_three(t_list **stacka);
void	sort_five(t_list **stacka, t_list **stackb);

// validation.c
int		is_sorted(t_list **stack);
int		check_num(char *arg);
int		check_arg(char *arg);
void	check_dup(t_list *stack);
int		check_chunk(t_list **stack, t_info *info);

// operators.c
void	swap(t_list **head, int c);
void	rotate(t_list **stack, int c);
void	reverse_rotate(t_list **stack, int c);
void	push(t_list **from, t_list **pushto, int c);

// sort.c

// sort3.c
void	sort3_a(t_list **src, t_list **dst, int one, int two);
void	sort3_a2(t_list **src, t_list **dst, int one, int two);
void	sort3_b(t_list **src, t_list **dst, int one, int two);
void	sort3_b2(t_list **src, t_list **dst, int one, int two);

// large.c
void	median(t_list **stack, t_info *info, int size);
void	spliting(t_list **src, t_list **dst, t_info *info);
void	sort_a(t_list **stacka, t_list **stackb, t_info *info, int size);
void	sort_b(t_list **stackb, t_list **stacka, t_info *info, int size);
void	sort_stacks(t_list **stacka, t_list **stackb, t_info *info);

// bonus.c
void	extra_op(t_list **stacka, t_list **stackb, char *op);
void	do_op(t_list **stacka, t_list **stackb, char *op);
void	take_op(t_list **stacka, t_list **stackb);

// print.c
void	printing(t_list *stacka, t_list *stackb, t_info *info, int size);
void	printingstack(t_list *stacka, t_list *stackb);
#endif