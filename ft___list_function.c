/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft___list_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:03:32 by jkong             #+#    #+#             */
/*   Updated: 2022/03/11 15:45:05 by jkong            ###   ########.fr       */
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

static t_list	*_lst_free(t_list *lst, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	return (lst);
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
			return (_lst_free(result, del));
		if (new)
			new->next = elem;
		else
			result = elem;
		new = elem;
		lst = lst->next;
	}
	return (result);
}
