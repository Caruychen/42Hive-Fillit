/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:17:23 by cchen             #+#    #+#             */
/*   Updated: 2022/01/20 13:54:39 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_math.h"
#include "ft_string.h"

static int	fill_grid(uint16_t *grid, int base, t_piece *piece)
{
	if (piece->letter == 0)
		return (1);
	while (piece->y <= base - piece->height)
	{
		piece->x = 0;
		while (piece->x <= base - piece->width)
		{
			if (!(*(uint64_t *)(grid + piece->y) & (piece->barray >> piece->x)))
			{
				*(uint64_t *)(grid + piece->y) ^= piece->barray >> piece->x;
				if (fill_grid(grid, base, piece + 1))
					return (1);
				*(uint64_t *)(grid + piece->y) ^= piece->barray >> piece->x;
			}
			piece->x++;
		}
		piece->y++;
	}
	piece->x = 0;
	piece->y = 0;
	return (0);
}

int	solve_square(t_piece *pieces, int count)
{
	int	base;
	int	blocks;
	uint16_t	grid[16];

	blocks = count * 4;
	base = ft_sqrt(blocks);
	if (!base)
	{
		base = 3;
		while (base * base < blocks)
			++base;
	}
	ft_bzero(grid, sizeof(*grid) * 16);
	while (!fill_grid(grid, base, pieces))
	{
		ft_bzero(grid, sizeof(*grid) * 16);
		++base;
	}
	return (base);
}
