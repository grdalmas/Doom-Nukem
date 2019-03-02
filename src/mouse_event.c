/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 07:48:53 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/02 08:20:53 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"


static void			mouse_motion2(int x, int y, t_struct *p)
{
	double	tmp_dir_x;
	double	tmp_plane_x;
	float	difx;
	float	dify;

	difx = p->ox - x;
	dify = p->oy - y;
	difx = difx / 180;
	p->c->rotation_speed = difx;
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
	p->h += dify;
	p->ox = x;
	p->oy = y;
}

int				mouse_motion(int x, int y, t_struct *p)
{
	if (p->menu == 3)
	{
		p->mousex = x;
		p->mousey = y;
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
	else if (p->menu == 1)
		mouse_motion2(x, y, p);
	return (0);
}

int				mouse_button(int button, int x, int y, t_struct *p)
{
	if (p->menu == 3)
		mouse_creator_map(p, button, x, y);
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
