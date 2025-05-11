/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo < jyoo@student.42gyeongsan.kr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:54:14 by jyoo              #+#    #+#             */
/*   Updated: 2025/02/24 15:36:55 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pt_putnbr_unsigned(unsigned int n)
{
	int		count;
	char	temp[10];

	count = 0;
	if (n == 0)
	{
		temp[count] = '0';
		count++;
	}
	while (n != 0)
	{
		temp[count] = n % 10 + '0';
		count++;
		n = n / 10;
	}
	pt_arry_rev(temp, count);
	return (count);
}

int	pt_puthex(unsigned int n, char format)
{
	int				count;
	char			*hex;
	char			hexreturn[8];

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	count = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	while (n > 0)
	{
		hexreturn[count] = hex[n % 16];
		count++;
		n = n / 16;
	}
	pt_arry_rev(hexreturn, count);
	return (count);
}

int	pt_puthex_for_address(unsigned long long n)
{
	int				count;
	char			*hex;
	char			hexreturn[16];

	if (n == 0)
	{
		hexreturn[0] = '0';
		return (1);
	}
	count = 0;
	hex = "0123456789abcdef";
	while (n > 0)
	{
		hexreturn[count] = hex[n % 16];
		count++;
		n = n / 16;
	}
	pt_arry_rev(hexreturn, count);
	return (count);
}

int	pt_putpointer(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		pt_putstr("(nil)");
		return (5);
	}
	pt_putstr("0x");
	count = count + 2;
	count += pt_puthex_for_address((unsigned long long)ptr);
	return (count);
}
