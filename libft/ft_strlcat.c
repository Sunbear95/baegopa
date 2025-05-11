/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeonsan.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:49:08 by jyoo              #+#    #+#             */
/*   Updated: 2024/10/28 21:04:26 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	de_size;
	size_t	sr_size;
	size_t	i;

	i = 0;
	de_size = ft_strlen(dest);
	sr_size = ft_strlen(src);
	if (de_size >= size)
		return (sr_size + size);
	while (de_size + i + 1 < size && src[i] != 0)
	{
		dest[de_size + i] = src[i];
		i++;
	}
	dest[de_size + i] = '\0';
	return (de_size + sr_size);
}
