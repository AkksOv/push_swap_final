/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-09 16:05:18 by jepenoy           #+#    #+#             */
/*   Updated: 2025-01-09 16:05:18 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

t_list	*findmax(t_list *lst)
{
	t_list	*temp;
	t_list	*res;

	temp = lst;
	res = lst;
	while (1)
	{
		temp = temp->next;
		if (res->data < temp->data)
			res = temp;
		if (temp == lst)
			break ;
	}
	return (res);
}

t_list	*findmin(t_list *lst)
{
	t_list	*temp;
	t_list	*res;

	temp = lst;
	res = lst;
	while (1)
	{
		temp = temp->next;
		if (res->data > temp->data)
			res = temp;
		if (temp == lst)
			break ;
	}
	return (res);
}

int	calculate_rota_cost(t_rotat **rot)
{
	int	cost;

	cost = 0;
	while ((*rot)->ra && (*rot)->rb)
	{
		cost++;
		(*rot)->ra--;
		(*rot)->rb--;
	}
	while ((*rot)->ra--)
		cost++;
	while ((*rot)->rb--)
		cost++;
	while ((*rot)->rra && (*rot)->rrb)
	{
		cost++;
		(*rot)->rra--;
		(*rot)->rrb--;
	}
	while ((*rot)->rra--)
		cost++;
	while ((*rot)->rrb--)
		cost++;
	free(*rot);
	return (cost);
}

t_list	*find_target(int n, t_list *b)
{
	t_list	*temp;
	t_list	*res;

	res = NULL;
	temp = b;
	while (1)
	{
		if (temp->data < n)
		{
			if (!res)
				res = temp;
			else if (temp->data > res->data)
				res = temp;
		}
		temp = temp->next;
		if (temp == b)
			break ;
	}
	if (!res)
		res = findmax(b);
	return (res);
}

int	check_pos(t_list *lst, int n)
{
	int	size;
	int	i;

	i = 0;
	size = list_len(lst);
	while (lst->data != n)
	{
		lst = lst->next;
		i++;
	}
	if (i > (size / 2))
		return (0);
	else
		return (1);
}
