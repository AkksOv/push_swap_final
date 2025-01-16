/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-10 10:21:55 by jepenoy           #+#    #+#             */
/*   Updated: 2025-01-10 10:21:55 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../printf/ft_printf.h"

int	check_order(t_list *lst)
{
	t_list	*temp;
	int		n;

	n = findmin(lst)->data;
	temp = lst;
	while (1)
	{
		if (temp->data == n)
			break ;
		temp = temp->next;
	}
	lst = temp;
	temp = temp->next;
	while (temp != lst)
	{
		if (temp->data > n)
			n = temp->data;
		else
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	sort_three(t_list **lst)
{
	t_list	*min;

	min = findmin(*lst);
	if (!check_order(min))
		swap(lst, "sa");
	while (*lst != findmin(*lst))
	{
		if (min == (*lst)->prev)
			rrotate(lst, "rra");
		else
			rotate(lst, "ra");
	}
}

void	sort_two(t_list **lst)
{
	if ((*lst)->data > (*lst)->next->data)
		ft_printf("sa\n");
}
