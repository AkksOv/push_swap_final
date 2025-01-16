/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-10 11:32:32 by jepenoy           #+#    #+#             */
/*   Updated: 2025-01-10 11:32:32 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"
#include <unistd.h>
#include "../printf/ft_printf.h"
#include "GetNextLine/get_next_line.h"

void	check_noargs(void)
{
	char	*temp;

	temp = get_next_line(0);
	if (temp)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(temp);
}

void	double_rainbow(t_list **lst, t_list **lst2, int r)
{
	if (r)
	{
		rotate(lst, NULL);
		rotate(lst2, NULL);
	}
	else
	{
		rrotate(lst, NULL);
		rrotate(lst2, NULL);
	}
}

int	do_instructions(char *s, t_list **lst, t_list **lst2)
{
	if (ft_strncmp(s, "rrr", 3) == 0)
		double_rainbow(lst, lst2, 0);
	else if (ft_strncmp(s, "rra", 3) == 0)
		rrotate(lst, NULL);
	else if (ft_strncmp(s, "rrb", 3) == 0)
		rrotate(lst2, NULL);
	else if (ft_strncmp(s, "rr", 2) == 0)
		double_rainbow(lst, lst2, 1);
	else if (ft_strncmp(s, "ra", 2) == 0)
		rotate(lst, NULL);
	else if (ft_strncmp(s, "rb", 2) == 0)
		rotate(lst2, NULL);
	else if (ft_strncmp(s, "pa", 2) == 0)
		push(lst2, lst, NULL);
	else if (ft_strncmp(s, "pb", 2) == 0)
		push(lst, lst2, NULL);
	else if (ft_strncmp(s, "sa", 2) == 0)
		swap(lst, NULL);
	else if (ft_strncmp(s, "sb", 2) == 0)
		swap(lst2, NULL);
	else
		return (ft_printf("Error\n"));
	return (0);
}

int	set_instructions(t_list **lst, t_list **lst2)
{
	char	*temp;

	temp = get_next_line(0);
	while (temp)
	{
		if (do_instructions(temp, lst, lst2))
		{
			free(temp);
			free_list(*lst);
			free_list(*lst2);
			return (0);
		}
		free(temp);
		temp = get_next_line(0);
	}
	if (temp)
		free(temp);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*lst;
	t_list	*lst2;

	lst2 = NULL;
	if (argc < 2)
	{
		check_noargs();
		return (0);
	}
	else if (argc == 2)
	{
		if (!argv[1][0])
			check_noargs();
		lst = norme2(argv);
	}
	else
		lst = norme(argc, argv);
	if (!lst)
		return (0);
	if (!set_instructions(&lst, &lst2))
		return (0);
	check_logic(lst, lst2);
}
