/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/12/09 21:58:57 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_chunk(t_list **stack)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->size == tmp->next->size)
		{
			tmp = tmp->next;
			count++;
		}
		else
			return (0);
	}
	return (count);
}

void	assign_chunk(t_list **stacka, int highest)
{
	t_list			*tmp;
	static int		lowest;

	tmp = *stacka;
	if (!lowest)
		lowest = INT_MAX;
	while (tmp)
	{
		if (tmp->index <= highest && tmp->index < lowest)
			lowest = tmp->index;
		tmp = tmp->next;
	}
	(*stacka)->low = lowest;
	(*stacka)->high = highest;
	(*stacka)->size = (highest - lowest) + 1;
}

void	sort_a(t_list **stacka, t_list **stackb, int size)
{
	int	median;
	int	i;

	i = size;
	median = ft_lstsize(*stackb) + (size / 2) + (size % 2);
	if (size == 2)
		sort_two(stacka);
	else if (size == 3)
		sort_three(stacka);
	else if (size > 3)
	{
		while (i--)
		{
			if ((*stacka)->index <= median)
			{
				// assign_chunk(stacka, median);
				(*stacka)->size = (size / 2) + (size % 2);
				push(stacka, stackb, 'b');
			}
			else
				rotate(stacka, 'a');
		}
		sort_a(stacka, stackb, (size / 2));
		sort_b(stackb, stacka, (size / 2) + (size % 2));
	}
}

void	sort_b(t_list **stackb, t_list **stacka, int size)
{
	int	whole_stack;
	int	median;
	int	i;

	whole_stack = ft_lstsize(*stacka) + ft_lstsize(*stackb);
	median = (whole_stack + 1 - size - ((size / 2) + (size % 2)));
	i = 0;
	if (size == 2)
		sort_two(stacka);
	else if (size == 3)
		sort_three(stacka);
	else if (size > 3)
	{
		while (i++ < size)
		{
			if ((*stackb)->index > median)
				push(stackb, stacka, 'a');
			else
				rotate(stackb, 'b');
		}
		sort_a(stacka, stackb, (size / 2));
		sort_b(stackb, stacka, (size / 2) + (size % 2));
	}
}

void	sort_stacks(t_list **stacka, t_list **stackb)
{
	int	size;

	size = ft_lstsize(*stacka);
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
		// quick_sort_a(stacka, stackb, size);
		// quick_sort_b(stackb, stacka, size);
		sort_a(stacka, stackb, size);
	}
}

int	main(int ac, char **av)
{
	t_list	*stacka;
	t_list	*stackb;

	stackb = NULL;
	if (ac == 1)
		exit (0);
	stacka = fill_stack(ac, av);
	check_dup(stacka);
	assign_index(stacka);
	set_size(stacka);
	sort_stacks(&stacka, &stackb);
	printf("\nStack A:\n");
	if (stacka == NULL)
		printf("NULL\n");
	while (stacka)
	{
		printf("Value: %d, Index: %d, Low: %d, High: %d, Size: %d\n",
			stacka->value, stacka->index, stacka->low, stacka->high, stacka->size);
		stacka = stacka->next;
	}
	printf("\nStack B:\n");
	if (stackb == NULL)
		printf("NULL\n");
	while (stackb)
	{
		printf("Value: %d, Index: %d, Low: %d, High: %d, Size: %d\n",
			stackb->value, stackb->index, stackb->low, stackb->high, stackb->size);
		stackb = stackb->next;
	}

	// system("leaks push_swap");
}
