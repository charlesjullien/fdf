/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vars2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:37:14 by cjullien          #+#    #+#             */
/*   Updated: 2021/09/24 12:27:12 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pass_non_decimal(t_data *d, int i, int j)
{
	while (d->ff1[i])
	{
		if (d->ff1[i] == ',')
		{
			while (d->ff1[i] != ' ' && d->ff1[i] != '\0' && d->ff1[i] != '\n')
				i++;
			i--;
		}
		else
		{
			d->full_file[j] = d->ff1[i];
			j++;
		}
		i++;
	}
	d->full_file[j] = '\0';
}

int	get_color(t_data *d, t_bres *b)
{
	double	depth;
	int		color;

	depth = 0.0;
	if ((b->distx > b->disty && b->distx > 0 && b->disty > 0) || (b->disty < 0
			&& b->distx > 0 && - b->disty > b->distx) || (b->disty == 0))
		depth = ((b->x0 - (b->x1 - b->distx)) * 1.0)
			/ ((b->x1 - (b->x1 - b->distx)) * 1.0);
	else if ((b->distx == 0) || (b->disty > 0 && b->disty > b->distx)
		|| (b->distx > b->disty && b->disty != 0))
		depth = ((b->y0 - (b->y1 - b->disty)) * 1.0)
			/ ((b->y1 - (b->y1 - b->disty)) * 1.0);
	if (depth > 1.0)
		depth = 1.0 / depth;
	color = (int)(120 * ((b->z1 * (1 - depth) + b->z2 * depth) / (d->bigz)));
	return ((125 + color) << 24 | (125 + color) << 16 | color << 8 | 255);
}

void	bresenham_call(t_data *d, t_bres *b, int i, int j)
{
	b->x0 = d->posx[i][j];
	b->x1 = d->posx[i + 1][j];
	b->y0 = d->posy[i][j];
	b->y1 = d->posy[i + 1][j];
}

void	find_posxy2(t_data *d, int i, int j)
{
	double	n;

	n = 0;
	d->posx[i][j] = (int)(d->startx + d->f * ((d->ci * j) + (d->si * i)));
	n = (d->si * ((d->si * j) - (d->ci * i)) - (d->ci * d->map[i][j]));
	d->posy[i][j] = (int)(d->starty + d->f * n);
	if (i == 0 && j == 0)
	{	
		d->lowy = d->posy[i][j];
		d->lowx = d->posx[i][j];
		d->bigy = d->posy[i][j];
		d->bigx = d->posx[i][j];
	}
	if (d->posy[i][j] < d->lowy)
		d->lowy = d->posy[i][j];
	if (d->posx[i][j] < d->lowx)
		d->lowx = d->posx[i][j];
	if (d->posy[i][j] > d->bigy)
		d->bigy = d->posy[i][j];
	if (d->posx[i][j] > d->bigx)
		d->bigx = d->posx[i][j];
}
