/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:44:50 by cchen             #+#    #+#             */
/*   Updated: 2022/01/25 12:16:40 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	valid_char(const char *src, const int index)
{
	char	c;

	c = src[index];
	if (index % 5 < 4)
		return (c == '#' || c == '.');
	return (c == '\n');
}

static int	validity_check(const int index,
		const unsigned int links, const unsigned int blocks)
{
	return (!(
			(index == TET_BUFF - 1 && blocks < 4)
			|| (blocks == 4 && links < 3)
			|| blocks > 4
		));
}

static int	valid_blocks(const char *src, const int index)
{
	static unsigned int	links;
	static unsigned int	blocks;

	if (index == 0)
	{
		links = 0;
		blocks = 0;
	}
	blocks += src[index] == '#';
	if (src[index] == '#')
	{
		if ((index - 1) >= 0 && src[index - 1] == '#')
			++links;
		if ((index - 5) >= 0 && src[index - 5] == '#')
			++links;
	}
	return (validity_check(index, links, blocks));
}

int	valid_piece(const char *src, const int bytes)
{
	int	index;

	if (bytes < TET_BUFF)
		return (0);
	index = 0;
	while (index < TET_BUFF)
	{
		if (!valid_char(src, index)
			|| !valid_blocks(src, index))
			return (0);
		++index;
	}
	return (!(bytes == TET_BUFF + 1 && src[index] != '\n'));
}
