/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/10/25 19:02:01 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errormsg(void)
{
	write(2, "Error\n", 6);
	// system("leaks push_swap");
	exit (0);
}

int	check_num(char *arg)
{
	long long int	nbr;

	nbr = ft_atoi(arg);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	else
		return (1);
}

int	check_arg(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i + 1] == '\0')
			return (0);
		i++;
	}
	if (arg[i] == '0' && arg[i + 1] != '\0')
		return (0);
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else
			return (0);
	}
	return (check_num(arg));
}

t_list	*fill_stack(int ac, char **av)
{
	int		i;
	t_list	*head;
	t_list	*tmp;
	char	**array;

	i = 0;
	head = NULL;
	if (ac == 2)
	{
		array = ft_split(av[1], ' ');
		while (array[i] != NULL)
		{
			if (check_arg(array[i]) != 1)
				errormsg();
			tmp = ft_lstnew(array[i++]);
			tmp->pos = i;
			ft_lstadd_back(&head, tmp);
		}
		head->size = i + 1;
		return (head);
	}
	while (++i < ac)
	{
		if (check_arg(av[i]) != 1)
			errormsg();
		tmp = ft_lstnew(av[i]);
		tmp->pos = i;
		ft_lstadd_back(&head, tmp);
	}
	head->size = i;
	return (head);
}

void	check_dup(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	if (stack == NULL)
		return ;
	while (tmp->next != NULL)
	{
		if (stack->value == tmp->next->value)
			errormsg();
		tmp = tmp->next;
	}
	check_dup(stack->next);
}

t_list	*assign_index(t_list *stack, int index)
{
	t_list			*head;
	t_list			*biggest_value;
	long long int	max_int;

	head = stack;
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

void	sort_stacks(t_list *stacka, t_list *stackb, int size)
{
	if (size == 4)
		swap_a(stacka);
	(void)stackb;
}

int	main(int ac, char **av)
{
	t_list	*stacka;
	t_list	*stackb;
	t_list	*tmp;
	int		size;

	stackb = NULL;
	if (ac == 1)
		return (0);
	stacka = fill_stack(ac, av);
	check_dup(stacka);
	size = stacka->size;
	assign_index(stacka, size);
	tmp = stacka;
	while (tmp)
	{
		printf("Value: %d, Index: %d, Pos: %d\n",
			tmp->value, tmp->index, tmp->pos);
		tmp = tmp->next;
	}
	printf("\n");
	sort_stacks(stacka, stackb, size);
	tmp = stacka;
	while (tmp)
	{
		printf("Value: %d, Index: %d, Pos: %d\n",
			tmp->value, tmp->index, tmp->pos);
		tmp = tmp->next;
	}
}
