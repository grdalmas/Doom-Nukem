/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:05:57 by cmartine          #+#    #+#             */
/*   Updated: 2017/11/27 13:03:59 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		if (n == -2147483648)
			return (12);
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char			*strn;
	int				neg;
	int				len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	len = ft_len(n);
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	if (!(strn = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	strn[len] = '\0';
	while (len > 0)
	{
		strn[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (neg == 1)
		strn[0] = '-';
	return (strn);
}
