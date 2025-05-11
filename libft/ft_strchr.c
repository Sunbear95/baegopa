/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeonsan.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:35:13 by jyoo              #+#    #+#             */
/*   Updated: 2024/10/28 21:04:03 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if ((char)c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (s[i] != 0 && s[i] != (char)c)
		i++;
	if (s[i] == 0)
		return (0);
	return ((char *)(s + i));
	return (0);
}
