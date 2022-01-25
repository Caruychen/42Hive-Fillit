/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:33:09 by cchen             #+#    #+#             */
/*   Updated: 2022/01/25 16:59:00 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

static int	wipe_board(char ***board, int row)
{
	while (row >= 0)
		ft_strdel(&(*board)[row--]);
	free(*board);
	*board = NULL;
	return (-1);
}

static int	init_board(char ***board, const int size)
{
	int	row;

	*board = (char **)malloc(sizeof(**board) * size);
	if (!(*board))
		return (-1);
	row = 0;
	while (row < size)
	{
		(*board)[row] = ft_strnew(size);
		if (!(*board)[row])
			return (wipe_board(board, row - 1));
		ft_memset((*board)[row], '.', size);
		row++;
	}
	return (0);
}

static void	place_piece(char **board, t_piece piece)
{
	t_point	pos;

	pos.y = 0;
	while (pos.y < piece.height)
	{
		pos.x = 0;
		while (pos.x < piece.width)
		{
			if ((piece.barray >> (16 * (pos.y + 1) - 1 - pos.x)) & 1)
				board[piece.y + pos.y][piece.x + pos.x] = (char)piece.letter;
			++pos.x;
		}
		++pos.y;
	}
}

static void	fill_board(char **board, t_piece *pieces)
{
	while (pieces->letter)
	{
		place_piece(board, *pieces);
		++pieces;
	}
}

int	print_board(t_piece *pieces, const int size)
{
	char	**board;
	int		row;

	if (init_board(&board, size) < 0)
		return (-1);
	fill_board(board, pieces);
	row = 0;
	while (row < size)
		ft_putendl(board[row++]);
	wipe_board(&board, size - 1);
	return (0);
}
