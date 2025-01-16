/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-31 09:36:45 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-31 09:36:45 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	i;
	int	negative;

	negative = 1;
	i = 0;
	res = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negative = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	return (res * negative);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] == s2[i] && s1[i])
		i++;
	if (i == n)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

t_list	*fill_list(int c, char *arr[])
{
	int		i;
	t_list	*lst;

	i = 2;
	lst = new_node(ft_atoi(arr[1]));
	if (!lst)
		return (0);
	while (i < c)
	{
		insert_end(&lst, ft_atoi(arr[i]));
		i++;
	}
	return (lst);
}

int	count_args(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

t_list	*find_number(t_list *a, int n)
{
	t_list	*temp;

	temp = a;
	while (1)
	{
		if (temp->data == n)
			return (temp);
		temp = temp->next;
		if (temp == a)
			break ;
	}
	return (temp);
}
