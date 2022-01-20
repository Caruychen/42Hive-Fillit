/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:17:23 by cchen             #+#    #+#             */
/*   Updated: 2022/01/20 17:22:40 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

int	solve_map(int count, t_piece *piece)
{
	uint16_t	bitmap[16];
	t_piece		pos;

	ft_bzero(bitmap, sizeof(uint16_t) * 16);
	pos = *piece;
	pos.y = 0;
	while (pos.y <= count)
	{
		pos.x = 0;
		while (pos.x <= count)
		{
			if (!(*(uint64_t *)(bitmap + pos.y) & (pos.barray >> pos.x)))
			{
				piece->x = pos.x;
				piece->y = pos.y;
				(*(uint64_t *)(bitmap + pos.y) ^= (pos.barray >> pos.x));
				if (solve_map(count, piece + 1))
					return (1);
				(*(uint64_t *)(bitmap + pos.y) ^= (pos.barray >> pos.x));
			}
			pos.x++;
		}
	pos.y++;
	}
	return (0);
}
