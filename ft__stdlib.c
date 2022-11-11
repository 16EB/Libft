/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__stdlib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:50:57 by jkong             #+#    #+#             */
/*   Updated: 2022/07/04 13:55:36 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	_nbrlen(int n)
{
	size_t	value;

	value = 0;
	if (n == 0)
		value++;
	while (n != 0)
	{
		value++;
		n /= 10;
	}
	if (n < 0)
		value++;
	return (value);
}

char	*ft_itoa(int n)
{
	const int		sign = n < 0;
	const size_t	len = _nbrlen(n);
	char *const		result = ft_calloc(len + 1, sizeof(char));
	size_t			i;

	if (!result)
		return (NULL);
	i = len;
	result[i--] = '\0';
	if (n == 0)
		result[i--] = '0';
	while (n != 0)
	{
		result[i--] = '0' + (1 - (sign << 1)) * (n % 10);
		n /= 10;
	}
	if (sign)
		result[i--] = '-';
	return (result);
}
