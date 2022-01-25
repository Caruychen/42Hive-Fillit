/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:45:52 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/01/25 15:01:06 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"
#include "../libft/libft.h"
#include <stdio.h>

static char	**empty_board(int count)
{
	char	**board;
	int		row;

	printf("%d\n", count);
	board = (char **)malloc(sizeof(char *) * count);
	if (!board)
		return (NULL);
	row = 0;
	while (row <= count)
	{
		board[row] = ft_strnew(count);
		ft_memset(board[row], '.', count);
		row++;
	}
	return (board);
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
			{
				printf("%d\n", pos.x);
				board[pos.y][pos.x] = piece.letter;
			}		
			pos.x++;
		}
		pos.y++;
	}
}

static void	fill_board(char **board, t_piece *piece)
{
	while(piece->letter)
	{
		place_piece(board, *piece);
		piece++;
	}
}

int		print_board(int count, t_piece *piece)
{
	int		row;
	int		col;
	char	**board;
	
	board = empty_board(count);
	printf("%p\n", piece);
	fill_board(board, piece);
	row = 0;
	while (row < count)
	{
		col = 0;
		while (col < count)
		{
			ft_putchar(board[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
	return (0);
}
