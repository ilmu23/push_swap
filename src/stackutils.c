/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:21:23 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/08 17:44:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp.h"

t_stack	*newstack(size_t n)
{
	t_stack	*out;

	ft_debugmsg(STKPFX, "Creating new stack (size %u)", n);
	out = ft_push(ft_alloc(sizeof(t_stack)));
	if (out)
		out->stack = ft_alloc(n * sizeof(int));
	ft_popn(out != NULL);
	out->numbers = 0;
	if (!out || !out->stack)
		return (NULL);
	return (out);
}

t_stack	*ft_pushstack(t_stack *s)
{
	if (!s)
		return (NULL);
	ft_push(s);
	ft_push(s->stack);
	return (s);
}

size_t	getrotation(t_stack *a, t_stack *b, size_t apos, size_t bpos)
{
	size_t	out;
	size_t	tmp;

	out = max(apos, bpos);
	tmp = max(a->numbers - apos, b->numbers - bpos);
	if (out > tmp)
		out = tmp;
	tmp = apos + b->numbers - bpos;
	if (out > tmp)
		out = tmp;
	tmp = a->numbers - apos + bpos;
	if (out > tmp)
		return (tmp);
	return (out);
}

int	sorted(t_stack *a)
{
	size_t	i;

	i = 1;
	while (i < a->numbers)
	{
		if (a->stack[i - 1] > a->stack[i])
			return (0);
		i++;
	}
	return (1);
}
