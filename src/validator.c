/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:44:50 by cchen             #+#    #+#             */
/*   Updated: 2022/01/12 16:58:39 by cchen            ###   ########.fr       */
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

static int	valid_blocks(char *piece, int index)
{
	static unsigned int	links;
	static unsigned int	blocks;

	if (index == 0)
	{
		links = 0;
		blocks = 0;
	}
	if (piece[index] == '#')
	{
		if ((index - 1) >= 0 && piece[index - 1] == '#')
			++links;
		if ((index - 5) >= 0 && piece[index - 5] == '#')
			++links;
	}
	blocks += piece[index] == '#';
	return (!((blocks == 4 && links < 3) || blocks > 4));
}

static int	valid_end(char c, int bytes)
{
	return (!(bytes == TET_SIZE + 1 && c != '\n'));
}

int	valid_piece(char *piece, int bytes)
{
	int	index;

	index = 0;
	while (index < TET_SIZE)
	{
		if (!valid_char(piece, index) || !valid_blocks(piece, index))
			return (0);
		++index;
	}
	return (valid_end(piece[index], bytes));
}
