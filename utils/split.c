/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-09 13:41:41 by jepenoy           #+#    #+#             */
/*   Updated: 2025-01-09 13:41:41 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int	i;
	int	res;

	if (c == '\0')
		return (1);
	res = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c)
			i++;
		res++;
	}
	return (res);
}

static char	*ft_set_strings(const char *str, int f, int l)
{
	char			*temp;
	unsigned int	i;
	unsigned int	n;

	temp = malloc(sizeof(char) * ((l - f) + 2));
	if (temp == NULL)
		return (0);
	i = 0;
	n = (l - f) + 1;
	while (i < n)
	{
		temp[i] = str[f];
		f++;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

static char	**free_allocated_memory(char **res, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(res[i++]);
	free(res);
	return (0);
}

static char	**ft_maker(char **res, char const *s, int count, char const c)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	end = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			end = i++;
		if (start <= end)
			res[count++] = ft_set_strings(s, start, end);
		if (count > 0 && res[count - 1] == NULL)
			return (free_allocated_memory(res, count - 1));
	}
	res[count] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		count;

	count = 0;
	if (!s)
		return (0);
	res = malloc(sizeof(char *) * (count_words(s, c) + 2));
	if (res == NULL)
		return (0);
	return (ft_maker(res, s, count, c));
}
