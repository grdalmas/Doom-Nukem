/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:51:35 by cmartine          #+#    #+#             */
/*   Updated: 2017/11/27 15:12:29 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		ls1;
	int		i;

	i = 0;
	ls1 = (ft_strlen(s1));
	if (!(s2 = (char *)malloc(sizeof(char) * ls1 + 1)))
		return (NULL);
	while (i < ls1)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
