/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difficulty_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <tifuret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 04:42:59 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/07 21:39:43 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		mouse_motion_diff2(t_struct *p)
{
	if (p->ch == 0)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[137].img_ptr, 0, 0);
	if (p->ch == 1)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[134].img_ptr, 0, 0);
	if (p->ch == 2)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[135].img_ptr, 0, 0);
	if (p->ch == 3)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[136].img_ptr, 0, 0);
}

int				mouse_motion_diff(int x, int y, t_struct *p)
{
	if (p->choice == 3)
	{
		if ((x >= 715 && x <= 905 && y >= 523 && y <= 585)
				|| (x >= 710 && x <= 910 && y >= 650 && y <= 700)
				|| (x >= 1105 && x <= 1320 && y >= 855 && y <= 900))
		{
			if (p->ch != 1 && p->ch != 2 && p->ch != 3 && p->sound == 1)
				system("afplay ./doomzik/elevator_button.mp3 & 2>&1");
			if (x >= 715 && x <= 905 && y >= 523 && y <= 585)
				p->ch = 1;
			else if (x >= 710 && x <= 910 && y >= 650 && y <= 700)
				p->ch = 2;
			else if (x >= 1105 && x <= 1320 && y >= 855 && y <= 900)
				p->ch = 3;
		}
		else
			p->ch = 0;
		mouse_motion_diff2(p);
	}
	return (1);
}

int				mouse_release_diff(int b, int x, int y, t_struct *p)
{
	if (p->choice == 3)
	{
		if ((b == 1) && x >= 715 && x <= 905 && y >= 523 && y <= 585)
			p->difficulty = 0;
		else if ((b == 1) && x >= 710 && x <= 910 && y >= 650 && y <= 704)
		{
			if (p->sound == 1)
				system("afplay ./doomzik/youshall.mp3 & 2>&1");
			p->difficulty = 1;
		}
		else if ((b == 1) && x >= 1105 && x <= 1320 && y >= 855 && y <= 900)
		{
			p->choice = 2;
			mouse_release_settings(b, x, y, p);
		}
		else
			mlx_put_image_to_window(p->mlx_ptr,
					p->w_ptr, p->tex[137].img_ptr, 0, 0);
	}
	return (1);
}
