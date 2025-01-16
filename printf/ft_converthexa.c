/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converthexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:57:57 by jepenoy           #+#    #+#             */
/*   Updated: 2024/10/29 16:58:52 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_converthexa(unsigned int n, int uppercase)
{
	char	*hexbase;
	int		i;

	i = 1;
	if (!uppercase)
		hexbase = "0123456789abcdef";
	else
		hexbase = "0123456789ABCDEF";
	if (n >= 16)
	{
		i += ft_converthexa(n / 16, uppercase);
	}
	ft_putchar_fd(hexbase[n % 16], 1);
	return (i);
}
