/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/12/08 16:41:41 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_top_half(t_list **stack, int index)
{
	t_list	*tmp;
	int		size;

	tmp = *stack;
	size = ft_lstsize(tmp);
	while (tmp->index != index)
		tmp = tmp->next;
	if (tmp->pos <= (size / 2))
		return (1);
	else
		return (0);
}

void	quick_sort_a(t_list **stacka, t_list **stackb, int size)
{
	int	median;
	int	midval;

	median = (size / 2) + (size % 2);
	midval = median + ft_lstsize(*stackb);
	if (ft_lstsize(*stacka) <= 2)
	{
		if ((*stacka)->index > (*stacka)->next->index)
			swap(stacka, 'a');
		return ;
	}
	while (ft_lstsize(*stacka) != median)
	{
		if (((*stacka)->index <= midval && (size % 2) == 0)
			|| ((*stacka)->index < midval && (size % 2) == 1))
			push(stacka, stackb, 'b');
		// else if (check_top_half(stacka, ft_lstsize(*stackb) + 1))
		// 	rotate(stacka, 'a');
		else
			rotate(stacka, 'a');
	}
	quick_sort_a(stacka, stackb, ft_lstsize(*stacka));
}

void	quick_sort_b(t_list **stackb, t_list **stacka, int size)
{
	c_list	*chunk;

	while (ft_lstsize(*stackb) > (size / 2))
	{
		if ((*stackb)->index == (*stacka)->index - 1)
			push(stackb, stacka, 'a');
		// else if ((*stackb)->next->index == (*stacka)->index - 1)
		// 	swap(stackb, 'b');
		else if (check_top_half(stackb, (*stacka)->index - 1))
			rotate(stackb, 'b');
		else
			reverse_rotate(stackb, 'b');
	}
	chunk->size = ft_lstsize(*stackb);
	while (ft_lstsize(*stackb))
		push(stackb, stacka, 'a');
}

void	sort_a(t_list **stacka, t_list **stackb, int size)
{
	int	pivot;
	// int	count;
	// int	chunk_size;

	pivot = size / 2;
	while (pivot)
	{
		if ((*stacka)->index <= pivot)
			push(stacka, stackb, 'b');
		else
			rotate(stacka, 'a');
	}
	(void)stacka;
	(void)stackb;
}

// void quicksortStackA(t_list **a, int low, int high)
// {
// 	if (low < high)
// 	{
// 		int pivot = partitionStackA(a, low, high);
// 		quicksortStackA(a, low, pivot-1);
// 		quicksortStackA(a, pivot+1, high);
// 	}
// }

void	sort_stacks(t_list **stacka, t_list **stackb, int size)
{
	(void)stackb;
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
	{
		quick_sort_a(stacka, stackb, size);
		quick_sort_b(stackb, stacka, size);
		// sort_a(stackb, stacka, size);
		// sort_b(stackb, stacka, size);
	}
}

int	main(int ac, char **av)
{
	t_list	*stacka;
	t_list	*stackb;
	int		size;

	stackb = NULL;
	if (ac == 1)
		exit (0);
	stacka = fill_stack(ac, av);
	check_dup(stacka);
	size = ft_lstsize(stacka);
	assign_index(stacka, size);
	sort_stacks(&stacka, &stackb, size);

	printf("\nStack A:\n");
	if (stacka == NULL)
		printf("NULL\n");
	while (stacka)
	{
		printf("Value: %d, Index: %d, Pos: %d\n",
			stacka->value, stacka->index, stacka->pos);
		stacka = stacka->next;
	}
	printf("\nStack B:\n");
	if (stackb == NULL)
		printf("NULL\n");
	while (stackb)
	{
		printf("Value: %d, Index: %d, Pos: %d\n",
			stackb->value, stackb->index, stackb->pos);
		stackb = stackb->next;
	}

	// system("leaks push_swap");
}
