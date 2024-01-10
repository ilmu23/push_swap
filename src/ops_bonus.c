/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:52:06 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/08 12:33:53 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	run(t_stack *a, t_stack *b, char *op);

int	runops(t_stack *a, t_stack *b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		ft_debugmsg(OPPFX, "Next operation: %s", op);
		if (!run(a, b, op))
			return (0);
		op = get_next_line(0);
	}
	return (1);
}

static int	run(t_stack *a, t_stack *b, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(op, "rr\n", 4) == 0)
		rr(a, b);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}
