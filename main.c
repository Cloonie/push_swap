/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/12/12 16:53:22 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	spliting(t_list **stacka, t_list **stackb, int size)
{
	static int	median;
	int	i;

	i = size;
	median = median + (size / 2) + (size % 2);

	printf("\nA: |size: %d| ", size);
	printf("|median: %d| \n", median);

	while (i--)
	{
		if ((*stacka)->index <= median)
		{
			(*stacka)->size = median;
			push(stacka, stackb, 'b');
		}
		else
		{
			rotate(stacka, 'a');
		}
	}
}
void	sort_a(t_list **stacka, t_list **stackb, int size)
{
	printing(*stacka, *stackb);
	if (size == 2)
		sort_two(stacka);
	else if (size == 3)
		sort_three(stacka);
	else if (size > 3)
	{
		spliting(stacka, stackb, size);
		sort_a(stacka, stackb, (size / 2));
		// sort_b(stackb, stacka, (size / 2));
	}
}

void	sort_b(t_list **stackb, t_list **stacka, int size)
{
	int	whole_stack;
	int	median;
	int	i;
	int	count_rotate;

	count_rotate = 0;
	whole_stack = ft_lstsize(*stacka) + ft_lstsize(*stackb);
	median = (whole_stack + 1 - size - ((size / 2) + (size % 2)));
	i = 0;
	printf("\nB: |size: %d| ", size);
	printf("|median: %d| \n", median);
	printing(*stacka, *stackb);
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
			{
				rotate(stackb, 'b');
				count_rotate++;
			}
		}
		while (count_rotate--)
			reverse_rotate(stackb, 'b');
		// sort_a(stacka, stackb, (size / 2) + (size % 2));
		// sort_b(stackb, stacka, (size / 2) + (size % 2));
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
		sort_a(stacka, stackb, size);
}

void	printing(t_list *stacka, t_list *stackb)
{
	printf("\nStack A:\n");
	if (stacka == NULL)
		printf("NULL\n");
	while (stacka)
	{
		printf("Value: %d, Index: %d, Size: %d\n",
			stacka->value, stacka->index, stacka->size);
		stacka = stacka->next;
	}
	printf("\nStack B:\n");
	if (stackb == NULL)
		printf("NULL\n");
	while (stackb)
	{
		printf("Value: %d, Index: %d, Size: %d\n",
			stackb->value, stackb->index, stackb->size);
		stackb = stackb->next;
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
	set_size(stacka, ft_lstsize(stacka));
	sort_stacks(&stacka, &stackb);

	// printing(stacka, stackb);
	// system("leaks push_swap");
}
