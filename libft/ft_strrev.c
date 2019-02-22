/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:31:04 by cmartine          #+#    #+#             */
/*   Updated: 2017/11/24 19:17:04 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	int		i;
	int		j;
	char	*s2;

	if (s != NULL)
	{
		i = ft_strlen(s) - 1;
		if (!(s2 = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		j = 0;
		while (i >= 0)
			s2[j++] = s[i--];
		s2[j] = '\0';
		return (s2);
	}
	return (NULL);
}
