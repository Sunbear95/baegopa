/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:55:17 by jyoo              #+#    #+#             */
/*   Updated: 2024/10/20 21:39:32 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countft(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t	ft_counted(char const *s1, char const *set, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && ft_strchr(set, s1[len - i - 1]))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	size_t	len;
	size_t	frt;
	size_t	end;

	len = ft_strlen(s1);
	frt = ft_countft(s1, set);
	end = ft_counted(s1, set, len);
	if (len < end + frt)
		return (ft_strdup (""));
	temp = ft_substr(s1, frt, len - end - frt);
	return (temp);
}
