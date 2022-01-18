/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:44:20 by cchen             #+#    #+#             */
/*   Updated: 2022/01/18 14:55:06 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_stdio.h"
#include "ft_string.h"

int	main(int argc, char **argv)
{
	t_piece		pieces[MAX_PIECES + 1];
	int			count;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (1);
	}
	ft_bzero(pieces, sizeof(*pieces) * (MAX_PIECES + 1));
	if (read_input(argv[1], pieces, &count) < 0)
	{
		ft_putendl("error");
		return (-1);
	}
	ft_putnbr(solve_square(pieces, count));
	return (0);
}
