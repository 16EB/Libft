/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:50:00 by jkong             #+#    #+#             */
/*   Updated: 2022/07/04 14:10:20 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char const	*src;
	size_t		src_len;
	size_t		dst_len;
	char		*result;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start > src_len)
		start = src_len;
	src = &s[start];
	dst_len = ft_strlen(src);
	if (dst_len > len)
		dst_len = len;
	result = ft_calloc(dst_len + 1, sizeof(char));
	if (!result)
		return (NULL);
	return (ft_memcpy(result, src, dst_len));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	src1_len;
	size_t	src2_len;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	src1_len = ft_strlen(s1);
	src2_len = ft_strlen(s2);
	result = ft_calloc(src1_len + src2_len + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, src1_len);
	ft_memcpy(result + src1_len, s2, src2_len);
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	s2_start;
	size_t			s2_len;

	if (!s1 || !set)
		return (NULL);
	s2_start = 0;
	s2_len = ft_strlen(s1);
	if (s2_len > 0)
	{
		while (ft_strchr(set, s1[s2_len - 1]))
			--s2_len;
		while (ft_strchr(set, s1[s2_start]))
		{
			s2_start++;
			--s2_len;
		}
	}
	return (ft_substr(s1, s2_start, s2_len));
}
