/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:44:20 by cchen             #+#    #+#             */
/*   Updated: 2022/01/17 19:19:45 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_stdio.h"
#include "ft_string.h"

int	main(int argc, char **argv)
{
	t_piece		pieces[MAX_PIECES + 1];
	char	**board;
	int		count;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (1);
	}
	ft_bzero(pieces, sizeof(t_piece) * (MAX_PIECES + 1));
	count = read_input(argv[1], pieces);
	if (count < 0)
	{
		ft_putendl("error");
		return (-1);
	}
	else
	{
		board = empty_board(count);
		print_board(board, count);
	}
	return (0);
}
