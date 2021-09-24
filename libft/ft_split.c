/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:54:13 by cjullien          #+#    #+#             */
/*   Updated: 2021/09/15 17:57:06 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	free_split(char **tab, unsigned int j)
{
	int	x;

	x = (int)j;
	while (--x >= 0)
		free((tab)[x]);
	free(tab);
	return (0);
}

unsigned int	get_nbr_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nbr_words;

	i = 0;
	nbr_words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			nbr_words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nbr_words);
}

int	splitter(char **tab, char const *s, char c, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	wordlen;

	i = 0;
	j = 0;
	while (j < n)
	{
		wordlen = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			wordlen++;
		}
		tab[j] = ft_substr(s, (i - wordlen), wordlen);
		if (!tab[j])
			return (free_split(tab, j));
		j++;
	}
	tab[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	nbr_words;

	if (!s)
		return (NULL);
	nbr_words = get_nbr_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (nbr_words + 1));
	if (!tab)
		return (NULL);
	if (splitter(tab, s, c, nbr_words))
		return (tab);
	return (NULL);
}
