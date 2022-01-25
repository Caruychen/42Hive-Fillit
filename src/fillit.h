/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:34:12 by cchen             #+#    #+#             */
/*   Updated: 2022/01/25 16:35:13 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define TET_BUFF 20
# define MAX_PIECES 26
# include <stdint.h>

typedef struct s_point
{
	uint8_t		x;
	uint8_t		y;
}	t_point;

typedef struct s_piece
{
	uint64_t	barray;
	uint8_t		letter;
	uint8_t		x;
	uint8_t		y;
	uint8_t		width;
	uint8_t		height;
}	t_piece;

int		valid_piece(const char *src, const int bytes);
int		read_input(const char *filename, t_piece *pieces, int *count);
void	build_piece(t_piece *piece, const char *str, const int count);
int		solve_map(t_piece *pieces, int count);
int		print_board(t_piece *pieces, const int size);

#endif
