/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:33:09 by cchen             #+#    #+#             */
/*   Updated: 2022/01/18 16:11:06 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"

static void	init_grid(char **grid, int base)
{
	int	size;

	size = (base + 1) * base;
	*grid = ft_strnew(size);
	while (--size >= 0)
	{
		if (size % (base + 1) < base)
			(*grid)[size] = '.';
		else
			(*grid)[size] = '\n';
	}
}

static void	insert_piece(char **grid, int base, t_piece *piece)
{
	int	y;
	int x;

	y = 0;
	while (y < piece->height)
	{
		x = 0;
		while (x < piece->width)
		{
			if ((piece->barray >> (16 * (y + 1) - 1 - x)) & 1)
				(*grid)[(piece->y + y) * (base + 1) + piece->x + x] = piece->letter;
			++x;
		}
		++y;
	}
}

static void	fill_grid(char **grid, int base, t_piece *pieces)
{
	while (pieces->letter)
	{
		insert_piece(grid, base, pieces);
		++pieces;
	}
}

void	print_grid(t_piece *pieces, int base)
{
	char	*grid;

	init_grid(&grid, base);
	fill_grid(&grid, base, pieces);
	ft_putstr(grid);
	ft_strdel(&grid);
}
