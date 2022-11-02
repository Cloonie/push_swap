/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:38:01 by mliew             #+#    #+#             */
/*   Updated: 2022/11/03 01:30:06 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_list *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		stack->pos = i;
		i++;
		stack = stack->next;
	}
}

void	swap(t_list **stack, int c)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *stack;
	*stack = (*stack)->next;
	next = (*stack)->next;
	(*stack)->next = tmp;
	tmp->next = next;
	set_position (*stack);
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	rotate(t_list **stack, int c)
{
	t_list	*tmp;
	t_list	*tail;

	if (!(*stack))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = ft_lstlast(*stack);
	tail->next = tmp;
	tmp->next = NULL;
	set_position (*stack);
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	reverse_rotate(t_list **stack, int c)
{
	t_list	*tmp;
	t_list	*tail;

	tail = ft_lstlast(*stack);
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	tail->next = *stack;
	*stack = tail;
	set_position (*stack);
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

// void	push(t_list **from, t_list **pushto, int c)
// {
// 	set_position (*pushto);
// 	set_position (*from);
// 	if (c == 'a')
// 		ft_printf("pa\n");
// 	else if (c == 'b')
// 		ft_printf("pb\n");
// }