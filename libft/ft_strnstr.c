/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:52:46 by cmartine          #+#    #+#             */
/*   Updated: 2017/11/27 13:32:52 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return (((char *)haystack));
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' && needle[j] == haystack[i + j]
				&& (i + j) < len && haystack[i + j] != '\0')
			j++;
		if (needle[j] == '\0')
			return (&(((char *)haystack)[i]));
		i++;
	}
	return (NULL);
}
