/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:19:06 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/11 22:23:09 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

void	rra(t_st *stack)
{
	int	temp;
	int	i;

	i = stack->len_a - 1;
	if (stack->len_a > 1)
	{
		temp = (stack->a)[stack->len_a - 1];
		while (--i >= 0)
			(stack->a)[i + 1] = (stack->a)[i];
		(stack->a)[0] = temp;
		ft_printf("rra\n");
	}
}

void	rrb(t_st *stack)
{
	int	temp;
	int	i;

	i = stack->len_b - 1;
	if (stack->len_b > 1)
	{
		temp = (stack->b)[stack->len_b - 1];
		while (--i >= 0)
			(stack->b)[i + 1] = (stack->b)[i];
		(stack->b)[0] = temp;
		ft_printf("rrb\n");
	}
}

void	rrr(t_st *stack)
{
	int	temp;
	int	i;

	i = stack->len_a - 1;
	if (stack->len_a > 1)
	{
		temp = (stack->a)[stack->len_a - 1];
		while (--i >= 0)
			(stack->a)[i + 1] = (stack->a)[i];
		(stack->a)[0] = temp;
	}
	if (stack->len_b > 1)
	{
		while (--i >= 0)
			(stack->b)[i + 1] = (stack->b)[i];
		(stack->b)[0] = temp;
	}
	ft_printf("rrr");
}

