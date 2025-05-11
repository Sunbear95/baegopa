/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:13:54 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/12 01:52:28 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

void	ft_swap(int *A, int *B)
{
	int	temp;

	temp = *A;
	*A = *B;
	*B = temp;
}

int	*make_line(t_st *stack, int len)
{
	int	*line;
	int	i;
	int	j;

	line = (int *) malloc (sizeof (int) * len + 1);
	if (!line)
		return (0);
	i = -1;
	while (++i < len)
		line[i] = stack->a[i];
	i = -1;
	while (++i < len - 1)
	{
		j = -1;
		while (++j < len - 1)
		{
			if (line[j] > line[j + 1])
				ft_swap(&line[j], &line[j + 1]);
		}
	}
	return (line);
}

int	make_order(t_st *stack, int len)
{
	int	*temp;
	int	i;
	int	j;

	temp = make_line(stack, len);
	if (!temp)
		return (0);
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (stack->a[i] == temp[j])
			{
				stack->a[i] = j + 1;
				break ;
			}
		}
	}
	free(temp);
	return (0);
}
