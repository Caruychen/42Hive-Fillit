/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:25:52 by cchen             #+#    #+#             */
/*   Updated: 2022/01/12 12:58:14 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_stdio.h"
#include "get_next_line.h"
#include "ft_stdlib.h"

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
	static unsigned int	vertices;
	static unsigned int	blocks;

	if (index == 0)
	{
		vertices = 0;
		blocks = 0;
	}
	blocks += piece[index] == '#';
}

static int	valid_piece(char *piece, int bytes)
{
	int	index;

	index = 0;
	while (index < 20)
	{
		if (!(valid_char(piece, index)))
			return (0);
		if (!(valid_blocks(piece, index)))
			return (0);
		++index;
	}
	if (bytes == 21 && piece[index] != '\n')
		return (0);
	return (1);
}

static long	read_piece(int fd, char *buff, long *bytes)
{
	long	ret;

	ret = 0;
	while (*bytes < 21)
	{
		ret = read(fd, buff + *bytes, 21 - *bytes);
		if (ret < 0)
			return (*bytes = ret);
		if (ret == 0)
			break ;
		*bytes += ret;
	}
	return (*bytes);
}

static int	get_next_piece(int fd)
{
	char	buff[21];
	long	bytes;

	bytes = 0;
	if (read_piece(fd, buff, &bytes) <= 0)
		return (bytes);
	if (!valid_piece(buff, (int) bytes))
		return (-1);
	return (bytes);
}

int	read_inputs(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	while (get_next_piece(fd) > 0)
	{
		ft_putendl("valid");
	}
	close(fd);
	return (0);
}
