/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeonsan.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:18:49 by jyoo              #+#    #+#             */
/*   Updated: 2024/10/28 21:04:10 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	char	*temp;

	temp = (char *)src;
	copy = (char *)malloc(sizeof(char) * ft_strlen(temp) + 1);
	if (!temp || !copy)
		return (0);
	ft_strlcpy(copy, (char *)src, ft_strlen(temp) + 1);
	return (copy);
}
