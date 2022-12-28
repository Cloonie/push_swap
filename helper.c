/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:19:32 by mliew             #+#    #+#             */
/*   Updated: 2022/12/23 03:19:32 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errormsg(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

int	low_index(t_list **stack)
{
	t_list	*tmp;
	int		low;

	tmp = *stack;
	low = INT_MAX;
	while (tmp)
	{
		if (tmp->index < low)
			low = tmp->index;
		tmp = tmp->next;
	}
	return (low);
}

int	max_index(t_list **stack)
{
	t_list	*tmp;
	int		max;

	tmp = *stack;
	max = INT_MIN;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
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
