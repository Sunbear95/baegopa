/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo < jyoo@student.42gyeongsan.kr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:54:14 by jyoo              #+#    #+#             */
/*   Updated: 2025/02/24 15:36:55 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pt_process_format(va_list *args, char format)
{
	if (format == 'c')
		return (pt_putchar(va_arg(*args, int)));
	else if (format == 's')
		return (pt_putstr(va_arg(*args, char *)));
	else if (format == 'd' || format == 'i')
		return (pt_putnbr(va_arg(*args, int)));
	else if (format == 'u')
		return (pt_putnbr_unsigned(va_arg(*args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (pt_puthex(va_arg(*args, unsigned int), format));
	else if (format == 'p')
		return (pt_putpointer(va_arg(*args, void *)));
	else if (format == '%')
	{
		pt_putchar('%');
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed_chars;

	i = 0;
	printed_chars = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			printed_chars += pt_process_format(&args, format[i + 1]);
			i++;
		}
		else
		{
			printed_chars++;
			pt_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}
