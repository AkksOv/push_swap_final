/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-31 10:46:28 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-31 10:46:28 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include "../printf/ft_printf.h"
#include <limits.h>

void	reset_rota(t_rotat **rot)
{
	(*rot)->ra = 0;
	(*rot)->rb = 0;
	(*rot)->rra = 0;
	(*rot)->rrb = 0;
}

int	calculate_cost(t_list *a, t_list *b, int aval)
{
	t_list	*target;
	t_list	*atest;
	t_rotat	*rotat;

	rotat = malloc(sizeof(t_rotat));
	reset_rota(&rotat);
	atest = find_number(a, aval);
	target = find_target(atest->data, b);
	calculate_rota(a, atest, &rotat, 'A');
	calculate_rota(b, target, &rotat, 'B');
	return (calculate_rota_cost(&rotat));
}

void	push_cheapest(t_list **a, t_list **b, t_list *cheapest)
{
	t_list	*target;
	t_rotat	*rota;

	rota = malloc(sizeof(t_rotat));
	reset_rota(&rota);
	target = find_target(cheapest->data, *b);
	calculate_rota(*a, cheapest, &rota, 'A');
	calculate_rota(*b, target, &rota, 'B');
	do_rota(a, b, &rota);
	push(a, b, "pb");
	free(rota);
}

void	find_cheapest(t_list **a, t_list **b)
{
	t_list	*temp;
	int		i;
	t_list	*cheapest;
	int		cost;

	cost = INT_MAX;
	i = list_len(*a);
	temp = *a;
	while (i--)
	{
		if (cost > calculate_cost(*a, *b, temp->data))
		{
			cost = calculate_cost(*a, *b, temp->data);
			cheapest = temp;
		}
		temp = temp->next;
	}
	if (!cheapest)
		cheapest = temp;
	push_cheapest(a, b, cheapest);
}

void	sort(t_list **a)
{
	t_list	*b;

	b = NULL;
	if (list_len(*a) <= 3)
	{
		if (list_len(*a) == 3)
			sort_three(a);
		else if (list_len(*a) == 2)
			sort_two(a);
		free_list(*a);
		return ;
	}
	push(a, &b, "pb");
	push(a, &b, "pb");
	while (list_len(*a) > 3)
		find_cheapest(a, &b);
	if (list_len(*a) == 3)
		sort_three(a);
	push_b_to_a(a, &b);
	final_rot(a);
	free_list(*a);
	free_list(b);
}
