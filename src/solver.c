/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:17:23 by cchen             #+#    #+#             */
/*   Updated: 2022/01/20 12:07:23 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_math.h"
#include "ft_string.h"

static inline int	test_fit(uint16_t *grid, t_piece *piece)
{
	return (!(*(uint64_t *)(grid + piece->y) & (piece->barray >> piece->x)));
}

static inline int	set_piece(uint16_t *grid, t_piece *piece)
{
	*(uint64_t *)(grid + piece->y) ^= piece->barray >> piece->x;
	return (1);
}

static int	fit_piece(uint16_t *grid, int base, t_piece *piece)
{
	static int	res;
	int			pos;

	if (res == -1 && (*(uint64_t *)(grid + piece->y)))
	{
		set_piece(grid, piece);
		piece->x++;
	}
	if (piece->last && res != -1)
		pos = piece->last->x + piece->last->y * base;
	else
		pos = piece->x + piece->y * base;
	piece->y = pos / base;
	while (piece->y <= base - piece->height)
	{
		if (piece->y != pos / base)
			piece->x = 0;
		else
			piece->x = pos % base;
		while (piece->x <= base - piece->width)
		{
			if (test_fit(grid, piece))
				return (res = set_piece(grid, piece));
			piece->x++;
		}
		piece->y++;
	}
	piece->y = 0;
	piece->x = 0;
	return (res = -1);
}

static int	fill_grid(int base, t_piece *pieces)
{
	int			index;
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
	int	blocks;

	blocks = count * 4;
	base = ft_sqrt(blocks);
	if (!base)
	{
		base = 3;
		while (base * base < blocks)
			++base;
	}
	while (!fill_grid(base, pieces))
		++base;
	return (base);
}
