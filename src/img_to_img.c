/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:26:12 by bbataini          #+#    #+#             */
/*   Updated: 2019/02/28 13:15:23 by grdalmas         ###   ########.fr       */
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
	while (col + line * p->tex[indice].sizeline < p->tex[indice].sizeline * p->tex[indice].height)
	{
		p->color.a = p->tex[indice].img_str[col * 32 / 8 + line * p->tex[indice].sizeline + 3];
		if (p->color.a == 0)
		{
			p->color.r = p->tex[indice].img_str[col * 32 / 8 + line * p->tex[indice].sizeline];
			p->color.g = p->tex[indice].img_str[col * 32 / 8 + line * p->tex[indice].sizeline + 1];
			p->color.b = p->tex[indice].img_str[col * 32 / 8 + line * p->tex[indice].sizeline + 2];
			if (indice == 0)
				draw_pixel2(p, p->img_str2, x, y);
			else if (x > 0 && x < WIDTH)
				draw_pixel2(p, p->img_str2, x, y);
		}
		col = (x - tmp) / sizeup;
		if (col == p->tex[indice].sizeline / 4)
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
