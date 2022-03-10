/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__string_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:31:32 by jkong             #+#    #+#             */
/*   Updated: 2022/03/10 17:03:04 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_split_elem(char **ptr, char const *s, char c)
{
	int		i;
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
			if (elem == NULL)
				return (0);
			while (*s && *s != c)
				*elem++ = *s++;
			*elem = '\0';
		}
	}
	*ptr = NULL;
	return (1);
}

static char	**_split_free(char **ptr)
{
	char	**tab;

	if (ptr)
	{
		tab = ptr;
		while (*tab)
		{
			free(*tab);
			*tab++ = NULL;
		}
		free(ptr);
		ptr = NULL;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;
	int		on_elem;
	int		i;

	count = 0;
	on_elem = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			on_elem = 0;
		else if (!on_elem)
		{
			count++;
			on_elem = 1;
		}
		i++;
	}
	result = ft_calloc(count + 1, sizeof(char *));
	if (result == NULL || !_split_elem(result, s, c))
		return (_split_free(result));
	return (result);
}
