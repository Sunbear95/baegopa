/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:05:13 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/11 23:00:18 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

void	sa(t_st *stack)
{
	int	temp;

	if (stack->len_a > 1)
	{
		temp = (stack->a)[0];
		(stack->a)[0] = (stack->a)[1];
		(stack->a)[1] = temp;
	}
	ft_printf("sa\n");
}

void	sb(t_st *stack)
{
	int	temp;

	if (stack->len_b > 1)
	{
		temp = (stack->b)[0];
		(stack->b)[0] = (stack->b)[1];
		(stack->b)[1] = temp;
	}
	ft_printf("sb\n");
}

void	ss(t_st *stack)
{
	int	temp;

	if (stack->len_a > 1)
	{
		temp = (stack->a)[0];
		(stack->a)[0] = (stack->a)[1];
		(stack->a)[1] = temp;
	}
	if (stack->len_a > 1)
	{
		temp = (stack->b)[0];
		(stack->b)[0] = (stack->b)[1];
		(stack->b)[1] = temp;
	}
	ft_printf("ss\n");
}
