/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:08:19 by cjullien          #+#    #+#             */
/*   Updated: 2021/09/15 17:47:54 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen((char *)source);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	while (source[i])
	{
		new[i] = source[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
