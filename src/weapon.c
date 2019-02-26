/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 02:44:09 by cmartine          #+#    #+#             */
/*   Updated: 2019/02/26 00:45:34 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void		touch_by_enemy(t_struct *p)
{
	int i;

	i = 4;
	while (i < 10)
	{
		if (i < 10 && p->k == p->sprite[i].k && (int)p->sprite[i].x
	== (int)p->c->p_x && (int)p->sprite[i].y == (int)p->c->p_y && p->life >= 0)
			p->life -= 0.2;
		else if (i < 16 && p->k == p->sprite[i].k && (int)p->sprite[i].x
	== (int)p->c->p_x && (int)p->sprite[i].y == (int)p->c->p_y)
			p->life -= 10;
		i++;
	}
	if (p->life < 1)
	{
		p->life = 0;
//		mlx_string_put(p->mlx_ptr, p->w_ptr, 900, 400, 0xffffff, "GAME OVER");
	}
}

void		hit_enemy(t_struct *p)
{
	int i;

	i = 4;
	while (i < 10)
	{
		if (p->keypress[KEY_SPACEBAR] == 1 && ((int)p->sprite[i].x
					== (int)p->c->p_x && (int)p->sprite[i].y == (int)p->c->p_y))
			p->sprite[i].pv--;
		i++;
	}
}

void		life_barre(t_struct *p)
{
	int i;

	p->c->colo = 0xFFFFFF;
	p->c->x1 = 10;
	draw_line2(10, 310, 10, p);
	draw_line2(10, 10, 40, p);
	p->c->x1 = 310;
	draw_line2(40, 310, 10, p);
	draw_line2(40, 10, 40, p);
	char *str;
	str = ft_itoa(p->life);
	mlx_string_put(p->mlx_ptr, p->w_ptr, 660, 15, 0xffffff, str);
	free(str);
//	mlx_string_put(p->mlx_ptr, p->w_ptr, 660, 15, 0xffffff, ft_itoa(p->life));
	mlx_string_put(p->mlx_ptr, p->w_ptr, 691, 15, 0xffffff, "%");
	i = 0;
	while (i < p->life * 3)
	{
		p->c->x1 = 10 + i;
		draw_line2(10, 10 + i, 40, p);
		i++;
	}
}

void		reload(t_struct *p)
{
	if (p->weapon.reload < 2)
	{
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[96].img_ptr, 800, 490);
		if (p->keypress[KEY_R] == 1)
			system("afplay ./Musiques/shotgun_pump.mp3 &");
	}
	else if (p->weapon.reload < 4)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[97].img_ptr, 800, 490);
	else if (p->weapon.reload < 6)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[98].img_ptr, 800, 490);
	else if (p->weapon.reload < 8)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[99].img_ptr, 800, 490);
	else if (p->weapon.reload < 10)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[100].img_ptr, 800, 490);
	else if (p->weapon.reload < 12)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[101].img_ptr, 800, 490);
}

void		shoot(t_struct *p)
{
	if (p->keypress[KEY_SPACEBAR] == 1 && p->weapon.reload > 11)
	{
		system("afplay ./Musiques/shotgun_shot.mp3 &");
		p->shoot = 1;
		p->weapon.reload = 0;
		p->weapon.sprite = 1;
	}
	if (p->weapon.sprite > 0)
	{
		if (p->weapon.sprite < 3)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[93].img_ptr, 800, 670);
		else if (p->weapon.sprite < 5)
		{
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[94].img_ptr, 800, 670);
			p->weapon.sprite = -1;
		}
		p->weapon.sprite++;
	}
	else if (p->weapon.reload < 12)
		reload(p);
	else
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[92].img_ptr, 800, 670);
}

void		soundtronco(t_struct *p)
{
	//	if (
	(void)p;
}

void		weapon(t_struct *p)
{

	p->weapon.id = 2;

	if (p->weapon.id == 1)
	{
		if (p->temp == 1)
			system("afplay ./Musiques/chainsaw_sustain.mp3 &");
		if (p->keypress[KEY_SPACEBAR] == 0) // actionner la tronco
		{
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[87].img_ptr, 610, 697); // tronco 1
			if (p->trons == 0)
			{
				p->trons = 1;
				system("afplay ./Musiques/chainsaw_attack_out.mp3 &");
			}
		}
		//if (p->keypress[KEY_SPACEBAR] == 1) // actionner la tronco
		//	mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[87].img_ptr, 610, 697); // tronco 1
		else if (p->keypress[KEY_SPACEBAR] == 1)// actionner la tronco
		{
			if (p->temp == 1)
				system("afplay ./Musiques/chainsaw_attack_middle.mp3 &");
			if (p->trons == 1)
			{
				p->trons = 0;
				system("afplay ./Musiques/chainsaw_attack_in.mp3 &");
			}
			soundtronco(p);
			p->soundtmp = p->temp;
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[88].img_ptr, 610, 583); // tronco 2
		}
	}
	touch_by_enemy(p);
	if (p->weapon.id == 1)
		hit_enemy(p);
	if (p->weapon.id == 2)
		shoot(p);
	life_barre(p);
	trump(p);
}
