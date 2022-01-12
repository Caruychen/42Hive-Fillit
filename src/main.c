/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:44:20 by cchen             #+#    #+#             */
/*   Updated: 2022/01/12 12:01:43 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_stdio.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (1);
	}
	read_inputs(argv[1]);
	return (0);
}
