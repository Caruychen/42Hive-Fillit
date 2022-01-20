/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:44:20 by cchen             #+#    #+#             */
/*   Updated: 2022/01/20 11:21:12 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include <stdlib.h>

static void	error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_piece		pieces[MAX_PIECES + 1];
	int			count;
	int			base;

	if (argc != 2)
		error("usage: ./fillit source_file");
	ft_bzero(pieces, sizeof(*pieces) * (MAX_PIECES + 1));
	if (read_input(argv[1], pieces, &count) < 0)
	{
		ft_putendl("error");
		return (-1);
	}
	base = solve_square(pieces, count);
	print_grid(pieces, base);
	return (0);
}
