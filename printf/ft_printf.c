/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:18:18 by jepenoy           #+#    #+#             */
/*   Updated: 2024/11/18 13:36:59 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	typeselect(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (format == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (format == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (format == 'u')
		return (ft_putunsigned((unsigned int)va_arg(args, unsigned int), 1));
	if (format == '%')
		return (ft_putchar_fd('%', 1));
	if (format == 'x')
		return (ft_converthexa(va_arg(args, int), 0));
	if (format == 'X')
		return (ft_converthexa(va_arg(args, int), 1));
	if (format == 'p')
		return (ft_printpointer(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += typeselect(*format, args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
