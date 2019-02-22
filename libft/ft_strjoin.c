/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:02:43 by cmartine          #+#    #+#             */
/*   Updated: 2017/11/27 15:10:17 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		if (!(s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1)
							+ ft_strlen(s2) + 1))))
			return (NULL);
		while (s1[i] != '\0')
		{
			s3[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
		{
			s3[i + j] = s2[j];
			j++;
		}
		s3[i + j] = '\0';
		return (s3);
	}
	return (NULL);
}
