/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:38:01 by mliew             #+#    #+#             */
/*   Updated: 2022/10/25 19:01:27 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap_a(t_list *stacka)
{
	t_list	*tmp;
	t_list	*new;

	new = stacka;
	tmp = stacka->next;
	new = tmp;
	new = new->next;
	new = stacka;
	return (new);
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