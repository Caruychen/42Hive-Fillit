/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:34:12 by cchen             #+#    #+#             */
/*   Updated: 2022/01/18 15:33:45 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define TET_BUFF 20
# define MAX_PIECES 26
# include <stdint.h>

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

int		valid_piece(char *piece, int bytes);
int		read_input(char *filename, t_piece *pieces, int *count);
t_piece	build_piece(const char *str, const int count);
int	solve_square(t_piece *pieces, int count);
void	print_grid(t_piece *pieces, int base);

#endif
