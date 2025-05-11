/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo < jyoo@student.42gyeongsan.kr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:44:21 by jyoo              #+#    #+#             */
/*   Updated: 2025/02/24 15:37:24 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pt_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == 0)
		return (pt_putstr("(null)"));
	while (*str != '\0')
	{
		pt_putchar(*str);
		str++;
		count++;
	}
	return (count);
}
