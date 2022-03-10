/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:50:00 by jkong             #+#    #+#             */
/*   Updated: 2022/03/10 18:53:57 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char const	*src;
	size_t		dst_len;
	char		*result;

	result = NULL;
	if (start < ft_strlen(s))
	{
		src = &s[start];
		dst_len = ft_strlen(src);
		if (dst_len > len)
			dst_len = len;
		result = ft_calloc(dst_len + 1, sizeof(char));
		if (result)
		{
			ft_memcpy(result, src, dst_len);
			result[dst_len] = '\0';
		}
	}
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	src1_len;
	size_t	src2_len;
	char	*result;

	src1_len = ft_strlen(s1);
	src2_len = ft_strlen(s2);
	result = ft_calloc(src1_len + src2_len + 1, sizeof(char));
	if (result)
	{
		ft_memcpy(result, s1, src1_len);
		ft_memcpy(result + src1_len, s2, src2_len);
		result[src1_len + src2_len] = '\0';
	}
	return (result);
}

static int	_contains(char c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	s2_start;
	size_t			s2_len;

	s2_start = 0;
	s2_len = ft_strlen(s1);
	if (s2_len > 0)
	{
		while (_contains(s1[s2_len - 1], set))
			--s2_len;
		while (_contains(s1[s2_start++], set))
			--s2_len;
	}
	return (ft_substr(s1, s2_start, s2_len));
}
