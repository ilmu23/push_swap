/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:16:40 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/10 21:16:08 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp.h"

void	rra(t_stack *a)
{
	int	tmp;

	tmp = a->stack[a->numbers - 1];
	shiftd(a, 'r');
	a->stack[0] = tmp;
	if (a->numbers < ft_getblksize(a->stack) / sizeof(int))
		a->stack[a->numbers] = 0;
}

void	rrb(t_stack *b)
{
	int	tmp;

	tmp = b->stack[b->numbers - 1];
	shiftd(b, 'r');
	b->stack[0] = tmp;
	if (b->numbers < ft_getblksize(b->stack) / sizeof(int))
		b->stack[b->numbers] = 0;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
