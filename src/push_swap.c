/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:40:40 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/11 22:23:05 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

void	free_all(t_st *stack)
{
	if (stack->a)
	{
		free(stack->a);
		stack->a = NULL;
	}
	if (stack->b)
	{
		free(stack->b);
		stack->b = NULL;
	}
}

void	find_big(t_st *stack)
{
	int	i;
	int	big;

	i = 0;
	big = 0;
	while (stack->a[i])
	{
		if (stack->a[i] > big)
			big = stack->a[i];
		i++;
	}
	stack->b_bit = 0;
	while ((big >> stack->b_bit) != 0)
		stack->b_bit++;
}

int	make_st(char **arr, int len, t_st *stack)
{
	int			i;
	long long	temp;

	stack->a = ft_calloc(sizeof (int), len + 1);
	stack->b = ft_calloc(sizeof (int), len + 1);
	if (!stack->a || !stack->b)
		return (1);
	stack->len_a = len;
	stack->len_b = 0;
	i = -1;
	while (++i < len)
	{
		temp = ps_atoi(arr[i]);
		if (temp == 2147483649 || doub_num(*stack, temp))
		{
			ft_printf("Error\n");
			return (1);
		}
		stack->a[i] = (int) temp;
	}
	make_order(stack, len);
	find_big(stack);
	return (0);
}

char	**ft_parsing(char **argv)
{
	int		i;
	char	*temp;
	char	*join;
	char	**arr;

	i = 0;
	temp = ft_strdup("");
	if (!temp)
		return (0);
	while (argv[++i])
	{
		join = ft_strjoin(temp, argv[i]);
		if (!join)
		{
			free (temp);
			return (0);
		}
		if (temp)
			free(temp);
		temp = ft_strjoin(join, " ");
		free(join);
	}
	arr = ft_split(temp, ' ');
	free(temp);
	return (arr);
}

int	main(int argc, char *argv[])
{
	char	**arr;
	t_st	stack;

	if (argc <= 1)
	{
		ft_printf("Error");
		return (0);
	}
	arr = ft_parsing(argv);
	if (!make_st(arr, ps_strlen(arr), &stack))
		start_algo(&stack);
	free_all(&stack);
	return (0);
}
