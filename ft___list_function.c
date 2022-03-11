/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft___list_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:03:32 by jkong             #+#    #+#             */
/*   Updated: 2022/03/11 16:41:11 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new;
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	result = NULL;
	new = NULL;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (elem == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		if (new)
			new->next = elem;
		else
			result = elem;
		new = elem;
		lst = lst->next;
	}
	return (result);
}
