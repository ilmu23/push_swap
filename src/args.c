/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:43:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/08 17:39:34 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp.h"

t_stack	*getstack(int n, char **args)
{
	size_t	i;
	t_stack	*out;

	if (n == 1)
		return (getnumbers(*args));
	out = newstack(n);
	if (!out)
		return (NULL);
	i = 0;
	if (getargs(out, args, n) == -1)
		return (NULL);
	return (out);
}

t_stack	*getnumbers(char *arg)
{
	size_t	n;
	char	**arr;
	t_stack	*out;

	arr = ft_pusharr(ft_split(arg, ' '));
	if (!arr || !*arr)
		return (NULL);
	n = 0;
	while (arr[n])
		n++;
	out = newstack(n);
	if (!out)
		out = NULL;
	if (getargs(out, arr, n) == -1)
		out = NULL;
	ft_popn(n);
	return (out);
}

int	getargs(t_stack *s, char **args, size_t n)
{
	size_t	i;
	int		tmp;

	if (!s)
		return (-1);
	ft_pushstack(s);
	i = 0;
	while (i < n)
	{
		if (ft_isinteger(args[i]) == 0)
			return (-1);
		tmp = ft_atoi(args[i]);
		if (contains(s, tmp) == 1)
			return (-1);
		s->stack[i] = tmp;
		s->numbers++;
		i++;
	}
	ft_popn(2);
	return (s->numbers);
}

int	contains(t_stack *s, int n)
{
	size_t	i;

	i = 0;
	while (i < s->numbers)
	{
		if (s->stack[i] == n)
			return (1);
		i++;
	}
	return (0);
}
