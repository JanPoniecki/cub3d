/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:48:08 by bkotwica          #+#    #+#             */
/*   Updated: 2024/03/20 10:14:17 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst -> content));
	if (!new)
		return (NULL);
	tmp = new;
	lst = lst -> next;
	while (lst)
	{
		tmp -> next = ft_lstnew(f(lst -> content));
		if (!tmp -> next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		tmp = tmp -> next;
		lst = lst -> next;
	}
	return (new);
}
