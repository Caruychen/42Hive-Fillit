/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:17:23 by cchen             #+#    #+#             */
/*   Updated: 2022/01/25 16:08:57 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_math.h"
#include "ft_string.h"

static int	get_size(const int count)
{
	int	size;

	size = ft_sqrt(count * 4);
	if (!size)
	{
		size = 3;
		while (size * size < count * 4)
			++size;
	}
	return (size);
}

static int	fill_bitmap(uint16_t *bitmap, const int size, t_piece *piece)
{
	t_piece	local;

	local = *piece;
	if (local.letter == 0)
		return (1);
	local.y = 0;
	while (local.y <= size - local.height)
	{
		local.x = 0;
		while (local.x <= size - local.width)
		{
			if (!(*(uint64_t *)(bitmap + local.y) & (local.barray >> local.x)))
			{
				piece->x = local.x;
				piece->y = local.y;
				*(uint64_t *)(bitmap + local.y) ^= local.barray >> local.x;
				if (fill_bitmap(bitmap, size, piece + 1))
					return (1);
				*(uint64_t *)(bitmap + local.y) ^= local.barray >> local.x;
			}
			local.x++;
		}
		local.y++;
	}
	return (0);
}

int	solve_map(t_piece *pieces, const int count)
{
	int			size;
	uint16_t	bitmap[16];

	size = get_size(count);
	ft_bzero(bitmap, sizeof(*bitmap) * 16);
	while (!fill_bitmap(bitmap, size, pieces))
	{
		ft_bzero(bitmap, sizeof(*bitmap) * 16);
		++size;
	}
	return (size);
}
