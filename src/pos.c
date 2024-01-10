/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:53:08 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/08 17:55:37 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp.h"

size_t	insertpos(t_stack *s, int n)
{
	size_t	i;

	if (s->numbers == 0)
		return (0);
	i = 0;
	if (s->stack[lpos(s)] < n || s->stack[spos(s)] > n)
		return (lpos(s));
	while (i < s->numbers - 1)
	{
		if (s->stack[i] > n && s->stack[i + 1] < n)
			break ;
		i++;
	}
	return (i + 1);
}

size_t	lpos(t_stack *s)
{
	size_t	i;
	size_t	h;

	i = 0;
	h = 0;
	while (i < s->numbers)
	{
		if (s->stack[i] > s->stack[h])
			h = i;
		i++;
	}
	return (h);
}

size_t	spos(t_stack *s)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (i < s->numbers)
	{
		if (s->stack[i] < s->stack[l])
			l = i;
		i++;
	}
	return (l);
}

void	postop(t_stack *s, size_t pos, char stk)
{
	if (pos < s->numbers && pos <= s->numbers / 2)
	{
		while (pos > 0)
		{
			if (stk == 'a')
				operation(s, NULL, "ra");
			else
				operation(NULL, s, "rb");
			pos--;
		}
	}
	else if (pos < s->numbers)
	{
		pos = s->numbers - pos;
		while (pos > 0)
		{
			if (stk == 'a')
				operation(s, NULL, "rra");
			else
				operation(NULL, s, "rrb");
			pos--;
		}
	}
}
