/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:05:42 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/07 12:07:17 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_w(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else if (str[i] == c)
			i++;
	}
	return (count);
}

static char	**free_ptr(char **str, int n)
{
	while (n > 0)
	{
		free(str[--n]);
	}
	free(str);
	return (0);
}

char	**split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		n;

	ptr = (char **)malloc((ft_count_w(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	n = 0;
	while (s && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (s[i] != c && s[i] != '\0' && j++ > -1)
			i++;
		ptr[n++] = ft_substr(s, i - j, j);
		if (ptr[n - 1] == NULL)
			return (free_ptr(ptr, n));
	}
	ptr[n] = NULL;
	return (ptr);
}
