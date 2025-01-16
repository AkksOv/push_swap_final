/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-13 16:59:14 by jepenoy           #+#    #+#             */
/*   Updated: 2025-01-13 16:59:14 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../printf/ft_printf.h"
#include "utils.h"

t_list	*fill_list_split(int c, char *arr[])
{
	int		i;
	t_list	*lst;

	i = 1;
	lst = new_node(ft_atoi(arr[0]));
	if (!lst)
		return (0);
	while (i < c)
	{
		insert_end(&lst, ft_atoi(arr[i]));
		i++;
	}
	return (lst);
}

int	is_sorted(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (1)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
		if (temp == lst->prev)
			break ;
	}
	return (1);
}

t_list	*norme2(char *argv[])
{
	char	**args;
	t_list	*lst;

	args = ft_split(argv[1], ' ');
	if (!args)
		return (0);
	if (!args[0])
	{
		free_split(args);
		return (NULL);
	}
	if (!check_args_split(count_args(args), args, 0))
		return (free_split(args), ft_printf("Error\n"), NULL);
	lst = fill_list_split(count_args(args), args);
	free_split(args);
	if (!lst)
		return (NULL);
	return (lst);
}

t_list	*norme(int argc, char *argv[])
{
	t_list	*lst;

	if (!check_args(argc, argv, 1))
		return (ft_printf("Error\n"), NULL);
	lst = fill_list(argc, argv);
	if (!lst)
		return (NULL);
	return (lst);
}

void	check_logic(t_list *lst, t_list *lst2)
{
	t_list	*temp;

	temp = lst;
	if (lst2 && list_len(lst2) != 0)
	{
		ft_printf("KO\n");
		return (free_list(lst), free_list(lst2));
	}
	while (1)
	{
		if (temp->data > temp->next->data)
		{
			ft_printf("KO\n");
			return (free_list(lst), free_list(lst2));
		}
		temp = temp->next;
		if (temp == lst->prev)
			break ;
	}
	ft_printf("OK\n");
	free_list(lst);
	free_list(lst2);
}
