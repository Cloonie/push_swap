/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/10/17 21:43:39 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errormsg(void)
{
	write(2, "Error\n", 6);
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
	return (head);
}

void	check_dup(t_list *stack)
{
	t_list *tmp;

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

void	assign_index(t_list *stack)
{
	t_list	*tmp;
	int		i;
	
	tmp = stack;
	i = 1;
	tmp->index = i;
	tmp = tmp->next;
}

int	main(int ac, char **av)
{
	t_list	*stacka;

	stacka = fill_stack(ac, av);
	check_dup(stacka);
	assign_index(stacka);
	while (stacka)
	{
		printf("Value: %d, Index: %d, Pos: %d\n", stacka->value, stacka->index, stacka->pos);
		stacka = stacka->next;
	}
}
