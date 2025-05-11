/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:11:04 by jyoo              #+#    #+#             */
/*   Updated: 2024/10/28 21:01:03 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*uctemp;

	if (nmemb != 0 && (size > SIZE_MAX / nmemb))
		return (0);
	uctemp = (unsigned char *) malloc(size * nmemb);
	if (!uctemp)
		return (0);
	ft_bzero((void *)uctemp, nmemb * size);
	return ((void *)uctemp);
}
