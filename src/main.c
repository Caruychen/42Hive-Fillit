/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:44:20 by cchen             #+#    #+#             */
/*   Updated: 2022/01/25 12:19:07 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_piece		pieces[MAX_PIECES + 1];
	int			board;
	int			count;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit [input_file]");
		return (1);
	}
	ft_bzero(pieces, sizeof(t_piece) * (MAX_PIECES + 1));
	count = read_input(argv[1], pieces);
	if (count < 0)
	{
		ft_putendl("error");
		return (-1);
	}
	printf("%d\n", count);
	board = solve_map(count, pieces);
	print_board(board, pieces);
	return (0);
}
