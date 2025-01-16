/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-31 09:48:56 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-31 09:48:56 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../printf/ft_printf.h"

int	is_int(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '+' || s[0] == '-')
		i++;
	if (s[0] == '-')
	{
		if (!check_int_min(s))
			return (0);
	}
	else
	{
		if (!check_int_max(s))
			return (0);
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_doubles_split(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_doubles(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(int argc, char *argv[], int i)
{
	while (i < argc)
	{
		if (!is_int(argv[i]))
			return (0);
		i++;
	}
	if (!check_doubles(argc, argv))
		return (0);
	return (1);
}

int	check_args_split(int argc, char *argv[], int i)
{
	while (i < argc)
	{
		if (!is_int(argv[i]))
			return (0);
		i++;
	}
	if (!check_doubles_split(argc, argv))
		return (0);
	return (1);
}
