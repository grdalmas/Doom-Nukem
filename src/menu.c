/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <tifuret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 06:18:36 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/07 20:58:55 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		mouse_motion_menu2(t_struct *p)
{
	if (p->ch == 0)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[122].img_ptr, 0, 0);
	if (p->ch == 1)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[123].img_ptr, 0, 0);
	if (p->ch == 2)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[124].img_ptr, 0, 0);
	if (p->ch == 3)
		mlx_put_image_to_window(p->mlx_ptr,
				p->w_ptr, p->tex[125].img_ptr, 0, 0);
}

static void		menu_sound(t_struct *p, int s)
{
	if (p->ch != 0)
	{
		if (s == 1)
			system("afplay ./doomzik/shotgun_pump.mp3 &");
		if (s == 2)
			system("afplay ./doomzik/elevator_button.mp3 &");
		if (s == 3)
			system("afplay ./doomzik/pain_1.mp3 &");
	}
}

int				mouse_motion_menu(int x, int y, t_struct *p, int s)
{
	if (p->choice == 0)
	{
		if (x >= 635 && x <= 990 && y >= 515 && y <= 605)
		{
			s = (p->ch == 1) ? 0 : 1;
			p->ch = 1;
		}
		else if (x >= 630 && x <= 990 && y >= 730 && y <= 800)
		{
			s = (p->ch == 2) ? 0 : 2;
			p->ch = 2;
		}
		else if (x >= 720 && x <= 900 && y >= 822 && y <= 883)
		{
			s = (p->ch == 3) ? 0 : 3;
			p->ch = 3;
		}
		else
			p->ch = 0;
		mouse_motion_menu2(p);
		if (p->sound == 1)
			menu_sound(p, s);
	}
	return (1);
}

static	void	start_game(t_struct *p)
{
	if (p->sound == 1)
	{
		p->ch = 0;
		system("afplay ./doomzik/shotgun_shot.mp3 &");
		system("afplay ./doomzik/amblobby.mp3 &");
	}
	p->choice = 1;
	mlx_clear_window(p->mlx_ptr, p->w_ptr);
	mlx_put_image_to_window(p->mlx_ptr,
			p->w_ptr, p->tex[45].img_ptr, 0, 35);
	mlx_put_image_to_window(p->mlx_ptr,
			p->w_ptr, p->tex[138].img_ptr, 35, 310);
	p->menu = 1;
}

int				mouse_release_menu(int b, int x, int y, t_struct *p)
{
	if (p->choice == 0)
	{
		if ((b == 1) && x >= 635 && x <= 990 && y >= 515 && y <= 605)
			start_game(p);
		else if ((b == 1) && x >= 630 && x <= 990 && y >= 730 && y <= 800)
		{
			p->ch = 0;
			p->choice = 2;
			mouse_release_settings(b, x, y, p);
			mouse_motion_settings(x, y, p);
		}
		else if ((b == 1) && x >= 720 && x <= 900 && y >= 822 && y <= 883)
			close_window(p);
		else
			mlx_put_image_to_window(p->mlx_ptr,
					p->w_ptr, p->tex[122].img_ptr, 0, 0);
	}
	return (1);
}
