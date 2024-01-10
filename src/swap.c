/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:04:26 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/09 19:12:33 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (a->numbers < 2)
		return ;
	tmp = a->stack[0];
	a->stack[0] = a->stack[1];
	a->stack[1] = tmp;
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->numbers < 2)
		return ;
	tmp = b->stack[0];
	b->stack[0] = b->stack[1];
	b->stack[1] = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
