/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:25:52 by cchen             #+#    #+#             */
/*   Updated: 2022/01/11 13:43:01 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_stdio.h"
#include "get_next_line.h"
#include "ft_stdlib.h"

int	read_block(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
