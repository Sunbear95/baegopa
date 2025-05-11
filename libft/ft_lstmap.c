/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:48:42 by jyoo              #+#    #+#             */
/*   Updated: 2024/10/28 13:32:18 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nllist;
	t_list	*nlist;

	if (!lst || !f)
		return (0);
	nllist = 0;
	while (lst)
	{
		nlist = ft_lstnew(f(lst -> content));
		if (!nlist)
		{
			ft_lstclear(&nllist, del);
			return (0);
		}
		ft_lstadd_back(&nllist, nlist);
		lst = lst -> next;
	}
	return (nllist);
}
