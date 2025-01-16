/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:45:04 by jepenoy           #+#    #+#             */
/*   Updated: 2024/10/29 16:40:42 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		i += ft_putstr_fd("(null)", 1);
	else
	{
		while (s[i])
			ft_putchar_fd(s[i++], fd);
	}
	return (i);
}
