/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:45:58 by cmartine          #+#    #+#             */
/*   Updated: 2017/11/27 13:31:15 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned long	i;
	char			*snew;

	i = 0;
	if (s != NULL)
	{
		if (!(snew = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1)))
			return (NULL);
		while (i < (ft_strlen(s)))
		{
			snew[i] = (char)(f(i, *(s + i)));
			i++;
		}
		snew[i] = '\0';
		return (snew);
	}
	return (NULL);
}
