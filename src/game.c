/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:35:25 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/07 21:58:28 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		sprite_move(t_struct *p)
{
	if (p->k == 5)
		movemy(p, 4);
	else if (p->k == 8)
	{
		if (p->keypress[KEY_E] == 1 && (int)p->c->p_x == 2
				&& (int)p->c->p_y == 7 && p->s < 0)
		{
			if (p->sound == 1)
				system("afplay ./doomzik/elevator_button.mp3 & 2>&1");
			p->s = 0;
		}
		if (p->s >= 0)
		{
			p->door[1].poort = 0;
			timer(p);
			p->s++;
			if (p->s >= 200)
				spawn(p);
		}
		movemy2(p, 10);
	}
	else if (p->k == 0)
		rotrump(p);
	else if (p->k == 9 && p->trump != 6)
		rotrump2(p);
}

static void		ingame(t_struct *p, int i)
{
	key_press_hook(p);
	raycasting(p, 0, 0);
	alive(p);
	weapon(p);
	sprite_move(p);
	while (i < NUMDOOR)
	{
		if (p->door[i].poort == 1 && p->door[i].open > 0)
			p->door[i].open -= p->door[i].spd;
		if (p->door[i].poort == 0 && p->door[i].open <= 1)
			p->door[i].open += p->door[i].spd;
		i++;
	}
	if (p->cure == 0 && p->difficulty == 0)
		p->life -= 0.01;
	else if (p->cure == 0 && p->difficulty == 1)
		p->life -= 0.02;
	if (p->trump == 7)
	{
		p->dead = 5;
		p->menu = 2;
	}
}

static void		reinit_sprite(t_struct *p)
{
	int i;

	i = 4;
	p->sprite[0].k = 2;
	p->sprite[1].k = 8;
	p->sprite[3].k = 1;
	p->sprite[16].k = 7;
	while (i < 10)
	{
		p->sprite[i].k = 5;
		p->sprite[i].pv = 10;
		i++;
	}
	while (i < 16)
	{
		p->sprite[i].k = 8;
		p->sprite[i].pv = 10;
		i++;
	}
}

static void		ingameover(t_struct *p)
{
	char *s;

	if (p->temp > 79)
		p->dead++;
	s = ft_itoa(5 - p->dead);
	if (p->dead == 5)
	{
		reinit_sprite(p);
		p->menu = 4;
		free(p->c);
		init(p);
		initplayer(p);
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[124].img_ptr, 0,
				0);
	}
	else
	{
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[119].img_ptr, 340,
				0);
		mlx_string_put(p->mlx_ptr, p->w_ptr, 900, 500, 0xffffff,
				"Retour au menu:");
		mlx_string_put(p->mlx_ptr, p->w_ptr, 1080, 500, 0xffffff, s);
	}
	free(s);
}

int				draw_game(t_struct *p)
{
	p->time.update(&p->time);
	if (p->temp < 80)
		p->temp++;
	else
		p->temp = 0;
	if (p->menu == 1)
		ingame(p, 0);
	else if (p->menu == 2)
		ingameover(p);
	else if (p->menu == 3)
	{
		if (p->edit != 0)
			img_to_img2(p, p->mousex - 350, p->mousey - 20, p->edit);
		else if (p->edits > 19)
			img_to_img2(p, p->mousex - 350, p->mousey - 20,
					p->sprite[p->edits].id);
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->img_ptr2, 340, 0);
		creator_map(p, 0, 0);
	}
	return (0);
}
