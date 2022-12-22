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