/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft___list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:03:32 by jkong             #+#    #+#             */
/*   Updated: 2022/03/11 16:46:56 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	if (result == NULL)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*result;

	result = NULL;
	while (lst)
	{
		result = lst;
		lst = lst->next;
	}
	return (result);
}
