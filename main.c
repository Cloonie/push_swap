/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/12/24 16:48:52 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	median(t_list **stack, t_info *info, int size)
{
	info->btm_half_len = (size / 2) + (size % 2);
	info->top_half_len = (size / 2);
	if (info->stack == 'a')
		info->median = low_index(stack) + info->top_half_len;
	if (info->stack == 'b' && max_index(stack) > size)
		info->median = max_index(stack) - info->btm_half_len + 1;
	else if (info->stack == 'b' && max_index(stack) <= size)
		info->median = max_index(stack) - info->btm_half_len + 1;
}

void	spliting(t_list **src, t_list **dst, t_info *info)
{
	while (check_chunk(src, info))
	{
		if (info->stack == 'a' && (*src)->index < info->median)
			push(src, dst, 'b');
		else if (info->stack == 'b' && (*src)->index >= info->median)
			push(src, dst, 'a');
		else
		{
			rotate(src, info->stack);
			info->rotates++;
		}
	}
	if (info->start_rr)
		info->rotates = 0;
	while (info->rotates)
	{
		reverse_rotate(src, info->stack);
		info->rotates--;
	}
}

void	sort_a(t_list **stacka, t_list **stackb, t_info *info, int size)
{
	info->stack = 'a';
	if (is_sorted(stacka))
		return ;
	median(stacka, info, size);
	// printing(*stacka, *stackb, info, size);
	if (size == 2)
	{
		if ((*stacka)->index > (*stacka)->next->index)
			swap(stacka, 'a');
	}
	else if (size == 3)
	{
		if (size == ft_lstsize(*stacka))
			sort_three(stacka);
		else
			sort3fora(stacka, stackb, 'a', 'b');
	}
	else if (size > 3)
	{
		spliting(stacka, stackb, info);
		sort_a(stacka, stackb, info, (size / 2) + (size % 2));
		sort_b(stackb, stacka, info, (size / 2));
	}
}

void	sort_b(t_list **stackb, t_list **stacka, t_info *info, int size)
{
	info->start_rr = 0;
	info->stack = 'b';
	median(stackb, info, size);
	// printing(*stacka, *stackb, info, size);
	if (size == 2)
	{
		if ((*stackb)->index < (*stackb)->next->index)
			swap(stackb, 'b');
		push(stackb, stacka, 'a');
		push(stackb, stacka, 'a');
	}
	else if (size == 3)
	{
		sort3forb(stackb, stacka, 'b', 'a');
		push(stackb, stacka, 'a');
		push(stackb, stacka, 'a');
		push(stackb, stacka, 'a');
	}
	else if (size > 3)
	{
		spliting(stackb, stacka, info);
		sort_a(stacka, stackb, info, (size / 2) + (size % 2));
		sort_b(stackb, stacka, info, (size / 2));
	}
}

void	sort_stacks(t_list **stacka, t_list **stackb, t_info *info)
{
	int	size;

	size = info->both_stacks;
	if (is_sorted(stacka))
		return ;
	else if (size == 2)
	{
		if ((*stacka)->index > (*stacka)->next->index)
			swap(stacka, 'a');
	}
	else if (size == 3)
		sort_three(stacka);
	else if (size == 5)
		sort_five(stacka, stackb);
	else
		sort_a(stacka, stackb, info, size);
}

int	main(int ac, char **av)
{
	t_list	*stacka;
	t_list	*stackb;
	t_info	*info;

	stackb = NULL;
	info = NULL;
	if (ac == 1)
		exit (0);
	stacka = fill_stack(ac, av);
	check_dup(stacka);
	assign_index(stacka);
	info = init_info(info, stacka);
	sort_stacks(&stacka, &stackb, info);

	if (is_sorted(&stacka))
		printf("OK\n");
	else
		printf("KO\n");

	// printing(stacka, stackb, info, 0);
	// system("leaks push_swap");
}
