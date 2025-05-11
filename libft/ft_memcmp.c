/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeonsan.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:44:14 by jyoo              #+#    #+#             */
/*   Updated: 2024/10/24 17:37:38 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	i = 0;
	ucs1 = (unsigned char *)s1;
	ucs2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && (ucs1[i] == ucs2[i]))
		i++;
	if (i < n)
		return (ucs1[i] - ucs2[i]);
	return (0);
}
