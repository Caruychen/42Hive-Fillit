/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:17:23 by cchen             #+#    #+#             */
/*   Updated: 2022/01/25 14:50:49 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

static int	board_size(int count)
{
	int	size;

	size = ft_sqrt(count * 4);
	if (!size)
	{
		size = 3;
		while (size * size < count * 4)
			size++;
	}
	return (size);
}

static int	backtracking(int size, t_piece *piece, uint16_t *bitmap)
{
	t_piece		pos;

	if (piece->letter == 0)
		return (1);
	pos = *piece;
	pos.y = 0;
	while (pos.y <= size - pos.height)
	{
		pos.x = 0;
		while (pos.x <= size - pos.width)
		{
			if (!(*(uint64_t *)(bitmap + pos.y) & (pos.barray >> pos.x)))
			{
				piece->x = pos.x;
				piece->y = pos.y;
				(*(uint64_t *)(bitmap + pos.y) ^= (pos.barray >> pos.x));
				if (backtracking(size, piece + 1, bitmap))
					return (1);
				(*(uint64_t *)(bitmap + pos.y) ^= (pos.barray >> pos.x));
			}
			pos.x++;
		}
	pos.y++;
	}
	return (0);
}

int	solve_map(int count, t_piece *piece)
{
	uint16_t	bitmap[16];
	int			size;

	ft_bzero(bitmap, sizeof(uint16_t) * 16);
	size = board_size(count);
	while (!backtracking(size, piece, bitmap))
	{
		ft_bzero(bitmap, sizeof(uint16_t) * 16);
		size++;
	}
	return (size);
}
