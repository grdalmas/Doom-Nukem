/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <tifuret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 01:01:59 by bbataini          #+#    #+#             */
/*   Updated: 2019/03/07 20:59:13 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		straff(t_struct *p, double s)
{
	int i;

	i = 0;
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

static void		straight_on(t_struct *p, double s)
{
	int i;

	i = 0;
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

static void		rooms(t_struct *p, int move, int t, double s)
{
	if (move == 0 && (p->keypress[KEY_A] == 1 || p->keypress[KEY_D] == 1))
		straff(p, s);
	else if (move == 0 || (t < NUMPORTE && p->porte[t].open >= 0.6))
		straight_on(p, s);
	else if (move == 12 || move == 13 || move == 68 || move == 66 || move == 24)
	{
		move_up2(p, move);
		if (p->sound == 1)
			system("afplay ./doomzik/tp.mp3 &");
		else
			system("killall afplay");
	}
}

void			move_up(t_struct *p, int move, int t, double s)
{
	int tmp;

	tmp = 0;
	while (t < NUMPORTE)
	{
		if (p->porte[t].zip == move)
			break ;
		t++;
	}
	if ((int)p->c->p_x == 7 && (int)p->c->p_y == 7
			&& p->k != 1 && p->k != 2 && p->k != 3 && p->k != 4)
		elevator(p);
	if (p->k == 4)
	{
		if (move == 0 && (p->keypress[KEY_A] == 1 || p->keypress[KEY_D] == 1))
			move = against_glitch_straff(p, move, s);
		else
			move = against_glitch(p, move, s);
	}
	rooms(p, move, t, s);
}
