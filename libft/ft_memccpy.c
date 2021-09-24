/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:00:26 by cjullien          #+#    #+#             */
/*   Updated: 2021/09/15 17:45:01 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int ch, size_t max_size)
{
	size_t			i;
	unsigned char	*destination;
	unsigned char	*source;

	if (!dest && !src)
		return (NULL);
	i = 0;
	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (i < max_size)
	{
		destination[i] = source[i];
		if (source[i] == (unsigned char)ch)
			return (destination + (1 + i));
		i++;
	}
	return (NULL);
}
