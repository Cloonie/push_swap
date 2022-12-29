/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:38:01 by mliew             #+#    #+#             */
/*   Updated: 2022/12/29 16:40:45 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head, int c)
{
	t_list	*tmp;
	t_list	*next;

	if (!(*head) || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	next = (*head)->next;
	(*head)->next = tmp;
	tmp->next = next;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	rotate(t_list **head, int c)
{
	t_list	*tmp;
	t_list	*tail;

	if (!(*head) || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tail = ft_lstlast(*head);
	tail->next = tmp;
	tmp->next = NULL;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	reverse_rotate(t_list **head, int c)
{
	t_list	*tmp;
	t_list	*tail;

	if (!(*head) || !(*head)->next)
		return ;
	tail = ft_lstlast(*head);
	tmp = *head;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	tail->next = *head;
	*head = tail;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	push(t_list **from, t_list **pushto, int c)
{
	t_list	*tmp;

	if (!(*from))
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *pushto;
	*pushto = tmp;
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}
