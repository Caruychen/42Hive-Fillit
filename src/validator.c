/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:44:50 by cchen             #+#    #+#             */
/*   Updated: 2022/01/15 22:28:06 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	valid_char(char *piece, int index)
{
	char	c;

	c = piece[index];
	if (index % 5 < 4)
		return (c == '#' || c == '.');
	return (c == '\n');
}

static int	validity_check(int index, unsigned int links, unsigned int blocks)
{
	return (!(
			(index == TET_BUFF - 1 && blocks < 4)
			|| (blocks == 4 && links < 3)
			|| blocks > 4
		));
}

static int	valid_blocks(char *piece, int index)
{
	static unsigned int	links;
	static unsigned int	blocks;

	if (index == 0)
	{
		links = 0;
		blocks = 0;
	}
	blocks += piece[index] == '#';
	if (piece[index] == '#')
	{
		if ((index - 1) >= 0 && piece[index - 1] == '#')
			++links;
		if ((index - 5) >= 0 && piece[index - 5] == '#')
			++links;
	}
	return (validity_check(index, links, blocks));
}

static int	valid_end(char c, int bytes)
{
	return (!(bytes == TET_BUFF + 1 && c != '\n'));
}

int	valid_piece(char *piece, int bytes)
{
	int	index;

	if (bytes < TET_BUFF)
		return (0);
	index = 0;
	while (index < TET_BUFF)
	{
		if (!valid_char(piece, index)
			|| !valid_blocks(piece, index))
			return (0);
		++index;
	}
	return (valid_end(piece[index], bytes));
}
