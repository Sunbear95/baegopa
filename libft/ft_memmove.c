/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeonsan.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:29:47 by jyoo              #+#    #+#             */
/*   Updated: 2024/10/28 21:03:22 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ucdest;
	unsigned char	*ucsource;
	size_t			i;

	ucdest = (unsigned char *) dest;
	ucsource = (unsigned char *)src;
	i = -1;
	if (src < dest)
	{
		while (++i < n)
			ucdest[n - i -1] = ucsource[n - i -1];
		return ((void *)ucdest);
	}
	else
		return (ft_memcpy(dest, src, n));
}
