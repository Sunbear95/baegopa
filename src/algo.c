/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:31:20 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/11 22:23:03 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

int	handle_anorm(t_st *stack)
{
	int	i;

	i = 0;
	while (i < stack->len_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (1);
		i++;
	}
	return (0);
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
