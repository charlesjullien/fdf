/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:53:17 by cjullien          #+#    #+#             */
/*   Updated: 2021/09/23 18:03:48 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_mlx *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham2(t_bres *b, t_mlx *img, t_data *d)
{
	int	i;
	int	color;

	i = 0;
	while (i <= b->disty)
	{
		color = get_color(d, b);
		my_mlx_pixel_put(img, b->x0, b->y0, color);
		b->y0 += b->yincr;
		b->ey -= b->dx;
		if (b->ey < 0)
		{
			b->x0 += b->xincr;
			b->ey += b->dy;
		}
		i++;
	}	
}

void	bresenham1(t_bres *b, t_mlx *img, t_data *d)
{
	int	i;
	int	color;

	i = 0;
	while (i <= b->distx)
	{
		color = get_color(d, b);
		my_mlx_pixel_put(img, b->x0, b->y0, color);
		b->x0 += b->xincr;
		b->ex -= b->dy;
		if (b->ex < 0)
		{
			b->y0 += b->yincr;
			b->ex += b->dx;
		}
		i++;
	}	
}

void	bresenham_new_loop(t_bres *b, t_mlx *img, t_data *d)
{
	b->ex = b->x1 - b->x0;
	b->ey = b->y1 - b->y0;
	if (b->ex < 0)
		b->ex = b->ex * (-1);
	if (b->ey < 0)
		b->ey = b->ey * (-1);
	b->dx = (2 * b->ex);
	b->dy = (2 * b->ey);
	b->distx = b->ex;
	b->disty = b->ey;
	b->xincr = 1;
	b->yincr = 1;
	if (b->x0 > b->x1)
		b->xincr = -1;
	if (b->y0 > b->y1)
		b->yincr = -1;
	if (b->distx > b->disty)
		bresenham1(b, img, d);
	if (b->distx <= b->disty)
		bresenham2(b, img, d);
}
