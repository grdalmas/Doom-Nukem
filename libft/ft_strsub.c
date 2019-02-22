/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:14:27 by cmartine          #+#    #+#             */
/*   Updated: 2017/11/27 13:34:27 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*trc;
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		if (!(trc = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			trc[i] = s[start];
			i++;
			start++;
		}
		trc[i] = '\0';
		return (trc);
	}
	return (NULL);
}
