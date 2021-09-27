/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:48:01 by cjullien          #+#    #+#             */
/*   Updated: 2021/09/27 13:25:55 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_leftover(t_mlx *img)
{
	int		i;

	i = 0;
	while (i < img->data->lines)
	{
		free(img->data->posx[i]);
		free(img->data->posy[i]);
		i++;
	}
	free(img->data->posx);
	free(img->data->posy);
	free(img->data->llen);
}

int	key_hook(int keycode, t_mlx *img)
{
	int		i;

	if (keycode == ESC)
	{
		i = 0;
		while (i < img->data->lines)
		{
			free(img->data->map[i]);
			i++;
		}
		free(img->data->map);
		free_leftover(img);
		mlx_destroy_window(img->mlx, img->win);
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		exit(0);
	}
	return (1);
}

void	horizontal(t_data *d, t_mlx *img, t_bres *b)
{
	int		i;
	int		j;

	i = 0;
	while (i < d->lines)
	{
		j = 0;
		while (j + 1 < d->llen[i])
		{
			b->x0 = d->posx[i][j];
			b->x1 = d->posx[i][j + 1];
			b->y0 = d->posy[i][j];
			b->y1 = d->posy[i][j + 1];
			b->z1 = d->map[i][j];
			b->z2 = d->map[i][j + 1];
			bresenham_new_loop(b, img, d);
			j++;
		}
		i++;
	}
}

void	vertical(t_data *d, t_mlx *img, t_bres *b, int k)
{
	int		i;
	int		j;

	j = 0;
	while (j < d->biggest_line)
	{
		i = k;
		while (i + 1 < d->lines)
		{
			if (j < d->llen[i] && j < d->llen[i + 1])
			{
				bresenham_call(d, b, i, j);
				b->z1 = d->map[i][j];
				b->z2 = d->map[i + 1][j];
				bresenham_new_loop(b, img, d);
			}
			while (d->llen[i + 1] <= j && i + 1 < d->lines)
				i++;
			i++;
		}
		j++;
		while (j == d->llen[k])
			k++;
	}
}

int	draw(t_data *data)
{
	t_mlx	img;
	t_bres	bres;
	int		xgap;
	int		ygap;

	img.data = data;
	img.mlx = mlx_init();
	if (img.mlx == NULL)
		return (0);
	img.win = mlx_new_window(img.mlx, X_RES, Y_RES, "fdf");
	img.img = mlx_new_image(img.mlx, X_RES, Y_RES);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	horizontal(data, &img, &bres);
	vertical(data, &img, &bres, 0);
	mlx_key_hook(img.win, key_hook, &img);
	xgap = (X_RES - (data->bigx + data->lowx)) / 2;
	ygap = (Y_RES - (data->bigy + data->lowy)) / 2;
	mlx_put_image_to_window(img.mlx, img.win, img.img, xgap, ygap);
	mlx_loop(img.mlx);
	return (1);
}
