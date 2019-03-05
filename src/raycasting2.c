/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 04:39:14 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/05 04:51:40 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static void	draw_transparent_wall2(t_struct *p, int x, int y, int wall_h)
{
	int line;
	int tex_y;
	int tex_x;
	int col;

	tex_x = (int)((p->c->offset * 256 >= 256 ? 255 : p->c->offset * 256));
	col = tex_x * BPP;
	while (y++ <= p->c->y_end)
	{
		tex_y = (y * 2 - HEIGHT + wall_h - p->h * 2)
			* (p->tex[p->tid].height / 2) / wall_h;
		line = tex_y * 1024;
		if (col + line + 3 < 262144 && col >= 0 && line >= 0)
			p->color.a = p->tex[p->tid].img_str[col + line + 3];
		if (p->color.a == 0)
		{
			color_text(p, tex_x, tex_y, p->c->shadow);
			draw_pixel2(p, p->img_str2, x, y);
		}
	}
}

static void	draw_transparent_wall(t_struct *p, int x, int y, int wall_height)
{
	wall_height = abs((int)(HEIGHT / p->c->wall_dist));
	y = (int)(-wall_height / 2 + HEIGHT / 2) + p->h;
	p->c->y_end = (int)(wall_height / 2 + HEIGHT / 2);
	if (y < 0)
		y = 0;
	p->c->shadow = ((double)HEIGHT / (2.0 * (double)p->c->y_end
				- (double)HEIGHT)) * 0.25;
	if (p->c->shadow > 1)
		p->c->shadow = 1;
	if (p->c->y_end > HEIGHT - p->h)
		p->c->y_end = HEIGHT - 1 - p->h;
	p->c->y_end += p->h;
	if (p->hit == 2)
		p->tid = 6;
	else if (p->hit == 3 && p->s == -1)
		p->tid = 5;
	else if (p->hit == 3 && p->s >= 0)
		p->tid = 18;
	draw_transparent_wall2(p, x, y, wall_height);
}

static void	elevathor(t_struct *p)
{
	if (p->elevator == 1)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr,
				p->tex[91].img_ptr, 750, 200);
	if (p->elevator == 2)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr,
				p->tex[103].img_ptr, 750, 200);
	if (p->elevator == 3)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr,
				p->tex[104].img_ptr, 750, 200);
	if (p->elevator == 4)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr,
				p->tex[105].img_ptr, 750, 200);
	if (p->elevator == 5)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr,
				p->tex[106].img_ptr, 750, 200);
}

static void	call_function_draw(t_struct *p)
{
	int nb;

	order_sprite(p);
	raysprite(p, 0.0, -1, 0.0);
	if (p->maap == 1)
		minimap(p);
	weapon(p);
	mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->img_ptr2, 340, 0);
	mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->img_ptr3, 0, 653);
	if (p->elevator != 0 && (int)p->c->p_x == 7 && (int)p->c->p_y == 7)
		elevathor(p);
	if (p->k == 7 && p->c->shadow <= 1)
	{
		nb = (rand() % 2);
		if (nb == 1)
			p->h += 8;
		else if (nb == 0)
			p->h -= 8;
		p->c->shadow += 0.0025;
	}
}

void		raycasting(t_struct *p, int x, int z)
{
	ft_bzero(p->img_str, WMHM4);
	ft_bzero(p->img_str2, WH4);
	z = WIDTHMINUSONE;
	while (x < WIDTH)
	{
		p->hit = 0;
		p->c->camera_x = (2.0 * x / (double)WIDTH) - 1.0;
		p->c->r_dir_x = p->c->dir_x + p->c->plane_x * p->c->camera_x;
		p->c->r_dir_y = p->c->dir_y + p->c->plane_y * p->c->camera_x;
		walls_sides(p, x);
		draw_wall_3d(p, z - x, 0, 0);
		if (p->hit == 2 || p->hit == 3)
		{
			walls_sides(p, x);
			draw_transparent_wall(p, z - x, 0, 0);
		}
		p->zbuff[z - x] = p->c->wall_dist;
		x++;
	}
	call_function_draw(p);
}
