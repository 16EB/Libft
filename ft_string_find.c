/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:00:32 by jkong             #+#    #+#             */
/*   Updated: 2022/03/10 18:59:01 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s != (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		--i;
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	return (NULL);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	n = ft_strlen(needle);
	if (n == 0)
		return ((char *)haystack);
	while (*haystack && len >= n)
	{
		if (ft_strncmp(haystack, needle, n) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
