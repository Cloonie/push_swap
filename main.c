/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/09/28 18:43:57 by mliew            ###   ########.fr       */
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
	int		j = 0;

	i = 0;
	head = NULL;
	if (ac == 2)
	{
		array = ft_split(av[1], ' ');
		while (array[j] != NULL)
		{
			if (check_arg(array[j]) != 1)
				errormsg();
			tmp = ft_lstnew(array[j++]);
			ft_lstadd_back(&head, tmp);
		}
		return (head);
	}
	while (++i < ac)
	{
		if (check_arg(av[i]) != 1)
			errormsg();
		tmp = ft_lstnew(av[i]);
		ft_lstadd_back(&head, tmp);
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_list	*stacka;

	stacka = fill_stack(ac, av);
	while (stacka)
	{
		printf("%d\n", stacka->value);
		stacka = stacka->next;
	}
}
