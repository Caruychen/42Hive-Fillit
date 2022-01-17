/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:45:52 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/01/17 19:10:47 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

int	print_board(char **board, int count)
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
