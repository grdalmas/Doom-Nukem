/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 22:42:14 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/02 10:35:25 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void		raycasting2(t_struct *p)
{
	order_sprite(p);
	raysprite(p, 0.0, -1, 0.0);
	if (p->maap == 1)
	{
		minimap(p);
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->img_ptr, 35, 35);
	}
	weapon(p);
	mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->img_ptr2, 340, 0);
	mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->img_ptr3, 0, 653);
}

void		raycasting3(t_struct *p)
{
	if (p->elevator != 0)
	{
		if ((int)p->c->p_x == 7 && (int)p->c->p_y == 7)
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
	}
}

void		raycasting4(t_struct *p)
{
	int		nb;

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

void		raycasting_while(t_struct *p, int x)
{
	p->hit = 0;
	p->c->camera_x = (2.0 * x / (double)WIDTH) - 1.0;
	p->c->r_pos_x = p->c->p_x;
	p->c->r_pos_y = p->c->p_y;
	p->c->r_dir_x = p->c->dir_x + p->c->plane_x * p->c->camera_x;
	p->c->r_dir_y = p->c->dir_y + p->c->plane_y * p->c->camera_x;
}

void		raycasting(t_struct *p, int x, int z)
{
	ft_bzero(p->img_str, (WIDTHMAP) * (HEIGHTMAP) * 4);
	ft_bzero(p->img_str2, WIDTH * HEIGHT * 4);
	z = WIDTH - 1;
	while (x < WIDTH)
	{
		raycasting_while(p, x);
		walls_sides(p, x);
		draw_wall_3d(p, z - x, 0, 0);
		if (p->hit == 2 || p->hit == 3)
		{
			walls_sides(p, x);
			draw_transparent_wall(p, z - x, 0, 0);
		}
		p->zbuff[z - x] = p->c->wall_dist;
		if (x == WIDTH / 2)
		{
			p->c->middle_wall_dist = p->c->wall_dist;
			//			printf("wall dist : %f\n", p->c->wall_dist);
		}
		x++;
	}
	raycasting2(p);
	raycasting3(p);
	raycasting4(p);
}
