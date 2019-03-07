/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <tifuret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:26:12 by bbataini          #+#    #+#             */
/*   Updated: 2019/03/07 20:58:36 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			img_to_img3(t_struct *p, int x, int y, int indice)
{
	p->i.tmpy = y;
	p->i.tmp = x - 1;
	p->i.l = 0;
	p->i.c = 0;
	while (p->i.c + p->i.l * 5120 < 5120 * p->tex[indice].height)
	{
		p->color.a = p->tex[indice].img_str[p->i.c * 4 + p->i.l * 5120 + 3];
		if (p->color.a == 0)
		{
			p->color.r = p->tex[indice].img_str[p->i.c * 4 + p->i.l * 5120];
			p->color.g = p->tex[indice].img_str[p->i.c * 4 + p->i.l * 5120 + 1];
			p->color.b = p->tex[indice].img_str[p->i.c * 4 + p->i.l * 5120 + 2];
			draw_pixel2(p, p->img_str2, x, y);
		}
		p->i.c = (x - p->i.tmp);
		if (p->i.c == 5120 / 4)
		{
			p->i.l = (y - p->i.tmpy);
			y++;
			x = p->i.tmp;
		}
		x++;
		if (y > HEIGHT)
			break ;
	}
}

void			img_to_img2(t_struct *p, int x, int y, int indice)
{
	p->i.tmpy = y;
	p->i.tmp = x - 1;
	p->i.l = 0;
	p->i.c = 0;
	while (p->i.c + p->i.l * 1024 < 1024 * 256)
	{
		p->color.a = p->tex[indice].img_str[p->i.c * 4 + p->i.l * 1024 + 3];
		if (p->color.a == 0)
		{
			p->color.r = p->tex[indice].img_str[p->i.c * 4 + p->i.l * 1024];
			p->color.g = p->tex[indice].img_str[p->i.c * 4 + p->i.l * 1024 + 1];
			p->color.b = p->tex[indice].img_str[p->i.c * 4 + p->i.l * 1024 + 2];
			draw_pixel2(p, p->img_str2, x, y);
		}
		p->i.c = (x - p->i.tmp) / 0.15625;
		if (p->i.c == p->tex[indice].sizeline / 4)
		{
			p->i.l = (y - p->i.tmpy) / 0.15625;
			y++;
			x = p->i.tmp;
		}
		x++;
		if (y > HEIGHT)
			break ;
	}
}

void			img_to_img(t_struct *p, int x, int y, int indice)
{
	p->i.tmpy = y;
	p->i.tmp = x - 1;
	p->i.l = 0;
	p->i.c = 0;
	while (p->i.c + p->i.l * 1024 < 1024 * p->tex[indice].height)
	{
		p->color.a = p->tex[indice].img_str[p->i.c * 4 + p->i.l * 1024 + 3];
		if (p->color.a == 0)
		{
			p->color.r = p->tex[indice].img_str[p->i.c * 4 + p->i.l * 1024];
			p->color.g = p->tex[indice].img_str[p->i.c * 4 + p->i.l * 1024 + 1];
			p->color.b = p->tex[indice].img_str[p->i.c * 4 + p->i.l * 1024 + 2];
			draw_pixel2(p, p->img_str2, x, y);
		}
		p->i.c = (x - p->i.tmp) / 0.3;
		if (p->i.c == 1024 / 4)
		{
			p->i.l = (y - p->i.tmpy) / 0.3;
			y++;
			x = p->i.tmp;
		}
		x++;
		if (y > HEIGHT)
			break ;
	}
}

void			color_text_sky(t_struct *p, int col, int line)
{
	col = col * BPP;
	line = line * SKYHEIGHT;
	if (col + line + 3 < SKYHW && col >= 0 && line > 0)
	{
		p->color.r = (unsigned char)(p->tex[p->skytex].img_str[col + line]);
		p->color.g = (unsigned char)(p->tex[p->skytex].img_str[col + line + 1]);
		p->color.b = (unsigned char)(p->tex[p->skytex].img_str[col + line + 2]);
	}
}
