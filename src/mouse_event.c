/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:12:06 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/02 07:16:56 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"


int			rotation2(int x, int y, t_struct *p)
{

	if (p->menu == 1)
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
	else if (p->menu == 3)
	{
		p->mousex = x;
		p->mousey = y;
		//			printf("//%i %i//", x, y);

	}
	else if (p->menu == 4)
	{
		if (p->choice == 0)
		mouse_motion_menu(x, y, p, 0);
		else if (p->choice == 2)
			mouse_motion_settings(x, y, p);
		else if (p->choice == 3)
			mouse_motion_diff(x, y, p);
	}
	return (0);
}


int				mouse_button(int button, int x, int y, t_struct *p)
{
	printf("je susi ds mouse button\n");
	if (p->menu == 3)
	{
	printf("je\n");
		{
			if (button == 2)
			{
				p->edit = 0;
				p->edits = -1;
			}

			else if (x > 1183 && x < 1183 + 76 && y > 135 && y < 135 + 76)
				p->edit = 8;
			else if (x > 1280 && x < 1280 + 76  && y > 130 && y < 214)
				p->edit = 9;
			else if (x > 1383 && x < 1383 + 76 && y > 135 && y < 135 + 76)
				p->edit = 10;
			else if (x > 1493 && x < 1496 + 76 && y > 140 && y < 214)
				p->edit = 11;
			else if (x > 1183 && x < 1183 + 76 && y > 247 && y < 247 + 76)
				p->edit = 23;
			else if (x > 1280 && x < 1357 && y > 240 && y < 240 + 76)
				p->edit = 7;
			else if (x > 1380 && x < 1457 && y > 240 && y < 240 + 76)
				p->edit = 4;
			else if (x > 1480 && x < 1557 && y > 240 && y < 240 + 76)
				p->edit = 121;

			if (p->edit != 0)
				p->edits = -1;

			/////////////// SPRITE ////////////////
			if (x > 1190 && x < 1250 && y > 444 && y < 512)
				p->edits = 20;
			else if (x > 1290 && x < 1350 && y > 444 && y < 512)
				p->edits = 21;
			else if (x > 1390 && x < 1450 && y > 444 && y < 512)
				p->edits = 22;
			else if (x > 1490 && x < 1550 && y > 444 && y < 512)
				p->edits = 23;

			if (p->edits > 19)
				p->edit = 0;

			//		printf("b : %i \n", button);

//			printf("y : %i \n", y);
//			printf("x good : %i \n", x);
//			printf("y good : %i \n", y);

			if (x > 1357 && x < 1396 && y > 600 && 638 > y)
			{
				if (p->edit > 0 && p->edit != 121)
					p->floor = p->edit;
				else
					p->floor = 7;
			}

			x = (x - 496) / 40;
			y = (y - 37) / 40;

			if (x >= 0 && x <= 14 && y >= 0 && y <= 14 && p->edit == 0)
			{
				if (p->edits > 19)
				{
					if (p->map[4][y][x] == 0)
					{
						p->sprite[p->edits].k = 4;
						p->sprite[p->edits].y = (int)x + 0.5;
						p->sprite[p->edits].x = (int)y + 0.5;
					}
				}
			}

			int i;
			if (x >= 0 && x <= 14 && y >= 0 && y <= 14 && p->edit != 0)
			{
				if (p->edit == 121)
				{
					if (x != 0 && x != 14 && y != 0 && y != 14)
						p->map[4][y][x] = 0;
				}
				else
				{
					i = 20;
					while (i < 24)
					{
						if (p->sprite[i].x == y && p->sprite[i].y == x)
							break ;
						i++;
					}
					if (i == 24)
					{
						if (x == 7)
						{
							if (y == 13 || y == 14)
								i = 100;
						}
						if (i != 100)
							p->map[4][y][x] = p->edit;
					}
				}
			}
//			printf("x good : %i \n", x);
//			printf("y good : %i \n", y);
//			printf("x sprite : %d\n", (int)p->sprite[20].y);
//			printf("y sprite : %d\n", (int)p->sprite[20].x);
		}
	}
	else if (p->menu == 4)
	{
		if (p->choice == 0)
		mouse_release_menu(button, x, y, p);
		else if (p->choice == 2)
			mouse_release_settings(button, x, y, p);
		else if (p->choice == 3)
			mouse_release_diff(button, x, y, p);
	}
		return (0);
}
