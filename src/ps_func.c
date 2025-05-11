/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:37:01 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/11 22:23:05 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

int	doub_num(t_st stack, long long temp)
{
	int	i;

	i = 0;
	while (stack.a[i] != 0)
	{
		if ((int) temp == stack.a[i])
			return (1);
		i++;
	}
	return (0);
}

int	ps_strlen(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

static void	ft_isspace(const char **str)
{
	while (**str == ' ' || **str == '\n' || **str == '\t'
		|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
}

static int	ft_pn(const char **str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			count++;
		(*str)++;
		i++;
	}
	if (i > 1)
		return (0);
	else if (count == 1)
		return (-1);
	else
		return (1);
}

long long	ps_atoi(const char *str)
{
	long long	n;
	long long	pn;

	n = 0;
	ft_isspace(&str);
	pn = ft_pn(&str);
	if (pn == 0 || ft_strlen(str) > 10 || str[0] == '\0')
		return (2147483649);
	while (*str != 0)
	{
		if (*str >= '0' && *str <= '9')
		{
			n = 10 * n + (*str - '0');
			str++;
		}
		else
			return (2147483649);
	}
	if (n == 2147483648 && pn == -1)
		return (pn * n);
	if (n >= 2147483648)
		return (2147483649);
	return (pn * n);
}
