/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype_letterconv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:33:49 by jkong             #+#    #+#             */
/*   Updated: 2022/03/10 21:58:50 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_conv(int c, int (*cond)(int), int from, int to)
{
	if (cond(c))
		return (to + (c - from));
	return (c);
}

static int	_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

static int	_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

int	ft_toupper(int c)
{
	return (_conv(c, _islower, 'a', 'A'));
}

int	ft_tolower(int c)
{
	return (_conv(c, _isupper, 'A', 'a'));
}
