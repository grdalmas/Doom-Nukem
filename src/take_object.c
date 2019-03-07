/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 09:39:04 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/07 21:25:19 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static void		take_object4(t_struct *p)
{
	if (p->trump == 1)
		p->trump = 0;
	else if (p->trump == 2)
		p->trump = 0;
	else if (p->trump == 3)
		p->trump = 0;
	else if (p->trump == 6)
		p->trump = 7;
	else if (p->trump == 4)
		p->trump = 0;
	else if (p->trump == 5)
		p->trump = 0;
	else if (p->k == 9 && p->sprited[18] <= 1.5 && p->trump != 6
			&& p->trump != 7)
	{
		if (p->sound == 1)
			system("afplay ./doomzik/trump_message_music.mp3 & 2>&1");
		p->sprite[18].id = 14;
		p->trump = 6;
	}
}

static void		take_object3(t_struct *p)
{
	if (p->sprited[19] <= 1.5 && p->trump != 4 && p->sprite[19].k != 6)
	{
		if (p->sound == 1)
			system("afplay ./doomzik/trump_message_pop.mp3 & 2>&1");
		p->trump = 4;
		p->sprite[19].k = 6;
		p->weapon.id = 2;
	}
	else if (p->k == 8 && (int)p->sprited[1] == 0)
	{
		if (p->sound == 1)
		{
			system("afplay ./doomzik/trump_message_pop.mp3 & 2>&1");
			system("afplay ./doomzik/zip.mp3 & 2>&1");
		}
		p->trump = 5;
		p->sprite[1].k = 6;
		p->cure = 1;
		p->life += 50;
		if (p->life > 100)
			p->life = 100;
	}
	else
		take_object4(p);
}

static void		take_object2(t_struct *p)
{
	if (p->k == 2 && p->sprited[0] <= 1.5 && p->trump != 2
			&& p->sprite[0].k != 6)
	{
		if (p->sound == 1)
		{
			system("afplay ./doomzik/trump_message_pop.mp3 & 2>&1");
			system("afplay ./doomzik/zip.mp3 & 2>&1");
		}
		p->tool = 1;
		p->trump = 2;
		p->sprite[0].k = 6;
	}
	else if (p->k == 1 && p->sprited[3] <= 1.5)
	{
		if (p->sound == 1)
			system("afplay ./doomzik/zip.mp3 & 2>&1");
		p->maap = 1;
		p->sprite[3].k = 6;
	}
	else
		take_object3(p);
}

void			take_object(t_struct *p)
{
	if (p->sprited[2] <= 1.5 && p->menu != -1)
	{
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->img_ptr2, 340, 0);
		p->menu = 3;
		inverse_map(p, 0, 0, 0);
	}
	else if (p->sprited[17] <= 1.5 && p->menu != -1 && p->sound == 1)
		system("afplay ./doomzik/mmpf.mp3 & 2>&1");
	else if (p->menu == -1)
	{
		inverse_map(p, 0, 0, 0);
		p->menu = 1;
	}
	else if (p->sprited[16] <= 1.5 && p->trump != 3 && p->sprite[16].k != 6)
	{
		p->trump = 3;
		p->sprite[16].k = 6;
		p->weapon.id = 1;
		if (p->sound == 1)
			system("afplay ./doomzik/chainsaw_start.mp3 & 2>&1");
	}
	else
		take_object2(p);
}
