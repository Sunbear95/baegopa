/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:36:46 by jyoo              #+#    #+#             */
/*   Updated: 2024/10/27 15:35:28 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ucdest;
	unsigned char	*ucsource;

	if (!dest && !src)
		return (0);
	ucdest = (unsigned char *)dest;
	ucsource = (unsigned char *)src;
	i = -1;
	while (++i < n)
		*(ucdest + i) = *(ucsource + i);
	return ((void *)ucdest);
}
