/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 03:10:31 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/05 05:03:58 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static void			shakeshadow(t_struct *p, int i, float distance)
{
	if (i == 0)
	{
		p->c->shadow = distance * 0.25;
		if (p->c->shadow > 1)
			p->c->shadow = 1;
	}
	else
	{
		p->c->shadow = ((double)HEIGHT / (2.0 * (double)p->c->y_end
					- (double)HEIGHT)) * 0.25;
		if (p->c->shadow > 1)
			p->c->shadow = 1;
	}
}

static void		floor_casting(t_struct *p, int x, int y, int z)
{
	double		distance;
	double		tmp_fl_x;
	double		tmp_fl_y;
	int			tex_x;
	int			tex_y;

	which_textf(p);
	y = p->c->y_end;
	z = HEIGHT - y;
	while (y++ < HEIGHT + abs(p->h) && z-- > 0 - abs(p->h))
	{
		distance = (double)HEIGHT / (2.0 * ((double)y) - (double)HEIGHT);
		p->c->ra = distance / p->c->wall_dist;
		if (p->k != 7)
			shakeshadow(p, 0, distance);
		tmp_fl_x = p->c->ra * p->c->floor_x + (1.0 - p->c->ra) * p->c->p_x;
		tmp_fl_y = p->c->ra * p->c->floor_y + (1.0 - p->c->ra) * p->c->p_y;
		tex_x = (int)(tmp_fl_x * p->tex[p->tid].width) % p->tex[p->tid].width;
		tex_y = (int)(tmp_fl_y * p->tex[p->tid].height) % p->tex[p->tid].height;
		color_textf(p, tex_x, tex_y, p->c->shadow);
		tex_y = y - HEIGHT + abs(p->h);
		draw_pixel2(p, p->img_str2, x, y + p->h);
		if (p->k != 9)
			draw_pixel2(p, p->img_str2, x, z + p->h);
	}
}

static void		draw_floor_3d(t_struct *p)
{
	if (p->c->side == 0 && p->c->r_dir_x > 0)
	{
		p->c->floor_x = p->c->map_x;
		p->c->floor_y = p->c->map_y + p->c->offset;
	}
	else if (p->c->side == 0 && p->c->r_dir_x < 0)
	{
		p->c->floor_x = p->c->map_x + 1.0;
		p->c->floor_y = p->c->map_y + p->c->offset;
	}
	else if (p->c->side == 1 && p->c->r_dir_y > 0)
	{
		p->c->floor_x = p->c->map_x + p->c->offset;
		p->c->floor_y = p->c->map_y;
	}
	else
	{
		p->c->floor_x = p->c->map_x + p->c->offset;
		p->c->floor_y = p->c->map_y + 1.0;
	}
}

static int				hodor(t_struct *p)
{
	int			tex_x;

	if (p->tid == p->porte[p->dodor].zip)
		tex_x = (int)((p->c->offset * 256 >= 256 ? 255 : (p->c->offset
						- p->porte[p->dodor].open) * 256));
	else
		tex_x = (int)((p->c->offset * 256 >= 256 ? 255 : p->c->offset * 256));
	draw_floor_3d(p);
	return (tex_x);
}

void			draw_wall_3d(t_struct *p, int x, int y, int wall_height)
{
	int			tex_x;
	int			tex_y;

	wall_height = abs((int)(HEIGHT / p->c->wall_dist));
	y = (int)(-wall_height / 2 + HEIGHT / 2) + p->h;
	p->c->y_end = (int)(wall_height / 2 + HEIGHT / 2);
	if (y < 0)
		y = 0;
	if (p->k == 9)
		skybox(p, y - p->h, x);
	tex_x = hodor(p);
	floor_casting(p, x, 0, 0);
	if (p->k != 7)
		shakeshadow(p, 1, 0);
	if (p->c->y_end > HEIGHT - p->h)
		p->c->y_end = HEIGHT - 1 - p->h;
	p->c->y_end += p->h;
	which_text(p);
	while (y++ <= p->c->y_end)
	{
		tex_y = (y * 2 - HEIGHT + wall_height - p->h * 2)
			* (p->tex[p->tid].height / 2) / wall_height;
		color_text(p, tex_x, tex_y, p->c->shadow);
		draw_pixel2(p, p->img_str2, x, y);
	}
}
