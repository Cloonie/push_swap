/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:38:01 by mliew             #+#    #+#             */
/*   Updated: 2022/10/25 20:36:35 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *stacka)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*second;

	tmp = stacka->next;
	first = stacka;
	second = tmp;
	stacka = first;
	stacka = stacka->next;
	stacka = second;
}

// void	swap_b()
// void	ss()

// void	push_a()
// void	push_b()

// void	rotate_a()
// void	rotate_b()
// void	rr()

// void	reverse_rotate_a()
// void	reverse_rotate_b()
// void	rrr()