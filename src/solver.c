/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:17:23 by cchen             #+#    #+#             */
/*   Updated: 2022/01/17 19:37:31 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

int	solve_square(int count)
{
	uint8_t	base;

	base = 2;
	while (base * base < count * 4)
		++base;
	return (base);
}

char	**empty_board(int count)
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
