/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:14:34 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/11 22:23:08 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

void	ra(t_st *stack)
{
	int	temp;
	int	i;

	i = -1;
	if (stack->len_a > 1)
	{
		temp = stack->a[0];
		while (++i < stack->len_a - 1)
			(stack->a)[i] = (stack->a)[i + 1];
		(stack->a)[i] = temp;
	}
	ft_printf("ra\n");
}

void	rb(t_st *stack)
{
	int	temp;
	int	i;

	i = -1;
	if (stack->len_b > 1)
	{
		temp = stack->b[0];
		while (++i < stack->len_b - 1)
			(stack->b)[i] = (stack->b)[i + 1];
		(stack->b)[i] = temp;
	}
	ft_printf("rb\n");
}

void	rr(t_st *stack)
{
	int	temp;
	int	i;

	i = -1;
	if (stack->len_a > 1)
	{
		temp = stack->a[0];
		while (++i < stack->len_a - 1)
			(stack->a)[i] = (stack->a)[i + 1];
		(stack->a)[i] = temp;
	}
	i = -1;
	if (stack->len_b > 1)
	{
		temp = stack->b[0];
		while (++i < stack->len_b - 1)
			(stack->b)[i] = (stack->b)[i + 1];
		(stack->b)[i] = temp;
	}
	ft_printf("rr\n");
}
