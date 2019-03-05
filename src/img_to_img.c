/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:26:12 by bbataini          #+#    #+#             */
/*   Updated: 2019/03/05 06:09:23 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

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

static void			color_text_sky(t_struct *p, int col, int line, int tex)
{
	col = col * BPP;
	line = line * SKYHEIGHT;
	if (col + line + 3 < SKYHW && col >= 0 && line > 0)
	{
		p->color.r = (unsigned char)(p->tex[tex].img_str[col + line]);
		p->color.g = (unsigned char)(p->tex[tex].img_str[col + line + 1]);
		p->color.b = (unsigned char)(p->tex[tex].img_str[col + line + 2]);
	}
}

void			skybox(t_struct *p, int y, int x)
{
	double		t;
	int			tex;
	int			tx;
	int			ty;
	int			tmp_y;

	tex = 0;
	t = atan2(p->c->r_dir_x, p->c->r_dir_y) * 180 / PI;
	while (t < 0.0)
		t += 360.0;
	while (t >= 360.0)
		t -= 360.0;
	if (t >= 0 && t < 90)
		tex = 107;
	else if (t >= 90 && t < 180)
		tex = 108;
	else if (t >= 180 && t < 270)
		tex = 109;
	else if (t >= 270 && t < 360)
		tex = 110;
	tx = ((int)((t / 90.0) * (double)p->tex[tex].width) % p->tex[tex].width);
	while (y-- >= 0 - p->h)
	{
		if (y < 0)
		{
			if (t >= 0 && t < 90)
				tex = 111;
			else if (t >= 90 && t < 180)
				tex = 112;
			else if (t >= 180 && t < 270)
				tex = 113;
			else if (t >= 270 && t < 360)
				tex = 114;
			tmp_y = -y;
			ty = (int)(((double)tmp_y / ((double)((HEIGHT)) / 2.1))
					* p->tex[tex].height) % (p->tex[tex].height);
			ty = 639 - ty;
		}
		else
			ty = (int)(((double)y / ((double)((HEIGHT)) / 2.1))
					* p->tex[tex].height) % (p->tex[tex].height);
		color_text_sky(p, tx, ty, tex);
		draw_pixel2(p, p->img_str2, x, y + p->h);
	}
}
