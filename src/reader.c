/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:25:52 by cchen             #+#    #+#             */
/*   Updated: 2022/01/26 17:14:16 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"

static long	read_piece(const int fd, char *buff, long *bytes)
{
	long	ret;

	ret = 0;
	while (*bytes < TET_BUFF + 1)
	{
		ret = read(fd, buff + *bytes, (size_t)(TET_BUFF + 1 - *bytes));
		if (ret < 0)
			return (*bytes = ret);
		if (ret == 0)
			break ;
		*bytes += ret;
	}
	return (*bytes);
}

static long	get_next_piece(const int fd, char *buff)
{
	long	bytes;

	bytes = 0;
	if (read_piece(fd, buff, &bytes) <= 0)
		return (bytes);
	if (!valid_piece(buff, (int) bytes))
		return (-1);
	return (bytes);
}

static int	reading(const int fd, char *buff, int *count)
{
	static int	res;
	int			curr_res;	

	curr_res = (int) get_next_piece(fd, buff);
	if (curr_res < 0)
		return (*count = -1);
	if (curr_res == 0 && res > 20)
		return (*count = -1);
	if (curr_res > 0 && *count == 26)
		return (*count = -1);
	return (res = curr_res);
}

int	read_input(const char *filename, t_piece *pieces, int *count)
{
	int		fd;
	char	buff[TET_BUFF + 1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	*count = 0;
	while (reading(fd, buff, count) > 0)
		build_piece(pieces++, buff, (*count)++);
	if (close(fd) == -1)
		return (-1);
	return (*count);
}
