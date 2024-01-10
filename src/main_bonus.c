/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:04:24 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/09 19:04:10 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (1);
	a = ft_pushstack(getstack(argc - 1, argv + 1));
	if (a)
		b = ft_pushstack(newstack(a->numbers));
	if (!a || !b)
	{
		ft_putendl_fd("Error", 2);
		return (ft_return(1));
	}
	if (!runops(a, b))
	{
		ft_putendl_fd("Error", 2);
		return (ft_return(1));
	}
	if (!sorted(a) || b->numbers)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (ft_return(0));
}
