/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:35:39 by cjullien          #+#    #+#             */
/*   Updated: 2021/09/15 17:36:19 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memory_block, int searched_char, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)memory_block;
	while (i < size)
	{
		if (str[i] == (char)searched_char)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
