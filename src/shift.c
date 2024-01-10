/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:22:34 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/18 18:12:54 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp.h"

void	shiftu(t_stack *s)
{
	size_t	i;

	i = 0;
	while (i < s->numbers - 1)
	{
		s->stack[i] = s->stack[i + 1];
		i++;
	}
	s->stack[i] = 0;
}

void	shiftd(t_stack *s)
{
	size_t	i;

	i = s->numbers;
	while (i > 0)
	{
		s->stack[i] = s->stack[i - 1];
		i--;
	}
}
