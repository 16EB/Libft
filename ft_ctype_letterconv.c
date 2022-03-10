/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype_letterconv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:33:49 by jkong             #+#    #+#             */
/*   Updated: 2022/03/10 15:59:01 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	_conv(int c, int from, int to)
{
	return (to + (c - from));
}

int	ft_toupper(int c)
{
	return (_conv(c, 'a', 'A'));
}

int	ft_tolower(int c)
{
	return (_conv(c, 'A', 'a'));
}
