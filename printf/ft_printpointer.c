/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:00:16 by jepenoy           #+#    #+#             */
/*   Updated: 2024/10/30 10:34:34 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(void *p)
{
	unsigned long int	addr;
	int					i;

	i = 0;
	if (!p)
		i += ft_putstr_fd("(nil)", 1);
	else
	{
		addr = (unsigned long int) p;
		i += ft_putstr_fd("0x", 1);
		i += ft_converthexalong(addr);
	}
	return (i);
}
