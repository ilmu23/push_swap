/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pshswp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:50:38 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/07 17:46:22 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSHSWP_H
# define PSHSWP_H
# include "libft.h"

# define STKPFX "\e[37;1mpush_swap: stack: "

typedef struct s_stack
{
	int		*stack;
	size_t	numbers;
}	t_stack;

// solve.c
void	solve(t_stack *a);

// push.c
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// swap.c
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// rotate.c
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// reverse.c
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// shift.c
void	shiftu(t_stack *s);
void	shiftd(t_stack *s);

// utils.c
size_t	max(size_t a, size_t b);

// args.c
t_stack	*getstack(int n, char **numbers);
t_stack	*getnumbers(char *arg);
int		getargs(t_stack *s, char **args, size_t n);
int		contains(t_stack *s, int n);

// ops.c
void	operation(t_stack *a, t_stack *b, char *op);
void	rotatestacks(t_stack *a, t_stack *b, size_t apos, size_t bpos);

// pos.c
size_t	insertpos(t_stack *s, int n);
size_t	lpos(t_stack *s);
size_t	spos(t_stack *s);
void	postop(t_stack *s, size_t pos, char stk);

// stackutils.c
t_stack	*newstack(size_t n);
t_stack	*ft_pushstack(t_stack *s);
size_t	getrotation(t_stack *a, t_stack *b, size_t apos, size_t bpos);
int		sorted(t_stack *a);

#endif
