/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:48:05 by jyoo              #+#    #+#             */
/*   Updated: 2024/10/28 13:32:02 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*temp;

	if (!lst)
		return ;
	p = *lst;
	while (p)
	{
		temp = p -> next;
		ft_lstdelone(p, del);
		p = temp;
	}
	*lst = 0;
}
