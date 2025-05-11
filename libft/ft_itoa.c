/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:24:30 by jyoo              #+#    #+#             */
/*   Updated: 2024/10/28 16:37:44 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numleng(int n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoasub(int n, int len, char *arr)
{
	int		i;

	if (n < 0)
	{
		n *= -1;
		arr[0] = '-';
	}
	i = 0;
	while (n != 0)
	{
		arr[len - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	arr[len] = '\0';
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_numleng(n);
	if (n < 0)
		len++;
	arr = (char *)ft_calloc(len + 1, sizeof (char));
	if (!arr)
		return (0);
	arr = ft_itoasub(n, len, arr);
	return (arr);
}
