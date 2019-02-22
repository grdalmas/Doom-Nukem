/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:24:10 by cmartine          #+#    #+#             */
/*   Updated: 2017/11/17 20:24:15 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_strlen(src);
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (j < len)
		while (j < len)
			dst[j++] = '\0';
	return (dst);
}
