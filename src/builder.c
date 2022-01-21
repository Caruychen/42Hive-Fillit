/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:45:08 by cchen             #+#    #+#             */
/*   Updated: 2022/01/21 13:57:35 by cchen            ###   ########.fr       */
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

static void	calc_points(uint8_t index, t_point *min, t_point *max)
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

static void	get_dimensions(const char *str, t_point *start, t_point *end)
{
	uint8_t		index;

	index = 0;
	init_points(start, end);
	while (index < TET_BUFF)
	{
		if (str[index] == '#')
			calc_points(index, start, end);
		++index;
	}
}

static void	encode_piece(t_piece *piece, const char *str, t_point start)
{
	t_point		curr;

	piece->barray = 0;
	curr.y = 0;
	while (curr.y < piece->height)
	{
		curr.x = 0;
		while (curr.x < piece->width)
		{
			if (str[(start.y + curr.y) * 5 + start.x + curr.x] == '#')
				piece->barray |= 1L << (16 * (curr.y + 1) - 1 - curr.x);
			++curr.x;
		}
		++curr.y;
	}
}

void	build_piece(t_piece *piece, const char *str, const int count)
{
	t_point		start;
	t_point		end;

	get_dimensions(str, &start, &end);
	piece->width = end.x - start.x + 1;
	piece->height = end.y - start.y + 1;
	piece->letter = 'A' + count;
	encode_piece(piece, str, start);
}
