/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:45:52 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/01/19 22:07:14 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

static char	**empty_board(int count)
{
	char	**board;
	int		row;

	board = (char **)malloc(sizeof(char *) * count);
	if (!board)
		return (NULL);
	row = 0;
	while (row < count)
	{
		board[row] = ft_strnew(count);
		ft_memset(board[row], '.', count);
		row++;
	}
	return (board);
}

static void	place_piece(char **board, t_piece pieces)
{
	
}

static char	**fill_board(char **board, t_piece *pieces)
{
	while(pieces->letter)
	{
		place_piece(board, *pieces);
		pieces++;
	}
	return (board);
}

int		print_board(char **board, int count)
{
	int	row;
	int	col;

	
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
