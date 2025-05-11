/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:08:58 by jyoo              #+#    #+#             */
/*   Updated: 2024/10/28 13:32:05 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	ft_move(char const *s, char c, int *start, int *i)
{
	while (s[*i] == c)
		(*i)++;
	*start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
}

static void	free_all(char **arr, int j)
{
	while (j >= 0)
		free(arr[j--]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	temp = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!s || !temp)
		return (0);
	while (s[i])
	{
		ft_move(s, c, &start, &i);
		if (i > start)
		{
			temp[j] = ft_substr(s, start, i - start);
			if (!temp[j++])
			{
				free_all(temp, j - 1);
				return (0);
			}
		}
	}
	temp[j] = 0;
	return (temp);
}
