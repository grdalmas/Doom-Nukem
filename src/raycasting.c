/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 22:42:14 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/05 01:33:45 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

t_sprite	*init_sprite(void)
{
	static t_sprite sprite[NUMSPRITE] = {
		{2, 0, 7.5, 7.5, 1}, // tools
		{8, 1, 7.5, 9.5, 10}, // medikit
		{0, 51, 9.5, 2.5, 1000}, // computer
		{1, 3, 3, 3, 1}, //map
		{5, 82, 7.5, 2, 10},  // se raproche du player 4
		{5, 82, 1.5, 10.5, 10}, // se rapproche du player 5
		{5, 82, 3.5, 11.5, 10}, // se rapproche du player 6
		{5, 82, 7.5, 1.5, 10}, // se rapproche du player 7
		{5, 82, 9.5, 13.5, 10}, // se rapproche du player 8
		{5, 82, 7.5, 3.5, 10}, // se rapproche du player 9
		{8, 119, 2.5, 2.5, 10}, // mechant 10
		{8, 119, 4, 4, 10},
		{8, 119, 13, 13, 10},
		{8, 119, 13, 2.5, 10},
		{8, 119, 7.5, 2, 10},
		{8, 119, 7.5, 12.5, 10}, // mechant 15
		{7, 86, 4.5, 3.5, 1}, // tronconneuse 16 !
		{0, 14, 11, 11, 10}, //trump 17
		{9, 14, 7.5, 1.5, 10}, //trump 18
		{6, 95, 7.5, 2, 1}, // pompe 19
		{6, 51, 0, 0, 0},//editeur
		{6, 33, 0, 0, 0},
		{6, 46, 0, 0, 0},
		{6, 50, 0, 0, 0},//editeur
		{1, 33, 7.5, 7.5,1},// 22 statue
	};
	return (sprite);
}

void		wall_dist(t_struct *p)
{
	if (p->c->side == 0)
	{
		p->c->wall_dist = fabs((p->c->map_x - p->c->p_x +
					(1.0 - p->c->step_x) / 2.0) / p->c->r_dir_x);
		p->c->offset = p->c->p_y + ((p->c->map_x
					- p->c->p_x + (1 - p->c->step_x) / 2)
				/ p->c->r_dir_x) * p->c->r_dir_y;
	}
	else
	{
		p->c->wall_dist = fabs((p->c->map_y - p->c->p_y +
					(1.0 - p->c->step_y) / 2.0) / p->c->r_dir_y);
		p->c->offset = p->c->p_x + ((p->c->map_y - p->c->p_y
					+ (1 - p->c->step_y) / 2)
				/ p->c->r_dir_y) * p->c->r_dir_x;
	}
	p->c->offset -= floor(p->c->offset);
}

void		shoothit(t_struct *p, int i)
{
	while (i < NUMSPRITE)
	{
		if (p->k == p->sprite[i].k && p->c->map_x == (int)p->sprite[i].x
				&& p->c->map_y == (int)p->sprite[i].y)
		{
			p->sprite[i].pv -= 10;
			p->shoot = 0;
		}
		i++;
	}
}

void		sadside(t_struct *p)
{
	if (p->c->side_x < p->c->side_y)
	{
		p->c->side_x += p->c->delta_x;
		p->c->map_x += p->c->step_x;
		p->c->side = 0;
	}
	else
	{
		p->c->side_y += p->c->delta_y;
		p->c->map_y += p->c->step_y;
		p->c->side = 1;
	}
}

void		hit_walls(t_struct *p, int x, int hit, int i)
{
	while (hit == 0)
	{
		sadside(p);
		if (p->shoot == 1 && x == WIDTH / 2)
			shoothit(p, 0);
		if (p->map[p->k][p->c->map_x][p->c->map_y] > 0)
		{
			i = 0;
			if (p->map[p->k][p->c->map_x][p->c->map_y] == 6 && p->hit != 2)
				p->hit = 2;
			else if (p->map[p->k][p->c->map_x][p->c->map_y] == 5 && p->hit != 3)
				p->hit = 3;
			else
				hit = 1;
			p->shoot = (x == 640) ? 0 : p->shoot;
			wall_dist(p);
			while (i < NUMPORTE && p->porte[i].zip
					!= p->map[p->k][p->c->map_x][p->c->map_y])
				i++;
			if (p->c->offset < p->porte[i].open - 0.02)
				hit = 0;
		}
	}
	p->dodor = i;
	wall_dist(p);
}

void		walls_sides(t_struct *p, int x)
{
	p->c->map_x = (int)p->c->p_x;
	p->c->map_y = (int)p->c->p_y;
	p->c->delta_x = fabs(1 / p->c->r_dir_x);
	p->c->delta_y = fabs(1 / p->c->r_dir_y);
	p->c->step_y = 1;
	p->c->side_y = (p->c->map_y + 1.0 - p->c->p_y)
		* p->c->delta_y;
	if (p->c->r_dir_x < 0)
	{
		p->c->step_x = -1;
		p->c->side_x = (p->c->p_x - p->c->map_x) * p->c->delta_x;
	}
	else
	{
		p->c->step_x = 1;
		p->c->side_x = (p->c->map_x + 1.0 - p->c->p_x)
			* p->c->delta_x;
	}
	if (p->c->r_dir_y < 0)
	{
		p->c->step_y = -1;
		p->c->side_y = (p->c->p_y - p->c->map_y) * p->c->delta_y;
	}
	hit_walls(p, x, 0, 0);
}

static void		draw_transparent_wall2(t_struct *p, int x, int y, int wall_h)
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

void		draw_transparent_wall(t_struct *p, int x, int y, int wall_height)
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
	draw_transparent_wall2(p, x, y, wall_height);
	if (p->hit == 2)
		p->tid = 6;
	else if (p->hit == 3 && p->s == -1)
		p->tid = 5;
	else if (p->hit == 3 && p->s >= 0)
		p->tid = 18;
}

void		elevathor(t_struct *p)
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

void		call_function_draw(t_struct *p)
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
