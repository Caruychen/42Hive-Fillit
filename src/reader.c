/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:25:52 by cchen             #+#    #+#             */
/*   Updated: 2022/01/11 17:05:40 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_stdio.h"
#include "get_next_line.h"
#include "ft_stdlib.h"

static int	valid_char(char c)
{
	return (c == '#' || c == '.');
}

static int	valid_line(char *line)
{
	unsigned int	index;

	index = 0;
	while (line[index])
	{
		if (index == 4 || !valid_char(line[index]))
			return (0);
		++index;
	}
	if (index < 3)
		return (0);
	return (1);
}

static long	read_block(int fd, char *buff, long *bytes)
{
	long	ret;

	ret = 0;
	while (*bytes < 21)
	{
		ret = read(fd, buff + *bytes, 21 - *bytes);
		if (ret < 0)
			return (ret);
		if (ret == 0)
			break;
		bytes += ret;
	}
	return (*bytes);
}

static int	get_next_block(int fd)
{
	char	*buff[21];
	long	bytes;

	bytes = 0;
	if (read_block(fd, &buff, bytes) < 0)
		return (-1);
	if (
	
	return (bytes);
}

int	read_block(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	while (get_next_block(fd) > 0)
	{
		ft_putendl("valid");
	}
	close(fd);
	return (0);
}
