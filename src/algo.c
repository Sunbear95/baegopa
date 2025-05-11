/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:31:20 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/12 01:21:42 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

int	handle_anorm(t_st *stack)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < stack->len_a - 1)
	{
		if (stack->a[i] == stack->a[i + 1] - 1)
			cnt++;
		i++;
	}
	if (stack->len_a - 1 == cnt)
		return (0);
	if (stack->len_a == 2)
	{
		ra(stack);
		return (0);
	}
	if (stack->len_a == 3)
		return (algo3(stack));
	if (stack->len_a < 6)
		return (algo5(stack));
	return (1);
}

int	start_algo(t_st *stack)
{
	int	i;
	int	j;
	int	temp;

	if (!handle_anorm(stack))
		return (0);
	i = -1;
	while (++i < stack->b_bit)
	{
		j = -1;
		temp = stack->len_a;
		while (++j < temp)
		{
			if (stack->a[0] == 0)
				break ;
			if (((stack->a[0] >> i) & 1) == 0)
				pb(stack);
			else
				ra(stack);
		}
		while (stack->len_b > 0 && stack->b[0] != 0)
			pa(stack);
	}
	pa(stack);
	return (0);
}
