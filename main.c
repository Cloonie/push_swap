/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/12/08 21:20:28 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_list **stacka, t_list **stackb, int size)
{
	int	pivot;
	int i;

	i = 0;
	pivot = size - (size / 2);
	while (++i <= size)
	{
		if ((*stacka)->index <= pivot)
		{
			push(stacka, stackb, 'b');
			(*stackb)->high = pivot;
			(*stackb)->low = pivot;
		}
		else
			rotate(stacka, 'a');
	}
	// i = pivot;
	// pivot = pivot + (pivot / 2) + (pivot % 2);
	// while (i--)
	// {
	// 	if ((*stacka)->index <= pivot && (*stacka)->size == size)
	// 	{
	// 		push(stacka, stackb, 'b');
	// 		(*stackb)->size = pivot;
	// 		i++;
	// 	}
	// 	else
	// 		reverse_rotate(stacka, 'a');
	// }
	// if ((*stacka)->size == ft_lstlast(*stacka)->size)
	// 	rotate(stacka, 'a');
	// if ((*stacka)->index > (*stacka)->next->index
	// 	&& (*stacka)->size == (*stacka)->next->size)
	// 	swap(stacka, 'a');
	// if (ft_lstsize(*stackb) == 2 && (*stackb)->index < (*stackb)->next->index)
	// 	swap(stackb, 'b');
	// quick_sort_b(stackb, stacka, (*stacka)->size);
}

void	sort_b(t_list **stackb, t_list **stacka, int size)
{
	int	pivot;

	pivot = (size / 2) + (size % 2);
	pivot = pivot + (pivot / 2) + (pivot % 2);
	while (pivot--)
	{
		if ((*stacka)->index <= pivot && (*stacka)->size == size)
		{
			push(stacka, stackb, 'b');
			(*stackb)->size = pivot;
			pivot++;
		}
		else
			reverse_rotate(stacka, 'a');
	}
}

void	sort_stacks(t_list **stacka, t_list **stackb)
{
	int	size;

	size = ft_lstsize(*stacka);
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
		// quick_sort_a(stacka, stackb, size);
		// quick_sort_b(stackb, stacka, size);
		sort_a(stacka, stackb, size);
		// sort_b(stackb, stacka, size);
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
