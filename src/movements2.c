/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <tifuret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:17:50 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/07 21:42:18 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		elevator2(t_struct *p)
{
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

void			elevator(t_struct *p)
{
	p->elevator = (p->k == 0) ? 2 : p->elevator;
	p->elevator = (p->k == 5) ? 3 : p->elevator;
	p->elevator = (p->k == 7) ? 1 : p->elevator;
	p->elevator = (p->k == 8) ? 4 : p->elevator;
	p->elevator = (p->k == 9) ? 5 : p->elevator;
	if (p->keypress[KEY_1] == 1 || p->keypress[KEY_2] == 1
			|| p->keypress[KEY_3] == 1 || p->keypress[KEY_4] == 1
			|| p->keypress[KEY_5] == 1 || p->keypress[KEY_PAD_1] == 1
			|| p->keypress[KEY_PAD_2] == 1 || p->keypress[KEY_PAD_3] == 1
			|| p->keypress[KEY_PAD_4] == 1 || p->keypress[KEY_PAD_5] == 1)
	{
		if (p->sound == 1)
			system("afplay ./doomzik/elevator_beep.mp3 & 2>&1");
		p->h = (p->k == 7) ? 0 : p->h;
		elevator2(p);
	}
}

static void		move_up3(t_struct *p, int move)
{
	if (move == 68 || move == 66)
	{
		system("killall afplay");
		if (p->k == 0 && move == 68)
		{
			system("afplay ./doomzik/vivaldi_spring.mp3 & 2>&1");
			p->c->p_x = 1.5;
			p->k = 3;
		}
		else if (p->k == 0 && move == 66)
		{
			system("afplay ./doomzik/Doom_1.mp3 & 2>&1");
			p->c->p_x = 13.5;
			p->k = 4;
		}
		else
		{
			p->k = 0;
			p->c->p_x = ((int)p->c->p_x == 13) ? 1.5 : 13.5;
			system("afplay ./doomzik/amblobby.mp3 & 2>&1");
		}
	}
	else if (move == 24 && p->k == 2)
		p->c->p_y -= 3;
}

void			move_up2(t_struct *p, int move)
{
	if (move == 13)
	{
		system("killall afplay");
		system("afplay ./doomzik/lego.mp3 & 2>&1");
		if (p->k == 2)
		{
			system("killall afplay");
			system("afplay ./doomzik/amblobby.mp3 & 2>&1");
		}
		p->c->p_y = (p->k == 0) ? 13.5 : 1.5;
		p->k = (p->k == 0) ? 2 : 0;
	}
	else if (move == 12)
	{
		system("killall afplay");
		system("afplay ./doomzik/ambbobo.mp3 & 2>&1");
		if (p->k == 1)
		{
			system("killall afplay");
			system("afplay ./doomzik/amblobby.mp3 & 2>&1");
		}
		p->c->p_y = (p->k == 0) ? 1.5 : 13.5;
		p->k = (p->k == 0) ? 1 : 0;
	}
	move_up3(p, move);
}
