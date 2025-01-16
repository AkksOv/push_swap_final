/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:34:13 by jepenoy           #+#    #+#             */
/*   Updated: 2024/10/30 10:41:53 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_converthexa(unsigned int n, int uppercase);
int	ft_converthexalong(unsigned long int n);
int	ft_printpointer(void *p);
int	ft_putunsigned(unsigned int n, int fd);
int	ft_printf(const char *format, ...);

#endif