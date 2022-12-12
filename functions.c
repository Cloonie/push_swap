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
	char	**array;
	int		i;

	i = 0;
	head = NULL;
	if (ac == 2)
	{
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
	while (++i < ac)
	{
		if (!check_arg(av[i]))
			errormsg();
		tmp = ft_lstnew(av[i]);
		ft_lstadd_back(&head, tmp);
	}
	return (head);
}

t_list	*assign_index(t_list *stack)
{
	t_list			*head;
	t_list			*biggest_value;
	long long int	max_int;
	int				index;

	head = stack;
	index = ft_lstsize(stack) + 1;
	while (--index > 0)
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
			biggest_value->index = index;
	}
	return (head);
}

void	set_size(t_list *stack, int size)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		tmp->size = size;
		tmp = tmp->next;
	}
}
