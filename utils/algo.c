/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-31 12:02:23 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-31 12:02:23 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../printf/ft_printf.h"

static void	do_rota_norm(t_list **a, t_list **b, t_rotat **rot)
{
	while ((*rot)->rra && (*rot)->rrb)
	{
		rrotate(a, NULL);
		rrotate(b, "rrr");
		(*rot)->rra--;
		(*rot)->rrb--;
	}
	while ((*rot)->rra)
	{
		rrotate(a, "rra");
		(*rot)->rra--;
	}
	while ((*rot)->rrb)
	{
		rrotate(b, "rrb");
		(*rot)->rrb--;
	}
}

void	do_rota(t_list **a, t_list **b, t_rotat **rot)
{
	while ((*rot)->ra && (*rot)->rb)
	{
		rotate(a, NULL);
		rotate(b, "rr");
		(*rot)->ra--;
		(*rot)->rb--;
	}
	while ((*rot)->ra)
	{
		rotate(a, "ra");
		(*rot)->ra--;
	}
	while ((*rot)->rb)
	{
		rotate(b, "rb");
		(*rot)->rb--;
	}
	do_rota_norm(a, b, rot);
}

void	calculate_rota(t_list *lst, t_list *to_find, t_rotat **rot, char let)
{
	if (check_pos(lst, to_find->data))
	{
		while (lst != to_find)
		{
			lst = lst->next;
			if (let == 'A')
				(*rot)->ra++;
			else
				(*rot)->rb++;
		}
	}
	else
	{
		while (lst != to_find)
		{
			lst = lst->prev;
			if (let == 'A')
				(*rot)->rra++;
			else
				(*rot)->rrb++;
		}
	}
}
