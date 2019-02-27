/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:26:12 by bbataini          #+#    #+#             */
/*   Updated: 2019/02/27 01:51:53 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void	img_to_img(t_struct *p, int x, int y, int indice, float sizeup)
{
	int line;
	int col;
	int tmp;
	int tmpy;

	tmpy = y;
	tmp = x;
	line = 0;
	col = 0;
	x++;
	while (col + line * p->tex[p->tid].sizeline < p->tex[p->tid].sizeline * p->tex[p->tid].height)
	{
		p->color.a = p->tex[p->tid].img_str[col * 32 / 8 + line * p->tex[p->tid].sizeline + 3];
		if (p->color.a == 0)
		{
			p->color.r = p->tex[p->tid].img_str[col * 32 / 8 + line * p->tex[p->tid].sizeline];
			p->color.g = p->tex[p->tid].img_str[col * 32 / 8 + line * p->tex[p->tid].sizeline + 1];
			p->color.b = p->tex[p->tid].img_str[col * 32 / 8 + line * p->tex[p->tid].sizeline + 2];
			if (indice == 0)
				draw_pixel2(p, p->img_str2, x, y);
			else if (x > 0 && x < WIDTH)
				draw_pixel2(p, p->img_str2, x, y);
		}
		col = (x - tmp) / sizeup;
		if (col == p->tex[p->tid].sizeline / 4)
		{
			line = (y - tmpy) / sizeup;
			y++;
			x = tmp;
		}
		x++;
		if (y > HEIGHT)
			break ;
	}
}
