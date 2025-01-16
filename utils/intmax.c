/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 10:51:03 by jepenoy           #+#    #+#             */
/*   Updated: 2025-01-16 10:51:03 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_int_max(char *str)
{
	int		i;
	char	*max;

	max = "2147483647";
	i = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (i > 10)
		return (0);
	else if (i == 10)
	{
		i = 0;
		while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] > max[i])
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_int_min(char *str)
{
	int		i;
	char	*min;

	min = "-2147483648";
	i = 0;
	while (str[i])
	{
		if (str[i] > min[i])
			return (0);
		i++;
	}
	return (1);
}
