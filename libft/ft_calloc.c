/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:15:25 by cjullien          #+#    #+#             */
/*   Updated: 2021/09/15 17:46:05 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t element_count, size_t element_size)
{
	void	*y;
	size_t	total_size;

	total_size = element_count * element_size;
	y = malloc(total_size);
	if (!y)
		return (NULL);
	ft_bzero(y, total_size);
	return (y);
}
