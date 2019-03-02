/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 05:55:11 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/02 06:44:55 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static void			mouse_motion_settings_sound_off(t_struct *p)
{
	if (p->ch == 0)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[127].img_ptr, 0, 0);
	else if (p->ch == 1)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[129].img_ptr, 0, 0);
	else if (p->ch == 2)
	{
		write(1, "1\n", 2);
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[130].img_ptr, 0, 0);
	}
	else if (p->ch == 3)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[128].img_ptr, 0, 0);
}

static void			mouse_motion_settings_sound_on(t_struct *p)
{
	if (p->ch == 0)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[126].img_ptr, 0, 0);
	else if (p->ch == 1)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[132].img_ptr, 0, 0);
	else if (p->ch == 2)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[133].img_ptr, 0, 0);
	else if (p->ch == 3)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[131].img_ptr, 0, 0);
}

int					mouse_motion_settings(int x, int y, t_struct *p)
{
	y = y + 30;
	if (p->choice == 2)
	{
		if ((x >= 600 && x <= 1025 && y >= 562 && y <= 610)
				|| (x >= 790 && x <= 900 && y >= 835 && y <= 930)
				|| (x >= 1105 && x <= 1320 && y >= 895 && y <= 930))
		{
			if (p->ch != 1 && p->ch != 2 && p->ch != 3 && p->sound == 1)
				system("afplay ./doomzik/elevator_button.mp3 &");
			if (x >= 600 && x <= 1025 && y >= 562 && y <= 610)
				p->ch = 1;
			else if (x >= 790 && x <= 900 && y >= 835 && y <= 930)
				p->ch = 2;
			else if (x >= 1105 && x <= 1320 && y >= 895 && y <= 930)
				p->ch = 3;
		}
		else
			p->ch = 0;
		if (p->sound == 1)
			mouse_motion_settings_sound_on(p);
		else
			mouse_motion_settings_sound_off(p);
	}
	return (1);
}

int					mouse_release_settings(int b, int x, int y, t_struct *p)
{
	y = y + 30;
	if (p->choice == 2)
	{
		if ((b == 1) && x >= 600 && x <= 1025 && y >= 562 && y <= 610)
			p->choice = 3;
		else if ((b == 1) && x >= 790 && x <= 900 && y >= 835 && y <= 920)
			p->sound = (p->sound == 1) ? 0 : 1;
		else if ((b == 1) && x >= 1105 && x <= 1320 && y >= 895 && y <= 930)
			p->choice = 0;
		else
		{
			if (p->sound == 1)
				mlx_put_image_to_window(p->mlx_ptr,
						p->w_ptr, p->tex[126].img_ptr, 0, 0);
			else if (p->sound == 0)
				mlx_put_image_to_window(p->mlx_ptr,
						p->w_ptr, p->tex[127].img_ptr, 0, 0);
		}
		mouse_release_diff(b, x, y, p);
		mouse_release_menu(b, x, y, p);
	}
	return (1);
}
