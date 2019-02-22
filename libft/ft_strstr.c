/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:27:03 by cmartine          #+#    #+#             */
/*   Updated: 2017/11/27 13:33:45 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return (((char *)haystack));
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' && needle[j] == haystack[i + j])
		{
			j++;
		}
		if (needle[j] == '\0')
			return (&(((char *)haystack)[i]));
		i++;
	}
	return (NULL);
}
