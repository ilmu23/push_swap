/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:54:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/10 20:30:04 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp.h"

static void	sort(t_stack *a, t_stack *b);
static void	sort3(t_stack *s);
static void	pusha(t_stack *a, t_stack *b);
static void	pushb(t_stack *a, t_stack *b);

void	solve(t_stack *a)
{
	t_stack	*b;

	b = ft_pushstack(newstack(ft_pushstack(a)->numbers));
	if (!b)
		return ;
	sort(a, b);
}

static void	sort(t_stack *a, t_stack *b)
{
	while (a->numbers > 3)
		pushb(a, b);
	sort3(a);
	postop(b, lpos(b), 'b');
	while (b->numbers > 0)
		pusha(a, b);
	postop(a, spos(a), 'a');
}

static void	sort3(t_stack *a)
{
	if (sorted(a))
		return ;
	if (a->numbers == 2 && a->stack[0] > a->stack[1])
	{
		operation(a, NULL, "sa");
		return ;
	}
	if ((a->stack[0] > a->stack[1] && a->stack[1] > a->stack[2])
		|| (a->stack[0] > a->stack[2] && a->stack[1] < a->stack[2]))
		operation(a, NULL, "ra");
	if (a->stack[0] < a->stack[1] && a->stack[1] > a->stack[2])
		operation(a, NULL, "rra");
	if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2])
		operation(a, NULL, "sa");
}

static void	pusha(t_stack *a, t_stack *b)
{
	size_t			i;
	static size_t	rotations;

	if (a->numbers == 3)
		rotations = 3;
	if (rotations && *b->stack < a->stack[a->numbers - 1])
	{
		i = 0;
		while (i < rotations && *b->stack < a->stack[a->numbers - 1 - i])
			i++;
		postop(a, a->numbers - i, 'a');
		rotations -= i;
	}
	operation(a, b, "pa");
}

static void	pushb(t_stack *a, t_stack *b)
{
	size_t	apos;
	size_t	mpos;
	size_t	moves;
	size_t	minmoves;

	apos = 0;
	minmoves = INT_MAX;
	while (apos < a->numbers)
	{
		moves = getrotation(a, b, apos, insertpos(b, a->stack[apos]));
		if (moves < minmoves)
		{
			minmoves = moves;
			mpos = apos;
		}
		apos++;
	}
	rotatestacks(a, b, mpos, insertpos(b, a->stack[mpos]));
	operation(a, b, "pb");
}
