/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converthexalong.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:58:53 by jepenoy           #+#    #+#             */
/*   Updated: 2024/10/30 10:33:55 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_converthexalong(unsigned long int n)
{
	char	*hexbase;
	int		i;

	i = 1;
	hexbase = "0123456789abcdef";
	if (n >= 16)
	{
		i += ft_converthexalong(n / 16);
	}
	ft_putchar_fd(hexbase[n % 16], 1);
	return (i);
}
