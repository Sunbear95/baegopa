/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func_pb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:46:13 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/11 22:23:06 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

static int	b_side(t_st *stack)
{
	int	*temp_b;
	int	i;

	temp_b = (int *)malloc((sizeof(int) * (stack->len_b + 1)));
	if (!temp_b)
		return (1);
	temp_b[0] = stack->a[0];
	i = -1;
	while (++i < stack->len_b)
		temp_b[i + 1] = (stack->b)[i];
	free (stack->b);
	stack->b = temp_b;
	stack->len_b++;
	return (0);
}

static int	a_side(t_st *stack)
{
	int	*temp_a;
	int	i;

	if (stack->len_a == 1)
	{
		stack->a[0] = 0;
		stack->len_a--;
		return (1);
	}
	temp_a = (int *)malloc((sizeof(int) * (stack->len_a - 1)));
	i = -1;
	while (++i < stack->len_a - 1)
		temp_a[i] = (stack->a)[i + 1];
	free (stack->a);
	stack->a = temp_a;
	stack->len_a--;
	return (0);
}

void	pb(t_st *stack)
{
	if (stack->len_a > 0)
	{
		b_side(stack);
		a_side(stack);
		ft_printf("pb\n");
	}
}