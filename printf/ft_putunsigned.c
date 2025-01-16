/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:01:33 by jepenoy           #+#    #+#             */
/*   Updated: 2024/10/30 10:40:06 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n, int fd)
{
	int	i;

	i = 1;
	if (n >= 10)
		i += ft_putunsigned(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
	return (i);
}
