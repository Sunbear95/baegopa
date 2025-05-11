/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func_pa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:46:13 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/11 22:23:08 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

static int	a_side(t_st *stack)
{
	int	*temp_a;
	int	i;

	temp_a = (int *)malloc((sizeof(int) * (stack->len_a + 1)));
	if (!temp_a)
		return (1);
	temp_a[0] = (stack->b)[0];
	i = -1;
	while (++i < stack->len_a)
		temp_a[i + 1] = (stack->a)[i];
	free (stack->a);
	stack->a = temp_a;
	stack->len_a++;
	return (0);
}

static int	b_side(t_st *stack)
{
	int	*temp_b;
	int	i;

	if (stack->len_b == 1)
	{
		stack->b[0] = 0;
		stack->len_b--;
		return (1);
	}
	temp_b = (int *)malloc((sizeof(int) * (stack->len_b - 1)));
	i = -1;
	while (++i < stack->len_b - 1)
		temp_b[i] = (stack->b)[i + 1];
	free (stack->b);
	stack->b = temp_b;
	stack->len_b--;
	return (0);
}

void	pa(t_st *stack)
{
	if (stack->len_b > 0)
	{
		a_side(stack);
		b_side(stack);
		ft_printf("pa\n");
	}
}