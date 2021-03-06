/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:09:46 by cjullien          #+#    #+#             */
/*   Updated: 2021/09/15 17:52:21 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int to_find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	while (str[i] != to_find)
	{
		if (i == 0)
		{
			return (NULL);
		}
		i--;
	}
	return ((char *)&str[i]);
}
