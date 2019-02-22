/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:29:13 by bbataini          #+#    #+#             */
/*   Updated: 2018/11/20 01:13:13 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_words(char const *s, char c)
{
	unsigned int	nb;
	size_t			i;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb++;
			while (s[i] != c && s[i])
				i++;
		}
		i++;
	}
	return (nb);
}

static unsigned int	ft_letters(char const *s, char c, size_t i)
{
	size_t	len;
	size_t	start;

	len = 0;
	start = i;
	while (s[i] && s[i] != c)
		i++;
	len = i - start;
	return (len);
}

static void			ft_init(size_t *i, size_t *x)
{
	*i = 0;
	*x = 0;
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	x;
	char	**tab;

	ft_init(&i, &x);
	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_words(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			tab[x] = ft_strsub(s, i, ft_letters(s, c, i));
			x++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	tab[x] = NULL;
	return (tab);
}
