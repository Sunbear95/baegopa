/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:50:35 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/12 01:55:45 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	down_low(t_st *stack)
{
	int	i;
	int	combo1;
	int	combo2;

	i = -1;
	combo1 = 0;
	combo2 = 0;
	while (++i < stack->len_a - 1)
	{
		if (stack->a[i] == stack->a[i + 1] + 1)
			combo1++;
		else
			break ;
	}
	while (++i < stack->len_a - 1)
	{
		if (stack->a[i] == stack->a[i + 1] + 1)
			combo2++;
		else
			break ;
	}
	if (combo1 + combo2 >= stack->len_a - 2)
		return (1);
	return (0);
}

int	up_low(t_st *stack)
{
	int	i;
	int	combo1;
	int	combo2;

	i = -1;
	combo1 = 0;
	combo2 = 0;
	while (++i < stack->len_a - 1)
	{
		if (stack->a[i] == stack->a[i + 1] - 1)
			combo1++;
		else
			break ;
	}
	while (++i < stack->len_a - 1)
	{
		if (stack->a[i] == stack->a[i + 1] - 1)
			combo2++;
		else
			break ;
	}
	if (combo1 + combo2 >= stack->len_a - 2)
		return (1);
	return (0);
}

int	in_a_low(t_st *stack)
{
	int	flag;

	if (stack->a[0] < stack->a[1])
		flag = 0;
	else
		flag = 1;
	if (flag == 0 && up_low(stack) == 1)
	{
		while (stack->a[0] != 1)
			rra(stack);
		return (1);
	}
	if (flag == 1 && down_low(stack) == 1)
	{
		while (stack->a[0] != 1)
			ra(stack);
		return (1);
	}
	return (0);
}

int	algo5(t_st *stack)
{
	if (in_a_low(stack))
		return (0);
	while (stack->a[0] != 1)
		ra(stack);
	pb(stack);
	if (stack->len_a > 3)
	{
		while (stack->a[0] != 2)
			ra(stack);
		pb(stack);
	}
	algo3(stack);
	if (stack->len_b == 2)
	{
		while (stack->b[0] != 1)
			rb(stack);
		pa(stack);
		pa(stack);
	}
	else
		pa(stack);
	return (0);
}
