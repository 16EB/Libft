/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__stdlib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:50:57 by jkong             #+#    #+#             */
/*   Updated: 2022/03/11 16:43:13 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_nbrlen(int n)
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

char	*ft_itoa(int n)
{
	size_t	len;
	char	*result;
	size_t	i;

	len = (n < 0) + 1 + _nbrlen(n);
	result = ft_calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	i = len;
	result[i--] = '\0';
	if (!n)
		result[i--] = '0';
	while (n)
	{
		result[i--] = '0' + ((!(n < 0) << 1) - 1) * (n % 10);
		n /= 10;
	}
	return (result);
}
