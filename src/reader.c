/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:25:52 by cchen             #+#    #+#             */
/*   Updated: 2022/01/12 14:57:32 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_stdio.h"
#include "get_next_line.h"
#include "ft_stdlib.h"
#include "fillit.h"

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
