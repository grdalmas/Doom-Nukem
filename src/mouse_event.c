/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:12:06 by grdalmas          #+#    #+#             */
/*   Updated: 2019/02/28 00:51:34 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"


int			rotation2(int x, int y, t_struct *p)
{
	if (p->menu == 3)
	{
		p->mousex = x;
		p->mousey = y;
			printf("//%i %i//", x, y);
		if (p->edit != 0)
			img_to_img(p, x - 340, y - 20, p->edit, 0.15625);
	}
	else
	{
	double tmp_dir_x;
	double tmp_plane_x;

	//(void)y;
	float difx;
	float dify;

	difx = p->ox - x;
	dify = p->oy - y;

	difx = difx  / 180;
//	dify = dify  ;
//	printf("%f ",(dif));
	//	if (p->ox >= x)
		p->c->rotation_speed = difx;
		if (p->k == 4)
			p->c->rotation_speed *= -1;
	//else if (p->ox <= x)
	//	p->c->rotation_speed = difx;
	tmp_dir_x = p->c->dir_x;
	p->c->dir_x = tmp_dir_x * cos(-p->c->rotation_speed) - p->c->dir_y
		* sin(-p->c->rotation_speed);
	p->c->dir_y = tmp_dir_x * sin(-p->c->rotation_speed) + p->c->dir_y
		* cos(-p->c->rotation_speed);
	tmp_plane_x = p->c->plane_x;
	p->c->plane_x = tmp_plane_x * cos(-p->c->rotation_speed) - p->c->plane_y
		* sin(-p->c->rotation_speed);
	p->c->plane_y = tmp_plane_x * sin(-p->c->rotation_speed) + p->c->plane_y
		* cos(-p->c->rotation_speed);

//	if (p->oy >= y)
//		p->h += dify;
//	if (p->oy <= y)
		p->h += dify;
	//printf("%i ", p->h);

	p->ox = x;
	p->oy = y;
	}
	return (0);
}


int				mouse_button(int button, int x, int y, t_struct *p)
{
	if (p->menu == 3)
	{
		if (button == 2)
			p->edit = 0;
		else if (x > 1183 && x < 1183 + 76 && y > 135 && y < 135 + 76)
			p->edit = 8;
		else if (x > 1280 && x < 1280 + 76  && y > 130 && y < 214)
		p->edit = 9;
		else if (x > 1383 && x < 1383 + 76 && y > 135 && y < 135 + 76)
			p->edit = 10;
		else if (x > 1493 && x < 1496 + 76 && y > 140 && y < 214)
		p->edit = 11;
		else if (x > 1183 && x < 1183 + 76 && y > 247 && y < 247 + 76)
			p->edit = 58;
			else if (x > 1280 && x < 1357 && y > 240 && y < 240 + 76)
		p->edit = 58;
			else if (x > 1380 && x < 1457 && y > 240 && y < 240 + 76)
		p->edit = 4;
		else if (x > 1480 && x < 1557 && y > 240 && y < 240 + 76)
		p->edit = 121;

		printf("b : %i \n", button);
		printf("x : %i \n", x);
		printf("y : %i \n", y);
		printf("x good : %i \n", (x - 496) / 40);
		printf("y good : %i \n", (y - 37) / 40);
		x = (x - 496) / 40;
		y = (y - 37) / 40;

		printf("p edit : %d\n", p->edit);
		if (x >= 0 && x <= 14 && y >= 0 && y <= 14)
		{
			if (p->edit == 121 || p->edit == 0)
			{
				if (x != 0 && x != 14 && y != 0 && y != 14)
					p->map[4][y][x] = 0;
			}
			else
				p->map[4][y][x] = p->edit;
		}
	}
	return (0);
}

