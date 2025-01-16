/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 09:27:56 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-27 09:27:56 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../printf/ft_printf.h"
#include <stdlib.h>

int	list_len(t_list *head)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = head->next;
	while (i++, temp != head)
		temp = temp->next;
	return (i);
}

void	swap(t_list **head, char *type)
{
	t_list	*temp;
	int		tdata;

	if (!head || list_len(*head) <= 1)
		return ;
	temp = *head;
	tdata = temp->data;
	temp->data = temp->next->data;
	temp->next->data = tdata;
	if (type)
		ft_printf("%s\n", type);
}

void	push(t_list **a, t_list **b, char *type)
{
	t_list	*tempa;

	if (!a || !*a)
		return ;
	if (!b)
	{
		tempa = *a;
		*b = new_node(tempa->data);
		delete_node(a, tempa->data);
	}
	else
	{
		tempa = *a;
		insert_begin(b, tempa->data);
		delete_node(a, tempa->data);
	}
	if (type)
		ft_printf("%s\n", type);
}

void	rotate(t_list **head, char *type)
{
	if (!head || (*head)->next == *head)
		return ;
	*head = (*head)->next;
	if (type)
		ft_printf("%s\n", type);
}

void	rrotate(t_list **head, char *type)
{
	if (!head || (*head)->next == *head)
		return ;
	*head = (*head)->prev;
	if (type)
		ft_printf("%s\n", type);
}
