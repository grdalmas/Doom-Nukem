/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trump.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:42:01 by bbataini          #+#    #+#             */
/*   Updated: 2019/03/04 17:35:20 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void			rotrump2(t_struct *p)
{
	if (p->trump != 6)
	{
		if (p->sprite[18].x > p->c->p_x && p->sprite[18].y > p->c->p_y)
			p->sprite[18].id = 14;
		else if (p->sprite[18].x < p->c->p_x && p->sprite[18].y < p->c->p_y)
			p->sprite[18].id = 17;
		else if (p->sprite[18].x > p->c->p_x && p->sprite[18].y < p->c->p_y)
			p->sprite[18].id = 16;
		else if (p->sprite[18].x < p->c->p_x && p->sprite[18].y > p->c->p_y)
			p->sprite[18].id = 15;
	}
	if (p->cure == 0)
		p->life -= 4;
}

void			rotrump(t_struct *p)
{
	if (p->sprite[17].x > p->c->p_x && p->sprite[17].y > p->c->p_y)
		p->sprite[17].id = 14;
	else if (p->sprite[17].x < p->c->p_x && p->sprite[17].y < p->c->p_y)
		p->sprite[17].id = 17;
	else if (p->sprite[17].x > p->c->p_x && p->sprite[17].y < p->c->p_y)
		p->sprite[17].id = 16;
	else if (p->sprite[17].x < p->c->p_x && p->sprite[17].y > p->c->p_y)
		p->sprite[17].id = 15;
}

void		trump(t_struct *p)
{
	if (p->trumplive == 1)
	{
		if (p->trump == 1)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[19].img_ptr,
				475, 490);
		else if (p->trump == 2)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[20].img_ptr,
				475, 490);
		else if (p->trump == 3)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[118].img_ptr,
				475, 490);
		else if (p->trump == 4)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[44].img_ptr,
				475, 490);
		else if (p->trump == 5)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[48].img_ptr,
				475, 490);
		else if (p->trump == 6)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[49].img_ptr,
				475, 490);
		if (p->tool == 1)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[0].img_ptr,
				1400, -100);
	}
}
