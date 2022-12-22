/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:58:34 by mliew             #+#    #+#             */
/*   Updated: 2022/12/21 17:07:16 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*current;
	t_list	*tmp;

	current = *stack;
	while (current)
	{
		tmp = (current)->next;
		while (tmp)
		{
			if ((current)->index < tmp->index)
				tmp = tmp->next;
			else
				return (0);
		}
		current = (current)->next;
	}
	return (1);
}

void	sort_two(t_list **stack)
{
	if ((*stack)->index > (*stack)->next->index)
		swap(stack, 'a');
}

void	sort_three(t_list **stacka)
{
	if (is_sorted(stacka))
		return ;
	if (((*stacka)->index < (*stacka)->next->index
			&& (*stacka)->index < (*stacka)->next->next->index))
	{
		swap(stacka, 'a');
		rotate(stacka, 'a');
	}
	if ((*stacka)->index > (*stacka)->next->index
		&& (*stacka)->index > (*stacka)->next->next->index)
		rotate(stacka, 'a');
	if ((*stacka)->index > (*stacka)->next->index)
		swap(stacka, 'a');
	if ((*stacka)->index < (*stacka)->next->index
		&& (*stacka)->index > (*stacka)->next->next->index)
		reverse_rotate(stacka, 'a');
}

void	sort_five(t_list **stacka, t_list **stackb)
{
	while (ft_lstsize(*stacka) != 3)
	{
		if ((*stacka)->index < 3)
			push(stacka, stackb, 'b');
		else
			rotate(stacka, 'a');
	}
	sort_three(stacka);
	if ((*stackb)->index < (*stackb)->next->index)
		swap(stackb, 'b');
	push(stackb, stacka, 'a');
	push(stackb, stacka, 'a');
}
