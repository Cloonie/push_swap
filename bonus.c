/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:07:16 by mliew             #+#    #+#             */
/*   Updated: 2022/12/26 20:07:16 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op(t_list **stacka, t_list **stackb, char *op)
{
	if (ft_strncmp(op, "\n", 2) == 0)
		errormsg();
	else if (ft_strncmp(op, "pa", 2) == 0 && *stackb)
		push(stackb, stacka, 0);
	else if (ft_strncmp(op, "pb", 2) == 0 && *stacka)
		push(stacka, stackb, 0);
	else if (ft_lstsize(*stacka) < 2)
		errormsg();
	else if (ft_strncmp(op, "sa", 2) == 0)
		swap(stacka, 0);
	else if (ft_strncmp(op, "ra", 2) == 0)
		rotate(stacka, 0);
	else if (ft_strncmp(op, "rra", 3) == 0)
		reverse_rotate(stacka, 0);
	else if (ft_lstsize(*stackb) < 2)
		errormsg();
	else if (ft_strncmp(op, "sb", 2) == 0)
		swap(stackb, 0);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rotate(stackb, 0);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		reverse_rotate(stackb, 0);
	else if (ft_strncmp(op, "ss", 2) == 0)
	{
		swap(stacka, 0);
		swap(stackb, 0);
	}
	else if (ft_strncmp(op, "rr", 2) == 0)
	{
		rotate(stacka, 0);
		rotate(stackb, 0);
	}
	else if (ft_strncmp(op, "rrr", 3) == 0)
	{
		reverse_rotate(stacka, 0);
		reverse_rotate(stackb, 0);
	}
	else
		errormsg();
	// printingstack(*stacka, *stackb);
}

int	check_limit(int steps, int size)
{
	if (size == 3 && steps >= 3)
		return (1);
	else if (size == 5 && steps >= 12)
		return (1);
	else if (size == 100 && steps >= 1500)
		return (1);
	else if (size == 500 && steps >= 11500)
		return (1);
	return (0);
}

void	take_op(t_list **stacka, t_list **stackb)
{
	// int		steps;
	// int		size;
	char	*op;

	// steps = 0;
	// size = ft_lstsize(*stacka);
	op = get_next_line(0);
	while (op)
	{
		do_op(stacka, stackb, op);
		if (is_sorted(stacka) && *stackb == NULL)
			return ;
		op = get_next_line(0);
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
	if (!is_sorted(&stacka))
		take_op(&stacka, &stackb);
	if (is_sorted(&stacka) && stackb == NULL)
		printf("OK\n");
	else
		printf("KO\n");
	// system("leaks checker");
}
