/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/11/28 21:19:20 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stacka)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		if ((*stacka)->index == 3)
			rotate(stacka, 'a');
		if ((*stacka)->index == 2 && (*stacka)->next->index == 3)
			reverse_rotate(stacka, 'a');
		if ((*stacka)->index == 2)
			swap(stacka, 'a');
		if ((*stacka)->index == 1 && (*stacka)->next->index == 3)
			swap(stacka, 'a');
		i++;
	}
}

int	is_sorted(t_list **stacka)
{
	t_list	*tmp;

	tmp = *stacka;
	while (tmp)
	{
		if (tmp->index == tmp->pos)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

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
		else if (check_top_half(stacka, ft_lstsize(*stackb) + 1))
			rotate(stacka, 'a');
		else
			reverse_rotate(stacka, 'a');
	}
	quick_sort_a(stacka, stackb, ft_lstsize(*stacka));
}

void	quick_sort_b(t_list **stackb, t_list **stacka)
{
	while (ft_lstsize(*stackb))
	{
		if ((*stackb)->index == (*stacka)->index - 1)
			push(stackb, stacka, 'a');
		else if ((*stackb)->next->index == (*stacka)->index - 1)
			swap(stackb, 'b');
		else if (check_top_half(stackb, (*stacka)->index - 1))
			rotate(stackb, 'b');
		else
			reverse_rotate(stackb, 'b');
	}
	// if (ft_lstsize(*stacka) >= ft_lstsize(*stackb))
	// {
	// 	while (ft_lstsize(*stackb))
	// 		push(stackb, stacka, 'a');
	// 	return ;
	// }
	// if ((*stackb)->index == (*stacka)->index - 1)
	// 	push(stackb, stacka, 'a');
	// else if ((*stackb)->next->index == (*stacka)->index - 1)
	// 	swap(stackb, 'b');
	// quick_sort_b(stackb, stacka);
}

void	sort_stacks(t_list **stacka, t_list **stackb, int size)
{
	int	stack_size;

	stack_size = ft_lstsize(*stacka);
	if (is_sorted(stacka))
		return ;
	if (size == 2)
		if ((*stacka)->index != 1)
			swap(stacka, 'a');
	if (size == 3)
		sort_three(stacka);
	if (size >= 4)
	{
		quick_sort_a(stacka, stackb, stack_size);
		quick_sort_b(stackb, stacka);
	}
}

int	main(int ac, char **av)
{
	t_list	*stacka;
	t_list	*stackb;
	int		size;

	stackb = NULL;
	if (ac == 1)
		return (0);
	stacka = fill_stack(ac, av);
	check_dup(stacka);
	size = stacka->size;
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
