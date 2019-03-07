/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <tifuret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 22:42:14 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/07 20:40:33 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static void		wall_dist(t_struct *p)
{
	if (p->c->side == 0)
	{
		p->c->wall_dist = fabs((p->c->map_x - p->c->p_x
					+ (1.0 - p->c->step_x) / 2.0) / p->c->r_dir_x);
		p->c->offset = p->c->p_y + ((p->c->map_x
					- p->c->p_x + (1 - p->c->step_x) / 2)
				/ p->c->r_dir_x) * p->c->r_dir_y;
	}
	else
	{
		p->c->wall_dist = fabs((p->c->map_y - p->c->p_y
					+ (1.0 - p->c->step_y) / 2.0) / p->c->r_dir_y);
		p->c->offset = p->c->p_x + ((p->c->map_y - p->c->p_y
					+ (1 - p->c->step_y) / 2)
				/ p->c->r_dir_y) * p->c->r_dir_x;
	}
	p->c->offset -= floor(p->c->offset);
}

static void		shoothit(t_struct *p, int i)
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

static void		sadside(t_struct *p)
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

static void		hit_walls(t_struct *p, int x, int hit, int i)
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

void			walls_sides(t_struct *p, int x)
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
