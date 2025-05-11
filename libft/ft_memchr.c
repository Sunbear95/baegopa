/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeonsan.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:30:05 by jyoo              #+#    #+#             */
/*   Updated: 2024/10/24 23:00:30 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ucs;
	unsigned char	ucc;
	size_t			i;

	ucs = (unsigned char *) s;
	ucc = (unsigned char ) c;
	i = 0;
	while ((i < n) && (ucs[i] != ucc))
		i++;
	if (i == n)
		return (0);
	return ((void *)(s + i));
}
