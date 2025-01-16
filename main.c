/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 13:56:13 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-27 13:56:13 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "printf/ft_printf.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_list	*lst;

	if (argc < 2)
	{
		return (0);
	}
	if (argc == 2)
		lst = norme2(argv);
	else
		lst = norme(argc, argv);
	if (!lst)
		return (0);
	if (is_sorted(lst))
		return (free_list(lst), 1);
	sort(&lst);
}
