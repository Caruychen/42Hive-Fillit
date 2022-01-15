/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:25:52 by cchen             #+#    #+#             */
/*   Updated: 2022/01/15 23:38:39 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "fillit.h"

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
	return (bytes);
}

int	read_input(char *filename)
{
	int		fd;
	uint8_t	count;
	char	buff[TET_BUFF + 1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (get_next_piece(fd, buff) > 0)
	{
		ft_putendl("valid");
	}
	return (close(fd));
}
