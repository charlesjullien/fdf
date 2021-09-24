/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:20:28 by cjullien          #+#    #+#             */
/*   Updated: 2021/09/24 14:12:00 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef INC
#  define INC -0.7858
# endif
# ifndef X_RES
#  define X_RES 1440
# endif
# ifndef Y_RES
#  define Y_RES 850
# endif
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libmlx/mlx.h"
# define ESC 65307

typedef struct s_data	t_data;
struct			s_data
{
	int		**map;
	int		*llen;
	int		**posx;
	int		**posy;
	char	*full_file;
	char	*ff1;
	int		lines;
	int		biggest_line;
	int		bigz;
	int		lowz;
	double	ci;
	double	si;
	double	f;
	int		startx;
	int		starty;
	int		k;
	int		lowx;
	int		lowy;
	int		bigx;
	int		bigy;
};

typedef struct s_bres	t_bres;
struct			s_bres
{
	int	distx;
	int	disty;
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	ex;
	int	ey;
	int	xincr;
	int	yincr;
	int	dx;
	int	dy;
	int	z1;
	int	z2;
};

typedef struct s_mlx	t_mlx;
struct			s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
	t_data	*data;
};

int		malloc_tab(t_data *data);
int		find_vars(t_data *data);
void	find_posxy2(t_data *d, int i, int j);
int		draw(t_data *data);
void	bresenham_new_loop(t_bres *b, t_mlx *img, t_data *d);
void	bresenham_call(t_data *d, t_bres *b, int i, int j);
int		get_color(t_data *d, t_bres *b);
void	pass_non_decimal(t_data *d, int i, int j);

#endif
