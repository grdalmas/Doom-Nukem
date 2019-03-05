/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 01:01:59 by bbataini          #+#    #+#             */
/*   Updated: 2019/03/05 01:49:55 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void			elevator(t_struct *p)
{
	if (p->keypress[KEY_1] == 1 || p->keypress[KEY_2] == 1
			|| p->keypress[KEY_3] == 1 || p->keypress[KEY_4] == 1
			|| p->keypress[KEY_5] == 1 || p->keypress[KEY_PAD_1] == 1
			|| p->keypress[KEY_PAD_2] == 1 || p->keypress[KEY_PAD_3] == 1
			|| p->keypress[KEY_PAD_4] == 1 || p->keypress[KEY_PAD_5] == 1)
	{
		if (p->sound == 1)
			system("afplay ./doomzik/elevator_beep.mp3 &");
		if (p->k == 7)
			p->h = 0;
		if (p->keypress[KEY_1] == 1 || p->keypress[KEY_PAD_1] == 1)
			p->k = 7;
		else if (p->keypress[KEY_2] == 1 || p->keypress[KEY_PAD_2] == 1)
			p->k = 0;
		else if (p->keypress[KEY_3] == 1 || p->keypress[KEY_PAD_3] == 1)
			p->k = 5;
		else if (p->keypress[KEY_4] == 1 || p->keypress[KEY_PAD_4] == 1)
			p->k = 8;
		else if (p->keypress[KEY_5] == 1 || p->keypress[KEY_PAD_5] == 1)
		{
			if (p->sprite[17].k == 6)
				p->sprite[18].k = 6;
			p->k = 9;
		}
		p->elevator = 0;
		p->c->p_x = 6.5;
		p->c->p_y = 7.5;
		p->c->dir_x = -1;
		p->c->dir_y = 0;
		p->c->plane_x = 0;
		p->c->plane_y = 1;
		p->porte[0].open = 0;
		p->porte[0].poort = 1;
	}
}

void			rotation(t_struct *p, int mod)
{
	double tmp_dir_x;
	double tmp_plane_x;

	if (mod == 0)
		p->c->rotation_speed = 0.1;
	if (mod == 1)
		p->c->rotation_speed = -0.1;
	tmp_dir_x = p->c->dir_x;
	p->c->dir_x = tmp_dir_x * cos(-p->c->rotation_speed) -
		p->c->dir_y * sin(-p->c->rotation_speed);
	p->c->dir_y = tmp_dir_x * sin(-p->c->rotation_speed) +
		p->c->dir_y * cos(-p->c->rotation_speed);
	tmp_plane_x = p->c->plane_x;
	p->c->plane_x = tmp_plane_x * cos(-p->c->rotation_speed) -
		p->c->plane_y * sin(-p->c->rotation_speed);
	p->c->plane_y = tmp_plane_x * sin(-p->c->rotation_speed) +
		p->c->plane_y * cos(-p->c->rotation_speed);
}

static void		move_up3(t_struct *p, int move)
{
	if (move == 68 || move == 66)
	{
		if (p->k == 0 && move == 68)
			move_tim(p, move);
		else if (p->k == 0 && move == 66)
			move_greg(p, move);
		else
		{
			p->k = 0;
			p->c->p_x = ((int)p->c->p_x == 13) ? 1.5 : 13.5;
			system("killall afplay");
		}
	}
	else if (move == 24 && p->k == 2)
	{
		p->c->p_y -= 3;
	}
	else if (move == 21)
		close_window(p);
}

static void		move_up2(t_struct *p, int move)
{
	if (move == 13)
	{
		system("killall afplay");
		system("afplay ./doomzik/lego.mp3 &");
		if (p->k == 2)
		{
			system("killall afplay");
			system("afplay ./doomzik/amblobby.mp3 &");
		}
		p->c->p_y = (p->k == 0) ? 13.5 : 1.5;
		p->k = (p->k == 0) ? 2 : 0;
	}
	else if (move == 12)
	{
		system("killall afplay");
		system("afplay ./doomzik/ambbobo.mp3 &");
		if (p->k == 1)
		{
			system("killall afplay");
			system("afplay ./doomzik/amblobby.mp3 &");
		}
		p->c->p_y = (p->k == 0) ? 1.5 : 13.5;
		p->k = (p->k == 0) ? 1 : 0;
	}
	move_up3(p, move);
}
void			move_up(t_struct *p, int move, int i, double s)
{
	int t;
	int tmp;

	t = 0;
	tmp = 0;
	while (t < NUMPORTE)
	{
		if (p->porte[t].zip == move)
			break ;
		t++;
	}
	if ((int)p->c->p_x == 7 && (int)p->c->p_y == 7
			&& p->k != 1 && p->k != 2 && p->k != 3 && p->k != 4)
	{
		if (p->k == 0)
			p->elevator = 2;
		if (p->k == 5)
			p->elevator = 3;
		if (p->k == 7)
			p->elevator = 1;
		if (p->k == 8)
			p->elevator = 4;
		if (p->k == 9)
			p->elevator = 5;
		elevator(p);
	}
	if (p->k == 4)
	{
		if (move == 0 && (p->keypress[KEY_A] == 1 || p->keypress[KEY_D] == 1))
			move = against_glitch_straff(p, move, s);
		else
			move = against_glitch(p, move, s);
	}
	if (move == 0 && (p->keypress[KEY_A] == 1 || p->keypress[KEY_D] == 1))
	{
		while (i < 5)
		{
			if (p->map[p->k][(int)((p->c->p_x + p->c->plane_x * i * s / 4))]
					[(int)((p->c->p_y + p->c->plane_y * i * s / 4))] == 1)
				break ;
			if (++i == 5)
			{
				p->c->p_x += p->c->plane_x * s;
				p->c->p_y += p->c->plane_y * s;
			}
		}
	}
	if (move == 0 || (t < NUMPORTE && p->porte[t].open >= 0.6))
	{
		while (i < 5)
		{
			if (p->map[p->k][(int)((p->c->p_x + p->c->dir_x * i * s / 4))]
					[(int)((p->c->p_y + p->c->dir_y * i * s / 4))] == 1)
				break ;
			if (++i == 5)
			{
				p->c->p_x += p->c->dir_x * s;
				p->c->p_y += p->c->dir_y * s;
			}
		}
	}
	else if (move == 12 || move == 13 || move == 68 || move == 66 || move == 24)
	{
		move_up2(p, move);
		if (p->sound == 1 && move != 24)
			system("afplay ./doomzik/tp.mp3 &");
		else
			system("killall afplay");
	}
}
