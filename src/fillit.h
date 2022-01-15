/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:34:12 by cchen             #+#    #+#             */
/*   Updated: 2022/01/15 22:51:20 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define TET_BUFF 20

typedef struct s_piece
{
	uint64_t	barray;
	uint8_t		letter;
	uint8_t		x;
	uint8_t		y;
	uint8_t		width;
	uint8_t		height;
}	t_piece;

typedef struct s_point
{
	uint8_t		x;
	uint8_t		y;
}	t_point;

int	valid_piece(char *piece, int bytes);
int	read_input(char *filename);

#endif
