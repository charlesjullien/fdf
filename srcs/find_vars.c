/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:48:34 by cjullien          #+#    #+#             */
/*   Updated: 2021/09/23 14:59:40 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	find_biggest_z(t_data *data)
{
	int		curr;
	int		i;
	int		j;

	curr = data->map[0][0];
	i = 0;
	while (i < data->lines)
	{
		j = 0;
		while (j < data->llen[i])
		{
			if (data->map[i][j] > curr)
				curr = data->map[i][j];
			j++;
		}
		i++;
	}
	data->bigz = curr;
}

void	find_lowest_z(t_data *data)
{
	int		curr;
	int		i;
	int		j;

	curr = data->map[0][0];
	i = 0;
	while (i < data->lines)
	{
		j = 0;
		while (j < data->llen[i])
		{
			if (data->map[i][j] < curr)
				curr = data->map[i][j];
			j++;
		}
		i++;
	}
	data->lowz = curr;
}

int	find_frame(t_data *d)
{
	double		f1;
	double		f2;

	f1 = d->si * ((d->biggest_line * d->si) - (d->lines * d->ci));
	if ((d->si * d->lines) > (d->ci * d->lines))
		f2 = X_RES / (d->si * d->lines);
	else
		f2 = X_RES / (d->ci * d->biggest_line);
	if (f2 < ((Y_RES * 1.0) / (f1 + (d->ci * (d->bigz - d->lowz)))))
		d->f = f2;
	else
		d->f = ((Y_RES * 1.0) / (f1 + (d->ci * (d->bigz - d->lowz))));
	d->startx = (int)((d->lines) * d->f);
	d->starty = (int)((d->f) * d->ci * d->bigz);
	if (d->startx > X_RES || d->starty > Y_RES)
		return (0);
	return (1);
}

void	find_posxy(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	d->posx = malloc(sizeof(int *) * d->lines);
	d->posy = malloc(sizeof(int *) * d->lines);
	while (i < d->lines)
	{
		d->posx[i] = malloc(sizeof(int) * d->llen[i]);
		d->posy[i] = malloc(sizeof(int) * d->llen[i]);
		i++;
	}
	i = 0;
	while (i < d->lines)
	{
		j = 0;
		while (j < d->llen[i])
		{
			find_posxy2(d, i, j);
			j++;
		}
		i++;
	}
}

int	find_vars(t_data *data)
{
	data->ci = cos(INC);
	data->si = sin(INC);
	find_biggest_z(data);
	find_lowest_z(data);
	if (!find_frame(data))
		return (0);
	find_posxy(data);
	if (!data->posx || !data->posy)
		return (0);
	if (!draw(data))
		return (0);
	return (1);
}
