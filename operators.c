/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:38:01 by mliew             #+#    #+#             */
/*   Updated: 2022/11/03 00:52:41 by mliew            ###   ########.fr       */
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

void	push(t_list **from, t_list **pushto, int c)
{
	t_list	*tmp;
	t_list	*head;

	tmp = *from;
	*pushto = tmp;
	
	(*pushto)->next = head;
	set_position (*pushto);
	set_position (*from);
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}

// void	rotate_a()
// void	rotate_b()
// void	rr()

// void	reverse_rotate_a()
// void	reverse_rotate_b()
// void	rrr()