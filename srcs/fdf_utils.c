/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:27:06 by cjullien          #+#    #+#             */
/*   Updated: 2021/09/27 15:13:54 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_biggest_line(t_data *data)
{
	int		i;
	int		n;

	i = 0;
	n = data->llen[0];
	while (i < data->lines)
	{
		if (data->llen[i] > n)
			n = data->llen[i];
		i++;
	}
	data->biggest_line = n;
}

void	free_file(t_data *data)
{
	if (data->full_file)
		free(data->full_file);
	if (data->ff1)
		free(data->ff1);
}

void	fill_tab(t_data *data, int i, int j, int k)
{
	while (i < data->lines)
	{
		j = 0;
		while (data->full_file[k] != '\n')
		{
			if (ft_isdigit(data->full_file[k]) || data->full_file[k] == '-')
				data->map[i][j] = ft_atoi(&data->full_file[k]);
			while (ft_isdigit(data->full_file[k]) || data->full_file[k] == '-')
				k++;
			while (data->full_file[k] == ' ')
				k++;
			j++;
		}
		i++;
		k++;
	}
	get_biggest_line(data);
}

int	malloc_tab2(t_data *data, int i, int j)
{
	int		len;

	while (j < data->lines)
	{
		len = 0;
		while (data->full_file[i] != '\n')
		{
			while (ft_isdigit(data->full_file[i]) || data->full_file[i] == '-')
				i++;
			len++;
			while (data->full_file[i] == ' ')
				i++;
		}
		data->llen[j] = len;
		data->map[j] = malloc(sizeof(int) * len);
		if (data->map[j] == NULL)
			return (0);
		j++;
		i++;
	}
	return (1);
}

int	malloc_tab(t_data *data)
{
	int		i;

	i = 0;
	pass_non_decimal(data, 0, 0);
	while (data->full_file[i])
	{
		if (data->full_file[i] == '\n')
			data->lines++;
		i++;
	}
	data->map = malloc(sizeof(int *) * data->lines);
	data->llen = malloc(sizeof(int *) * data->lines);
	if (data->map == NULL || data->llen == NULL)
		return (0);
	if (!malloc_tab2(data, 0, 0))
		return (0);
	fill_tab(data, 0, 0, 0);
	free_file(data);
	if (!find_vars(data))
		return (0);
	return (1);
}
