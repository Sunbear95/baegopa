/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo < jyoo@student.42gyeongsan.kr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:52:17 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/07 21:14:33 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		pt_putnbr_unsigned(unsigned int n);
int		pt_puthex(unsigned int n, char format);
int		pt_puthex_for_address(unsigned long long n);
int		pt_putpointer(void *ptr);
int		pt_process_format(va_list *args, char format);
int		ft_printf(const char *format, ...);

int		pt_putstr(char *str);

int		pt_putnbr(int nb);

int		pt_putchar(int c);
void	pt_arry_rev(char *str, int c);

#endif
