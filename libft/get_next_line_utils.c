/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo < jyoo@student.42gyeongsan.kr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:44:16 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/08 21:49:03 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strdup(char *src)
{
	char	*copy;
	size_t	len;
	size_t	i;

	if (!src)
		return (NULL);
	len = gnl_strlen(src);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s || start >= gnl_strlen(s))
		return (gnl_strdup(NULL));
	i = 0;
	while (s[start + i] != 0)
		i++;
	if (i < len)
		len = i;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

size_t	gnl_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	gnl_strlcpy(char *dst, char *src, size_t size)
{
	size_t			i;
	unsigned int	src_len;

	src_len = 0;
	if (!src)
		return (0);
	while (src[src_len])
		src_len++;
	i = 0;
	if (size == 0)
		return (src_len);
	while (src[i] != 0 && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}

char	*gnl_strjoin(char **s1, char *s2)
{
	char	*temp;
	size_t	len1;
	size_t	len2;

	if (!s2)
		return (NULL);
	len1 = gnl_strlen(*s1);
	len2 = gnl_strlen(s2);
	temp = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!temp)
		return (NULL);
	gnl_strlcpy(temp, *s1, len1 + 1);
	gnl_strlcpy(temp + len1, s2, len2 + 1);
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	return (temp);
}
