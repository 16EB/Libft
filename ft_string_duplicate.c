/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_duplicate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:04:25 by jkong             #+#    #+#             */
/*   Updated: 2022/07/04 14:14:52 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const size_t	len = ft_strlen(s1) + 1;
	char *const		s2 = ft_calloc(len, sizeof(char));

	if (!s2)
		return (NULL);
	return (ft_memcpy(s2, s1, len));
}
