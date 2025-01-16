/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:01:23 by jepenoy           #+#    #+#             */
/*   Updated: 2024/10/30 10:39:17 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = 1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (n < 0)
	{
		i++;
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n >= 10)
		i += ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
	return (i);
}
