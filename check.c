/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:14:42 by mliew             #+#    #+#             */
/*   Updated: 2022/12/23 03:19:39 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *arg)
{
	long	nbr;

	nbr = ft_atoi(arg);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	else
		return (1);
}

int	check_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i + 1] == '\0')
			return (0);
		i++;
	}
	if (!arg[i])
		return (0);
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

int	check_chunk(t_list **stack, t_info *info)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if ((info->stack == 'a' && tmp->index < info->median)
				|| (info->stack == 'b' && tmp->index >= info->median))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}