/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:06:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/07 21:05:53 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp.h"

void	operation(t_stack *a, t_stack *b, char *op)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		sa(a);
	else if (ft_strncmp(op, "sb", 2) == 0)
		sb(b);
	else if (ft_strncmp(op, "ss", 2) == 0)
		ss(a, b);
	else if (ft_strncmp(op, "pa", 2) == 0)
		pa(a, b);
	else if (ft_strncmp(op, "pb", 2) == 0)
		pb(a, b);
	else if (ft_strncmp(op, "ra", 2) == 0)
		ra(a);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rb(b);
	else if (ft_strncmp(op, "rr", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(op, "rra", 3) == 0)
		rra(a);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		rrb(b);
	else
		rrr(a, b);
	ft_printf("%s\n", op);
}

void	rotatestacks(t_stack *a, t_stack *b, size_t apos, size_t bpos)
{
	ft_debugmsg(STKPFX, "apos = %u, *apos = %d", apos, a->stack[apos]);
	ft_debugmsg(STKPFX, "bpos = %u, *bpos = %d", bpos, b->stack[bpos]);
	if (apos <= a->numbers / 2 && bpos <= b->numbers / 2)
	{
		while (apos > 0 && bpos > 0)
		{
			operation(a, b, "rr");
			apos--;
			bpos--;
		}
	}
	else if (apos > a->numbers / 2 && bpos > b->numbers / 2)
	{
		while (a->numbers - apos > 0 && b->numbers - bpos > 0)
		{
			operation(a, b, "rrr");
			apos++;
			bpos++;
		}
	}
	postop(a, apos, 'a');
	postop(b, bpos, 'b');
}
