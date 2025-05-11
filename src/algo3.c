/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:37:13 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/12 01:35:02 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	algo3(t_st *stack)
{
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && \
		stack->a[0] < stack->a[2])
	{
		sa(stack);
		ra(stack);
	}
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && \
		stack->a[0] > stack->a[2])
		rra(stack);
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && \
		stack->a[0] < stack->a[2])
		sa(stack);
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		sa(stack);
		rra(stack);
	}
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && \
		stack->a[0] < stack->a[2])
		ra(stack);
	return (0);
}
