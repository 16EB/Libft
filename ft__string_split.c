/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__string_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:31:32 by jkong             #+#    #+#             */
/*   Updated: 2022/07/04 14:05:27 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_split_elem(char **ptr, char const *s, char c)
{
	size_t	i;
	char	*elem;

	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			i = 0;
			while (s[i] && s[i] != c)
				i++;
			elem = ft_calloc(i + 1, sizeof(char));
			*ptr++ = elem;
			if (!elem)
				return (0);
			while (*s && *s != c)
				*elem++ = *s++;
		}
	}
	return (1);
}

static char	**_split_free(char **ptr)
{
	char	**it;

	if (ptr)
	{
		it = ptr;
		while (*it)
			free(*it++);
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
	}
	result = ft_calloc(count + 1, sizeof(char *));
	if (!result || !_split_elem(result, s, c))
		return (_split_free(result));
	return (result);
}
