/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:10:51 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/10 20:44:51 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->numbers == 0)
		return ;
	if (a->numbers)
		shiftd(a);
	*(a->stack) = *(b->stack);
	shiftu(b);
	a->numbers++;
	b->numbers--;
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->numbers == 0)
		return ;
	if (b->numbers)
		shiftd(b);
	*(b->stack) = *(a->stack);
	shiftu(a);
	b->numbers++;
	a->numbers--;
}
