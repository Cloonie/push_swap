/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/11/03 20:40:16 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*bracket_arg(char **av)
{
	t_list	*head;
	t_list	*tmp;
	char	**array;
	int		i;

	i = 0;
	head = NULL;
	array = ft_split(av[1], ' ');
	if (!array[i])
		exit (0);
	while (array[i] != NULL)
	{
		if (!check_arg(array[i]))
			errormsg();
		tmp = ft_lstnew(array[i++]);
		ft_lstadd_back(&head, tmp);
	}
	return (head);
}

t_list	*fill_stack(int ac, char **av)
{
	t_list	*head;
	t_list	*tmp;
	int		i;

	i = 0;
	head = NULL;
	if (ac == 2)
		return (bracket_arg(av));
	while (++i < ac)
	{
		if (!check_arg(av[i]))
			errormsg();
		tmp = ft_lstnew(av[i]);
		ft_lstadd_back(&head, tmp);
	}
	return (head);
}

t_list	*assign_index(t_list *stack, int i)
{
	t_list	*head;
	t_list	*biggest_value;
	long	max_int;

	head = stack;
	while (--i > 0)
	{
		max_int = LLONG_MIN;
		stack = head;
		while (stack)
		{
			if (stack->value == max_int && !(stack->index))
				return (NULL);
			if (stack->value > max_int && !(stack->index))
			{
				max_int = stack->value;
				biggest_value = stack;
			}
			stack = stack->next;
		}
		if (!(biggest_value->index))
			biggest_value->index = i;
	}
	return (head);
}

t_info	*init_info(t_info *info, t_list *stacka)
{
	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->both_stacks = ft_lstsize(stacka);
	info->median = 0;
	info->btm_half_len = 0;
	info->top_half_len = 0;
	info->stack = 0;
	info->rotates = 0;
	info->start_rr = 1;
	return (info);
}
