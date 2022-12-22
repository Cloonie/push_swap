/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/12/22 21:53:04 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	median(t_list **stack, t_info *info, int size)
{
	(void)(*stack);
	info->btm_half_len = (size / 2) + (size % 2);
	info->top_half_len = (size / 2);
	if (info->stack == 'a')
		info->median = low_index(stack) + info->top_half_len;
	if (info->stack == 'b' && max_index(stack) > size)
		info->median = max_index(stack) - info->btm_half_len + 1;
	else if (info->stack == 'b' && max_index(stack) <= size)
		info->median = max_index(stack) - info->btm_half_len + 1;
}

int	check_chunk(t_list **stack, t_info *info)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if ((info->stack == 'a' && tmp->index < info->median)
				|| (info->stack == 'b' && tmp->index >= info->median))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	spliting(t_list **src, t_list **dst, t_info *info)
{
	while (check_chunk(src, info))
	{
		if (info->stack == 'a' && (*src)->index < info->median)
		{
			(*src)->size = info->median;
			push(src, dst, 'b');
		}
		else if (info->stack == 'b' && (*src)->index >= info->median)
		{
			// (*src)->size = info->median;
			push(src, dst, 'a');
		}
		else
		{
			rotate(src, info->stack);
			info->rotates++;
		}
	}
	while (info->rotates)
	{
		reverse_rotate(src, info->stack);
		info->rotates--;
	}
}

void	sort3(t_list **src, t_list **dst, int one, int two)
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
	// 3 2 1 > 2 3 1 > ? 3 1 > ? 1 3 > 2 1 3 > 1 2 3
	else
	{
		swap(src, one);
		push(src, dst, two);
		swap(src, one);
		push(dst, src, one);
		swap(src, one);
	}
}

void	sort_a(t_list **stacka, t_list **stackb, t_info *info, int size)
{
	info->stack = 'a';
	if (is_sorted(stacka))
	{
		printf("RETURNEDDDDDDDDDDDDD\n");
		return ;
	}
	median(stacka, info, size);
	printing(*stacka, *stackb, info, size);
	if (size == 2)
	{
		if ((*stacka)->index > (*stacka)->next->index)
			swap(stacka, 'a');
		return ;
	}
	else if (size == 3)
	{
		if (size == ft_lstsize(*stacka))
			sort_three(stacka);
		else
			sort3(stacka, stackb, 'a', 'b');
		return ;
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
	info->stack = 'b';
	median(stackb, info, size);
	printing(*stacka, *stackb, info, size);
	if (size == 2)
	{
		if ((*stackb)->index < (*stackb)->next->index)
			swap(stackb, 'b');
		push(stackb, stacka, 'a');
		push(stackb, stacka, 'a');
		return ;
	}
	else if (size == 3)
	{
		sort3(stackb, stacka, 'b', 'a');
		return ;
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
		sort_two(stacka);
	else if (size == 3)
		sort_three(stacka);
	else if (size == 5)
		sort_five(stacka, stackb);
	else
	{
		sort_a(stacka, stackb, info, size);
		// sort_b(stackb, stacka, info, size);
	}
}

void	printing(t_list *stacka, t_list *stackb, t_info *info, int size)
{
	printf("~~~~~\nstack: %c\n", info->stack);
	printf("size: %d\n", size);
	// printf("last_median: %d\n", info->last_median);
	printf("median: %d\n", info->median);
	printf("btm_half_len: %d\n", info->btm_half_len);
	printf("top_half_len: %d\n", info->top_half_len);
	// printf("chunk_size: %d\n~~~~~\n", info->chunk_size);
	printf("\nStack A:\n");
	if (stacka == NULL)
		printf("NULL\n");
	while (stacka)
	{
		printf("Value: %3d, Index: %3d, Size: %3d\n",
			stacka->value, stacka->index, stacka->size);
		stacka = stacka->next;
	}
	printf("\nStack B:\n");
	if (stackb == NULL)
		printf("NULL\n");
	while (stackb)
	{
		printf("Value: %3d, Index: %3d, Size: %3d\n",
			stackb->value, stackb->index, stackb->size);
		stackb = stackb->next;
	}
}

t_info	*init_info(t_info *info, t_list *stacka)
{
	info = malloc(sizeof(t_info));

	if (!info)
		return (NULL);
	info->both_stacks = ft_lstsize(stacka);
	info->chunk_size = 0;
	info->last_median = 0;
	info->median = 0;
	info->btm_half_len = 0;
	info->top_half_len = 0;
	info->stack = 0;
	info->rotates = 0;
	return (info);
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
	set_size(stacka, ft_lstsize(stacka));
	info = init_info(info, stacka);
	sort_stacks(&stacka, &stackb, info);

	printing(stacka, stackb, info, 0);
	// system("leaks push_swap");
}
