/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:39:26 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/04 20:42:03 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void		touch_by_enemy(t_struct *p)
{
	int i;

	i = 4;
	while (i < 16)
	{
		if (i < 10 && p->k == p->sprite[i].k && (int)p->sprite[i].x \
				== (int)p->c->p_x && (int)p->sprite[i].y == (int)p->c->p_y \
				&& p->life >= 0)
			p->life -= 0.2;
		else if (i < 16 && p->k == p->sprite[i].k && (int)p->sprite[i].x \
				== (int)p->c->p_x && (int)p->sprite[i].y == (int)p->c->p_y)
			p->life -= 1;
		i++;
	}
	if (p->life < 1)
	{
		p->life = 0;
		p->menu = 2;
		p->temp = 0;
	}
}

void		touch_by_enemyhard(t_struct *p)
{
	int i;

	i = 4;
	while (i < 16)
	{
		if (i < 10 && p->k == p->sprite[i].k && (int)p->sprite[i].x \
				== (int)p->c->p_x && (int)p->sprite[i].y == (int)p->c->p_y \
				&& p->life >= 0)
			p->life -= 0.4;
		else if (i < 16 && p->k == p->sprite[i].k && (int)p->sprite[i].x \
				== (int)p->c->p_x && (int)p->sprite[i].y == (int)p->c->p_y)
			p->life -= 2;
		i++;
	}
	if (p->life < 1)
	{
		p->life = 0;
		p->menu = 2;
		p->temp = 0;
	}
}

void		soundpain(t_struct *p)
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

void		hit_enemy(t_struct *p)
{
	int i;

	i = 4;
	while (i < 18)
	{
		if (p->keypress[KEY_SPACEBAR] == 1 && ((int)p->sprite[i].x
					== (int)p->c->p_x && (int)p->sprite[i].y == (int)p->c->p_y))
			p->sprite[i].pv--;
		i++;
	}
}

void		life_barre(t_struct *p)
{
	int		i;
	char	*str;

	p->c->colo = 0xFFFFFF;
	p->c->x1 = 10;
	draw_line2(10, 310, 10, p);
	draw_line2(10, 10, 40, p);
	p->c->x1 = 310;
	draw_line2(40, 310, 10, p);
	draw_line2(40, 10, 40, p);
	str = ft_itoa(p->life);
	mlx_string_put(p->mlx_ptr, p->w_ptr, 660, 15, 0xffffff, str);
	free(str);
	//	mlx_string_put(p->mlx_ptr, p->w_ptr, 660, 15, 0xffffff, ft_itoa(p->life));
	mlx_string_put(p->mlx_ptr, p->w_ptr, 691, 15, 0xffffff, "%");
	i = 0;
	if (p->sound == 1)
		soundpain(p);
	while (i < p->life * 3)
	{
		p->c->x1 = 10 + i;
		draw_line2(10, 10 + i, 40, p);
		i++;
	}
}
