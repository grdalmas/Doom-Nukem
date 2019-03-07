/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 02:06:49 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/07 20:40:14 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static void			rotation(t_struct *p, int mod)
{
	double tmp_dir_x;
	double tmp_plane_x;

	if (mod == 0)
		p->c->rotation_speed = 0.1;
	if (mod == 1)
		p->c->rotation_speed = -0.1;
	tmp_dir_x = p->c->dir_x;
	p->c->dir_x = tmp_dir_x * cos(-p->c->rotation_speed)
		- p->c->dir_y * sin(-p->c->rotation_speed);
	p->c->dir_y = tmp_dir_x * sin(-p->c->rotation_speed)
		+ p->c->dir_y * cos(-p->c->rotation_speed);
	tmp_plane_x = p->c->plane_x;
	p->c->plane_x = tmp_plane_x * cos(-p->c->rotation_speed)
		- p->c->plane_y * sin(-p->c->rotation_speed);
	p->c->plane_y = tmp_plane_x * sin(-p->c->rotation_speed)
		+ p->c->plane_y * cos(-p->c->rotation_speed);
}

static void			soundstep(t_struct *p)
{
	if (p->c->pas == p->pas && (p->c->pas = 1) == 1)
		system("afplay ./doomzik/pas1.mp3 &");
	else if (p->c->pas == p->pas + 1 && (p->c->pas = 2) == 2)
		system("afplay ./doomzik/pas2.mp3 &");
	else if (p->c->pas == p->pas + 2 && (p->c->pas = 3) == 3)
		system("afplay ./doomzik/pas3.mp3 &");
	else if (p->c->pas == p->pas + 3 && (p->c->pas = 4) == 4)
		system("afplay ./doomzik/pas4.mp3 &");
	else if (p->c->pas == p->pas + 4 && (p->c->pas = 5) == 5)
		system("afplay ./doomzik/pas5.mp3 &");
	else if (p->c->pas == p->pas + 5 && (p->c->pas = 6) == 6)
		system("afplay ./doomzik/pas6.mp3 &");
	else if (p->c->pas >= p->pas + 6 && (p->c->pas = 0) == 0)
		system("afplay ./doomzik/pas7.mp3 &");
}

static void			key_press_hook2(t_struct *p)
{
	if (p->keypress[KEY_ESCAPE] == 1)
		close_window(p);
	if (p->keypress[KEY_LEFT] == 1)
		rotation(p, 0);
	if (p->keypress[KEY_RIGHT] == 1)
		rotation(p, 1);
	if (p->keypress[KEY_SHIFT] == 1)
	{
		p->sprint = 0.3;
		p->c->pas += 7;
		p->pas = 21;
	}
	else if (p->keypress[KEY_A] == 1 || p->keypress[KEY_D] == 1
			|| p->keypress[KEY_W] == 1 || p->keypress[KEY_S] == 1)
	{
		p->sprint = 0.2;
		p->pas = 35;
		p->c->pas += 7;
	}
}

int					key_press_hook(t_struct *p)
{
	double	s;
	int		key;

	key = 1;
	key_press_hook2(p);
	if (p->keypress[KEY_W] == 1 || p->keypress[KEY_S] == 1)
	{
		s = (p->keypress[KEY_W] ? p->sprint : -p->sprint);
		key = p->map[p->k][(int)((p->c->p_x + p->c->dir_x * s))]
			[(int)((p->c->p_y + p->c->dir_y * s))];
	}
	if (p->keypress[KEY_A] == 1 || p->keypress[KEY_D] == 1)
	{
		s = (p->keypress[KEY_A] ? p->sprint : -p->sprint);
		key = p->map[p->k][(int)((p->c->p_x + p->c->plane_x * s))]
			[(int)((p->c->p_y + p->c->plane_y * s))];
	}
	if (key == 0 && p->sound == 1)
		soundstep(p);
	move_up(p, key, 0, s);
	return (0);
}
