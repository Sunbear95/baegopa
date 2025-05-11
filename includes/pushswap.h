/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo <jyoo@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:42:01 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/11 20:27:17 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_st
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
	int	b_bit;
}	t_st;

int			start_algo(t_st *stack);
int			make_order(t_st *stack, int len);
int			ps_strlen(char **arr);
int			doub_num(t_st stack, long long temp);
long long	ps_atoi(const char *str);

void		ra(t_st *stack);
void		rb(t_st *stack);
void		rr(t_st *stack);
void		rra(t_st *stack);
void		rrb(t_st *stack);
void		rrr(t_st *stack);
void		sa(t_st *stack);
void		sb(t_st *stack);
void		ss(t_st *stack);
void		pa(t_st *stack);
void		pb(t_st *stack);

#endif
