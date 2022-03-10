/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__stdlib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:50:57 by jkong             #+#    #+#             */
/*   Updated: 2022/03/10 22:36:29 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_log10(int n)
{
	int	value;

	value = !n;
	while (n)
	{
		value++;
		n /= 10;
	}
	return (value - 1);
}

static int	_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*result;
	size_t	i;

	len = (n < 0) + 1 + _log10(n);
	result = ft_calloc(len + 1, sizeof(char));
	if (result)
	{
		if (n < 0)
			result[0] = '-';
		i = len;
		result[i--] = '\0';
		if (!n)
			result[i--] = '0';
		while (n)
		{
			result[i--] = '0' + _abs(n % 10);
			n /= 10;
		}
	}
	return (result);
}
