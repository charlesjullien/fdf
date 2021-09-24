/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:19:17 by cjullien          #+#    #+#             */
/*   Updated: 2021/09/23 18:32:48 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

long int	count_char(int fd, int rd, int buf, long int i)
{
	while (rd == 1)
	{
		rd = read(fd, (char *)&buf, 1);
		i++;
	}
	close(fd);
	return (i);
}

int	get_map(int fd, t_data *data, char *str, int buf)
{
	long int	i;
	long int	count;
	int			rd;

	i = 0;
	rd = 1;
	count = count_char(fd, rd, buf, i);
	fd = open(str, O_RDONLY);
	data->ff1 = malloc(sizeof(char) * count + 1);
	data->full_file = malloc(sizeof(char) * count + 1);
	if (!data->ff1)
		return (0);
	while (rd == 1)
	{
		rd = read(fd, (char *)&buf, 1);
		data->ff1[i] = buf;
		i++;
	}
	data->ff1[i] = '\0';
	close(fd);
	if (!malloc_tab(data))
		return (0);
	return (1);
}

void	data_init(t_data *data)
{
	data->lines = -1;
	data->biggest_line = 0;
	data->k = 0;
	data->ff1 = NULL;
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	data_init(&data);
	if (fd != -1)
	{
		if (get_map(fd, &data, av[1], 1))
			return (0);
	}
	return (0);
}
