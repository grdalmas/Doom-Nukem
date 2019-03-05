/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 02:44:09 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/05 02:49:58 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void		weapon3(t_struct *p)
{
	if (p->difficulty == 0)
		touch_by_enemy(p);
	else
		touch_by_enemyhard(p);
	if (p->weapon.id == 1)
		hit_enemy(p);
	if (p->weapon.id == 2)
		shoot(p);
	life_barre(p);
	trump(p);
}

void		weapon2(t_struct *p)
{
	if (p->temp == 1 && p->sound == 1)
		system("afplay ./doomzik/chainsaw_attack_middle.mp3 &");
	if (p->trons == 1)
	{
		p->trons = 0;
		if (p->sound == 1)
			system("afplay ./doomzik/chainsaw_attack_in.mp3 &");
	}
	soundtronco(p);
	p->soundtmp = p->temp;
	mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[88].img_ptr, 610, 583);
}

void		weapon(t_struct *p)
{
//	p->weapon.id = 1;
	if (p->weapon.id == 1)
	{
		if (p->temp == 1 && p->sound == 1)
			system("afplay ./doomzik/chainsaw_sustain.mp3 &");
		if (p->keypress[KEY_SPACEBAR] == 0)// actionner la tronco
		{
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[87].img_ptr,
					610, 697); // tronco 1
			if (p->trons == 0)
			{
				p->trons = 1;
				if (p->sound == 1)
					system("afplay ./doomzik/chainsaw_attack_out.mp3 &");
			}
		}
		else if (p->keypress[KEY_SPACEBAR] == 1)// actionner la tronco
			weapon2(p);
	}
	weapon3(p);
}
