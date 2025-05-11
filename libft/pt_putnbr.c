/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:42:14 by jyoo              #+#    #+#             */
/*   Updated: 2025/01/30 21:06:17 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pt_arry_rev(char *str, int c)
{
	int	r;

	r = c - 1;
	while (r >= 0)
	{
		write (1, &str[r], 1);
		r--;
	}
}

void	min_nb(int nb_)
{
	int		m;
	int		i;
	char	mnbar[12];

	m = 0;
	if (nb_ == -2147483648)
	{
		write (1, "-2147483648", 11);
	}
	else
	{
		nb_ = -nb_;
		while (nb_ > 0)
		{
			i = nb_ % 10;
			mnbar[m] = i + '0';
			m++;
			nb_ = nb_ / 10;
		}
		pt_putchar('-');
		pt_arry_rev(mnbar, m);
	}
}

void	plus_nb(int nb)
{
	int		n;
	int		k;
	char	nb_ar[11];

	n = 0;
	while (nb > 0)
	{
		k = nb % 10;
		nb_ar[n] = k + '0';
		n++;
		nb = nb / 10;
	}
	pt_arry_rev(nb_ar, n);
}

int	pt_putnbr(int nb)
{
	int		temp;
	int		count;

	count = 0;
	temp = nb;
	while (temp != 0)
	{
		count++;
		temp = temp / 10;
	}
	if (nb > 0)
		plus_nb(nb);
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (nb < 0)
	{
		count++;
		min_nb(nb);
	}
	return (count);
}
