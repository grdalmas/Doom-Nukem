/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:12:06 by grdalmas          #+#    #+#             */
/*   Updated: 2019/02/27 04:07:25 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"


int			rotation2(int x, int y, t_struct *p)
{
	if (p->menu == 3)
	{
			printf("%i", x);
		if (p->edit != 0)
			img_to_img(p, x, y, p->edit, 0.15625);
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
	//else if (p->ox <= x)
	//	p->c->rotation_speed = difx;
	tmp_dir_x = p->c->dir_x;
	p->c->dir_x = tmp_dir_x * cos(-p->c->rotation_speed) - p->c->dir_y *
		 sin(-p->c->rotation_speed);
	p->c->dir_y = tmp_dir_x * sin(-p->c->rotation_speed) + p->c->dir_y *
		 cos(-p->c->rotation_speed);
	tmp_plane_x = p->c->plane_x;
	p->c->plane_x = tmp_plane_x * cos(-p->c->rotation_speed) - p->c->plane_y *
		 sin(-p->c->rotation_speed);
	p->c->plane_y = tmp_plane_x * sin(-p->c->rotation_speed) + p->c->plane_y *
		 cos(-p->c->rotation_speed);

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
