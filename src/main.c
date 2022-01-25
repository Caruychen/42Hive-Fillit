/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:44:20 by cchen             #+#    #+#             */
/*   Updated: 2022/01/25 16:09:39 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include <stdlib.h>

static void	error(const char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_piece		pieces[MAX_PIECES + 1];
	int			count;
	int			size;

	if (argc != 2)
		error("usage: ./fillit source_file");
	ft_bzero(pieces, sizeof(*pieces) * (MAX_PIECES + 1));
	if (read_input(argv[1], pieces, &count) <= 0)
		error("error");
	size = solve_map(pieces, count);
	print_grid(pieces, size);
	return (0);
}
