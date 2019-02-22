/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:38:36 by cmartine          #+#    #+#             */
/*   Updated: 2017/11/23 17:27:39 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_returnvalue(unsigned long rslt, unsigned long ngtv)
{
	if (ngtv == 1)
	{
		rslt = -rslt;
		if (rslt < 9223372036854775807)
			return (0);
	}
	if (rslt > 9223372036854775807 && ngtv == 0)
		return (-1);
	return (((int)rslt));
}

int			ft_atoi(const char *str)
{
	int				i;
	unsigned long	rslt;
	int				ngtv;

	i = 0;
	rslt = 0;
	ngtv = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
			i++;
		if (str[i] == '+')
			i++;
		if ((str[i] == '-' && str[i - 1] != '+'))
		{
			ngtv = 1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
			rslt = rslt * 10 + (str[i++] - '0') % 10;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (((int)ft_returnvalue(rslt, ngtv)));
	}
	return (0);
}
