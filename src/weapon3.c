/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:39:29 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/05 06:14:45 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void				soundpain(t_struct *p)
{
	if (p->soundpain >= p->life + 5)
	{
		p->soundpainmum++;
		p->soundpain = p->life;
		if (p->soundpainmum == 1)
			system("afplay ./doomzik/pain_1.mp3 &");
		else if (p->soundpainmum == 2)
			system("afplay ./doomzik/pain_2.mp3 &");
		else if (p->soundpainmum == 3)
			system("afplay ./doomzik/pain_4.mp3 &");
		else if (p->soundpainmum == 4)
		{
			p->soundpainmum = 0;
			system("afplay ./doomzik/pain_3.mp3 &");
		}
	}
}

static void			reload(t_struct *p)
{
	if (p->weapon.reload < 2)
	{
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[96].img_ptr, 800, \
				490);
		if (p->keypress[KEY_R] == 1 && p->sound == 1)
			system("afplay ./doomzik/shotgun_pump.mp3 &");
	}
	else if (p->weapon.reload < 4)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[97].img_ptr, 800,
				490);
	else if (p->weapon.reload < 6)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[98].img_ptr, 800,
				490);
	else if (p->weapon.reload < 8)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[99].img_ptr, 800,
				490);
	else if (p->weapon.reload < 10)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[100].img_ptr, 800,
				490);
	else if (p->weapon.reload < 12)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[101].img_ptr, 800,
				490);
}

static void			shoot2(t_struct *p)
{
	if (p->weapon.sprite > 0)
	{
		if (p->weapon.sprite < 3)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[93].img_ptr,
					800, 670);
		else if (p->weapon.sprite < 5)
		{
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[94].img_ptr,
					800, 670);
			p->weapon.sprite = -1;
		}
		p->weapon.sprite++;
	}
	else if (p->weapon.reload < 12)
		reload(p);
	else
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[92].img_ptr,
				800, 670);
}

void				shoot(t_struct *p)
{
	if (p->keypress[KEY_R] == 1 && p->weapon.reload < 12)
		p->weapon.reload += 1;
	else
		p->keypress[KEY_R] = 0;
	if (p->keypress[KEY_SPACEBAR] == 1 && p->weapon.reload > 11)
	{
		if (p->sound == 1)
			system("afplay ./doomzik/shotgun_shot.mp3 &");
		p->shoot = 1;
		p->weapon.reload = 0;
		p->weapon.sprite = 1;
	}
	shoot2(p);
}
