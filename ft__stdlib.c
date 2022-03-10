/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__stdlib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:50:57 by jkong             #+#    #+#             */
/*   Updated: 2022/03/10 18:34:03 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_log10(int n)
{
	int	value;

	value = 0;
	while (n)
	{
		value++;
		n /= 10;
	}
	return (value);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*result;
	char	i;

	len = (n < 0) + 1 + _log10(n);
	result = ft_calloc(len + 1, sizeof(char));
	if (result)
	{
		if (n < 0)
			result[0] = '-';
		i = len;
		result[len--] = '\0';
		while (n)
		{
			result[len--] = '0' + n % 10;
			n /= 10;
		}
	}
	return (result);
}
