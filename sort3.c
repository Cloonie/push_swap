/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:31:35 by mliew             #+#    #+#             */
/*   Updated: 2022/12/23 03:31:35 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3fora(t_list **src, t_list **dst, int one, int two)
{
	if (is_sorted(src))
		return ;
	// 1 3 2
	if ((*src)->next->index > (*src)->next->next->index
			&& (*src)->next->next->index > (*src)->index)
	{
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
	}
	// 2 1 3
	else if ((*src)->next->next->index > (*src)->index
			&& (*src)->index > (*src)->next->index)
		swap(src, one);
	// 2 3 1
	else if ((*src)->next->index > (*src)->index
			&& (*src)->index > (*src)->next->next->index)
	{
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
		swap(src, one);
	}
	// 3 1 2
	else if ((*src)->index > (*src)->next->next->index
			&& (*src)->next->next->index > (*src)->next->index)
	{
		swap(src, one);
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
	}
	// 3 2 1
	else if ((*src)->index > (*src)->next->index
			&& (*src)->next->index > (*src)->next->next->index)
	{
		swap(src, one);
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
		swap(src, one);
	}
}

void	sort3forb(t_list **src, t_list **dst, int one, int two)
{
	// (1 2 3) > (2 1 3) > (1 3 | 2) > (3 1 | 2) > (2 3 1) > (3 2 1)
	if ((*src)->index < (*src)->next->index
			&& (*src)->next->index < (*src)->next->next->index)
	{
		swap(src, one);
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
		swap(src, one);
	}
	// (1 3 2) > (3 1 2) > (1 2 | 3) > (2 1 | 3) > (3 2 1)
	else if ((*src)->index < (*src)->next->next->index
			&& (*src)->next->next->index < (*src)->next->index)
	{
		swap(src, one);
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
	}
	// (2 1 3) > (1 3 | 2) > (3 1 | 2) > (2 3 1) > (3 2 1)
	else if ((*src)->next->index < (*src)->index
			&& (*src)->index < (*src)->next->next->index)
	{
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
		swap(src, one);
	}
	// (2 3 1) > (3 2 1)
	else if ((*src)->next->next->index < (*src)->index
			&& (*src)->index < (*src)->next->index)
		swap(src, one);
	// (3 1 2)
	else if ((*src)->next->index < (*src)->next->next->index
			&& (*src)->next->next->index < (*src)->index)
	{
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
	}
}