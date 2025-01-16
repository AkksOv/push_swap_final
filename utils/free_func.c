/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-10 14:53:16 by jepenoy           #+#    #+#             */
/*   Updated: 2025-01-10 14:53:16 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_list(t_list *lst)
{
	int		tempi;
	t_list	*temp;

	if (!lst)
		return (free(lst));
	temp = lst;
	while (lst)
	{
		tempi = temp->data;
		temp = temp->next;
		delete_node(&lst, tempi);
	}
	free(lst);
}
