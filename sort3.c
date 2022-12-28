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

void	sort3_a(t_list **src, t_list **dst, int one, int two)
{
	if (is_sorted(src))
		return ;
	if ((*src)->next->index > (*src)->next->next->index
		&& (*src)->next->next->index > (*src)->index)
	{
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
	}
	else if ((*src)->next->next->index > (*src)->index
		&& (*src)->index > (*src)->next->index)
		swap(src, one);
	else
		sort3_a2(src, dst, one, two);
}

void	sort3_a2(t_list **src, t_list **dst, int one, int two)
{
	if ((*src)->next->index > (*src)->index
		&& (*src)->index > (*src)->next->next->index)
	{
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
		swap(src, one);
	}
	else if ((*src)->index > (*src)->next->next->index
		&& (*src)->next->next->index > (*src)->next->index)
	{
		swap(src, one);
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
	}
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

void	sort3_b(t_list **src, t_list **dst, int one, int two)
{
	if ((*src)->index < (*src)->next->index
		&& (*src)->next->index < (*src)->next->next->index)
	{
		swap(src, one);
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
		swap(src, one);
	}
	else if ((*src)->index < (*src)->next->next->index
		&& (*src)->next->next->index < (*src)->next->index)
	{
		swap(src, one);
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
	}
	else
		sort3_b2(src, dst, one, two);
}

void	sort3_b2(t_list **src, t_list **dst, int one, int two)
{
	if ((*src)->next->index < (*src)->index
		&& (*src)->index < (*src)->next->next->index)
	{
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
		swap(src, one);
	}
	else if ((*src)->next->next->index < (*src)->index
		&& (*src)->index < (*src)->next->index)
		swap(src, one);
	else if ((*src)->next->index < (*src)->next->next->index
		&& (*src)->next->next->index < (*src)->index)
	{
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
	}
}
