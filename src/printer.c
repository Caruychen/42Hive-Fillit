/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:33:09 by cchen             #+#    #+#             */
/*   Updated: 2022/01/24 11:26:25 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"

static void	init_grid(char **grid, const int base)
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

static void	insert_char(char **grid, const int base, t_point p, t_piece piece)
{
	(*grid)[(piece.y + p.y) * (base + 1) + piece.x + p.x] = piece.letter;
}

static void	insert_piece(char **grid, const int base, t_piece piece)
{
	t_point	p;

	p.y = 0;
	while (p.y < piece.height)
	{
		p.x = 0;
		while (p.x < piece.width)
		{
			if ((piece.barray >> (16 * (p.y + 1) - 1 - p.x)) & 1)
				insert_char(grid, base, p, piece);
			++p.x;
		}
		++p.y;
	}
}

static void	fill_grid(char **grid, const int base, t_piece *pieces)
{
	while (pieces->letter)
	{
		insert_piece(grid, base, *pieces);
		++pieces;
	}
}

void	print_grid(t_piece *pieces, const int base)
{
	char	*grid;

	init_grid(&grid, base);
	fill_grid(&grid, base, pieces);
	ft_putstr(grid);
	ft_strdel(&grid);
}
