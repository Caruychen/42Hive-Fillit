/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:17:23 by cchen             #+#    #+#             */
/*   Updated: 2022/01/18 14:55:08 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_math.h"
#include "ft_stdio.h"
#include "ft_string.h"

static int	find_sqr_base(int blocks)
{
	int	base;

	base = ft_sqrt(blocks);
	if (!base)
	{
		base = 3;
		while (base * base < blocks)
			++base;
	}
	return (base);
}

static inline int	test_fit(uint16_t *grid, t_piece *piece)
{
	return (!(*(uint64_t *)(grid + piece->y) & (piece->barray >> piece->x)));
}

static inline void	set_piece(uint16_t *grid, t_piece *piece)
{
	*(uint64_t *)(grid + piece->y) ^= piece->barray >> piece->x;
}

static int	fit_piece(uint16_t *grid, int base, t_piece *piece)
{
	if (piece->y != 0 || piece->x != 0)
		set_piece(grid, piece);
	while (piece->y <= base - piece->height)
	{
		piece->x = 0;
		while (piece->x <= base - piece->width)
		{
			if (test_fit(grid, piece))
			{
				set_piece(grid, piece);
				return (1);
			}
			piece->x++;
		}
		piece->y++;
	}
	piece->y = 0;
	piece->x = 0;
	return (-1);
}

static int	fill_grid(int base, t_piece *pieces)
{
	int	index;
	uint16_t	grid[16];

	index = 0;
	ft_bzero(grid, sizeof(*grid) * 16);
	while (pieces[index].letter != 0)
	{
		index += fit_piece(grid, base, &pieces[index]);
		if (index == -1)
			return (0);
	}
	return (1);
}

int	solve_square(t_piece *pieces, int count)
{
	int	base;

	base = find_sqr_base(count * 4);
	while (!fill_grid(base, pieces))
		++base;
	return (base);
}
