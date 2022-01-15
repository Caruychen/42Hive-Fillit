/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:45:08 by cchen             #+#    #+#             */
/*   Updated: 2022/01/15 23:38:16 by cchen            ###   ########.fr       */
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

static void	get_dimensions(const char *str, t_piece *piece,
	t_point *min, t_point *max)
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
	piece->width = max.x - min.x + 1;
	piece->height = max.y - min.y + 1;
}

t_piece	build_piece(const char *str, const uint8_t count)
{
	t_piece		piece;
	t_point		start;
	t_point		end;

	piece.letter = 'A' + count;
	piece.barray = 0;
	get_dimensions(str, &piece, &start, &end);
	while (start.y < <= end.y)
	{
		while (start.x <= end.x)
		{
			if (str[start.y * 5 + start.x] == '#')
				piece.barray |= 1L << ();
			++start.x;
		}
		++start.y;
	}
	return (piece);
}
