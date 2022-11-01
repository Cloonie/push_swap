/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:38:01 by mliew             #+#    #+#             */
/*   Updated: 2022/11/01 21:37:39 by mliew            ###   ########.fr       */
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

void	push(t_list **stacka, t_list **stackb, int c)
{
	
}

// void	rotate_a()
// void	rotate_b()
// void	rr()

// void	reverse_rotate_a()
// void	reverse_rotate_b()
// void	rrr()