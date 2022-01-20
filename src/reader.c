/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:25:52 by cchen             #+#    #+#             */
/*   Updated: 2022/01/20 12:05:26 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_stdlib.h"
#include "fillit.h"
#include "ft_stdio.h"

static long	read_piece(int fd, char *buff, long *bytes)
{
	long	ret;

	ret = 0;
	while (*bytes < TET_BUFF + 1)
	{
		ret = read(fd, buff + *bytes, TET_BUFF + 1 - *bytes);
		if (ret < 0)
			return (*bytes = ret);
		if (ret == 0)
			break ;
		*bytes += ret;
	}
	return (*bytes);
}

static long	get_next_piece(int fd, char *buff)
{
	long	bytes;

	bytes = 0;
	if (read_piece(fd, buff, &bytes) <= 0)
		return (bytes);
	if (!valid_piece(buff, (int) bytes))
		return (-1);
	return (1);
}

static int	reading(int fd, char *buff, int *count)
{
	int	ret;

	ret = (int) get_next_piece(fd, buff);
	if (ret < 0 || *count == 26)
		return (*count = -1);
	return (ret);
}

int	read_input(char *filename, t_piece *pieces, int *count)
{
	int		fd;
	char	buff[TET_BUFF + 1];
	int		index;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	*count = 0;
	while (reading(fd, buff, count) > 0)
	{
		pieces[*count] = build_piece(buff, *count);
		index = *count - 1;
		while (index >= 0)
		{
			if (pieces[index].barray == pieces[index].barray)
				pieces[index].last = pieces + index;
			--index;
		}
		++*count;
	}
	close(fd);
	return (*count);
}
