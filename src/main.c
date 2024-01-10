/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:05:58 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/08 12:40:33 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pshswp.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		return (-1);
	a = getstack(argc - 1, argv + 1);
	if (!a)
	{
		ft_putendl_fd("Error", 2);
		return (ft_return(1));
	}
	if (a->numbers == 1 || sorted(a))
		return (ft_return(0));
	solve(a);
	return (ft_return(0));
}
