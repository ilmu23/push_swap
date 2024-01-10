/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:12:02 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/04 14:01:28 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp.h"

void	ra(t_stack *a)
{
	int	tmp;

	tmp = a->stack[0];
	shiftu(a);
	a->stack[a->numbers - 1] = tmp;
}

void	rb(t_stack *b)
{
	int	tmp;

	tmp = b->stack[0];
	shiftu(b);
	b->stack[b->numbers - 1] = tmp;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
