/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:45:08 by cchen             #+#    #+#             */
/*   Updated: 2022/01/17 13:18:11 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	init_points(t_point *min, t_point *max)
{
	min->x = 3;
	min->y = 3;
	max->x = 0;
	max->y = 0;
}

static void	assign_points(uint8_t index, t_point *min, t_point *max)
{
	if (index % 5 < min->x)
		min->x = index % 5;
	if (index / 5 < min->y)
		min->y = index / 5;
	if (index % 5 > max->x)
		max->x = index % 5;
	if (index / 5 > max->y)
		max->y = index / 5;
}

static void	get_dimensions(const char *str, t_point *min, t_point *max)
{
	uint8_t		index;

	index = 0;
	init_points(min, max);
	while (index < TET_BUFF)
	{
		if (str[index] == '#')
			assign_points(index, min, max);
		++index;
	}
}

t_piece	build_piece(const char *str, const int count)
{
	t_piece		piece;
	t_point		start;
	t_point		end;
	uint8_t		x;
	uint8_t		y;

	get_dimensions(str, &start, &end);
	piece.width = end.x - start.x + 1;
	piece.height = end.y - start.y + 1;
	piece.letter = 'A' + count;
	piece.barray = 0;
	y = 0;
	while (y < piece.height)
	{
		x = 0;
		while (x < piece.width)
		{
			if (str[(start.y + y) * 5 + start.x + x] == '#')
				piece.barray |= 1L << (16 * (y + 1) - 1 - x);
			++x;
		}
		++y;
	}
	return (piece);
}
