/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:26:36 by cmartine          #+#    #+#             */
/*   Updated: 2017/11/27 13:35:01 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skiplastspaces(char const *s)
{
	int i;
	int	j;
	int size;

	j = ft_strlen(s) - 1;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && (j != 0))
		j--;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && (s[i] != '\0'))
		i++;
	size = ((j + 1) - i);
	return (size);
}

static int	ft_skipfirstspaces(char const *s)
{
	int i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && (s[i] != '\0'))
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*s2;
	int		j;
	int		size;
	int		beg;

	if (s != NULL)
	{
		size = ft_skiplastspaces(s);
		beg = ft_skipfirstspaces(s);
		if (size < 0)
			size = 0;
		if (!(s2 = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		j = 0;
		while (j < size)
		{
			s2[j] = ((char)s[beg + j]);
			j++;
		}
		s2[j] = '\0';
		return (s2);
	}
	return (NULL);
}
