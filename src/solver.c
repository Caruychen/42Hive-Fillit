/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:17:23 by cchen             #+#    #+#             */
/*   Updated: 2022/01/20 15:14:41 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_math.h"
#include "ft_string.h"

static int	fill_grid(uint16_t *grid, int base, t_piece *piece)
{
	t_piece	local;

	local = *piece;
	if (local.letter == 0)
		return (1);
	local.y = 0;
	while (local.y <= base - local.height)
	{
		local.x = 0;
		while (local.x <= base - local.width)
		{
			if (!(*(uint64_t *)(grid + local.y) & (local.barray >> local.x)))
			{
				piece->x = local.x;
				piece->y = local.y;
				*(uint64_t *)(grid + local.y) ^= local.barray >> local.x;
				if (fill_grid(grid, base, piece + 1))
					return (1);
				*(uint64_t *)(grid + local.y) ^= local.barray >> local.x;
			}
			local.x++;
		}
		local.y++;
	}
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
