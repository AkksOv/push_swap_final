/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-10 10:40:19 by jepenoy           #+#    #+#             */
/*   Updated: 2025-01-10 10:40:19 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

t_list	*find_target_r(int n, t_list *b)
{
	t_list	*temp;
	t_list	*res;

	res = NULL;
	temp = b;
	while (1)
	{
		if (temp->data > n)
		{
			if (!res)
				res = temp;
			else if (temp->data < res->data)
				res = temp;
		}
		temp = temp->next;
		if (temp == b)
			break ;
	}
	if (!res)
		res = findmin(b);
	return (res);
}

void	final_rot(t_list **lst)
{
	if (check_pos(*lst, findmin(*lst)->data))
		while (*lst != findmin(*lst))
			rotate(lst, "ra");
	else
		while (*lst != findmin(*lst))
			rrotate(lst, "rra");
}

void	push_b_to_a(t_list **a, t_list **b)
{
	t_list	*target;

	while (*b)
	{
		target = find_target_r((*b)->data, *a);
		if (check_pos(*a, target->data))
		{
			while (1)
			{
				if (target == *a)
					break ;
				rotate(a, "ra");
			}
		}
		else
		{
			while (1)
			{
				if (target == *a)
					break ;
				rrotate(a, "rra");
			}
		}
		push(b, a, "pa");
	}
}
