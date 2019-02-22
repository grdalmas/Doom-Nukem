/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:07:51 by cmartine          #+#    #+#             */
/*   Updated: 2017/11/27 13:30:29 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			snew[i] = (char)(f(*(s + i)));
			i++;
		}
		snew[i] = '\0';
		return (snew);
	}
	return (NULL);
}
