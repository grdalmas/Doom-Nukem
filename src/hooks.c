/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 02:06:49 by cmartine          #+#    #+#             */
/*   Updated: 2019/02/22 00:03:18 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void		take_object(t_struct *p)
{
	/*
	   int i;
	   int x;
	   int y;
	   i = 0;
	   while (i < 4)
	   {
	   if ((int)p->sprited[i] == 0)
	   {
	//			p->sprite[i].k = 6;
	if (i == 1 || i == 2)
	x = -30;
	if (i == 0 || i == 3)
	x = 140;
	if (i == 1 || i == 3)
	y = 210;
	if (i == 2 || i == 0)
	y = 375;
	mlx_put_image_to_window(p->mlx_ptr, p->w_ptr,
	p->tex[i].img_ptr, x, y);
	system("afplay ./musics/zip.mp3 &");
	}
	i++;
	} */
	//	printf("iuh");
	// pour fair apparaitre la tronconneuse
	if (p->k == 7 && (int)p->c->p_x == (int)p->sprite[16].x && (int)p->sprite[16].y == (int)p->c->p_y && p->trump != 3 && p->sprite[16].k != 6)
	{
			printf("ilasfjklajflw");
		p->trump = 3;
		p->sprite[16].k = 6;
		p->weapon.id = 1;
	}
	// pour ramasser caisse a outils et ouvrir ascenceur
	else if (p->k == 2 && (int)p->sprited[0] == 0)//(int)p->c->p_x == (int)p->sprite[0].x && (int)p->sprite[0].y == (int)p->c->p_y)
	{
		p->tool = 1;
		p->trump = 2;
		p->sprite[0].k = 6;
		// METTRE CONDITION POUR OUVRIR LA PORTE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
	}
	else if (p->k == 1 && (int)p->sprited[3] == 0)//(int)p->c->p_x == (int)p->sprite[0].x && (int)p->sprite[0].y == (int)p->c->p_y)
	{
		p->maap = 1;
		p->sprite[3].k = 6;
		// METTRE CONDITION POUR OUVRIR LA PORTE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
	}
	else if (p->k == 9 && (int)p->sprited[18] == 0 && p->trump != 6 && p->trump != 7)//(int)p->c->p_x == (int)p->sprite[0].x && (int)p->sprite[0].y == (int)p->c->p_y)
	{
		p->sprite[18].id = 14;
		p->trump = 6;
		//		p->sprite[3].k = 6;
		// METTRE CONDITION POUR OUVRIR LA PORTE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
	}
	else if (p->k == 5 && (int)p->c->p_x == (int)p->sprite[2].x && (int)p->sprite[2].y == (int)p->c->p_y && p->trump != 4 && p->sprite[2].k != 6)
	{
		p->trump = 4;
		p->sprite[2].k = 6;
		p->weapon.id = 2;
	}
	else if (p->k == 0 && p->trump == 1)
		p->trump = 0;
	else if (p->k == 2 && p->trump == 2)
		p->trump = 0;
	else if (p->k == 7 && p->trump == 3)
		p->trump = 0;
	else if (p->trump == 6)
		p->trump = 7;
	else if (p->trump == 4)
		p->trump = 0;
	if (p->k == 8 && (int)p->sprited[1] == 0 && p->trump != 5 && p->sprite[1].k != 6)
	{
		p->trump = 5;
		p->sprite[1].k = 6;
		p->cure = 1;
		p->life += 50;
		if (p->life > 100)
			p->life = 100;
	}
	//	printf("trump1 :%d\n", p->trump);
}

void			soundstep(t_struct *p)
{
	if (p->c->pas == PAS && (p->c->pas = 1) == 1)
		system("afplay ./musics/pas1.mp3 &");
	else if (p->c->pas == PAS + 1 && (p->c->pas = 2) == 2)
		system("afplay ./musics/pas2.mp3 &");
	else if (p->c->pas == PAS + 2 && (p->c->pas = 3) == 3)
		system("afplay ./musics/pas3.mp3 &");
	else if (p->c->pas == PAS + 3 && (p->c->pas = 4) == 4)
		system("afplay ./musics/pas4.mp3 &");
	else if (p->c->pas == PAS + 4 && (p->c->pas = 5) == 5)
		system("afplay ./musics/pas5.mp3 &");
	else if (p->c->pas == PAS + 5 && (p->c->pas = 6) == 6)
		system("afplay ./musics/pas6.mp3 &");
	else if (p->c->pas == PAS + 6 && (p->c->pas = 0) == 0)
		system("afplay ./musics/pas7.mp3 &");
}

void			flee(t_struct *p)
{
	if ((int)p->sprited[2] == 0 && p->c->tpobj == 0)
	{
		p->sprite[2].x = 12;
		p->c->tpobj++;
		system("afplay ./musics/flee.mp3 &");
	}
	else if ((int)p->sprited[2] == 0 && p->c->tpobj == 1)
	{
		p->sprite[2].y = 12;
		p->c->tpobj++;
		system("afplay ./musics/flee.mp3 &");
	}
	else if ((int)p->sprited[2] == 0 && p->c->tpobj++ == 2)
	{
		p->sprite[2].x = 3;
		system("afplay ./musics/flee.mp3 &");
	}
}

int				key_press_hook(t_struct *p)
{
	printf("ptrump : %d\n", p->trump);
	double s;
	int key = 0;
	if (p->keypress[KEY_ESCAPE] == 1)
		close_window(p);
	if (p->keypress[KEY_LEFT] == 1)
		rotation(p, 0);
	if (p->keypress[KEY_RIGHT] == 1)
		rotation(p, 1);
	//if (p->keypress[KEY_Q] == 1)
	if (p->keypress[KEY_W] == 1 || p->keypress[KEY_S] == 1)
	{
		s = (p->keypress[KEY_W] ? 0.2 : -0.2);
		key = p->map[p->k][(int)((p->c->p_x + p->c->dir_x * s))]
			[(int)((p->c->p_y + p->c->dir_y * s))];
	}
	if (p->keypress[KEY_A] == 1 || p->keypress[KEY_D] == 1)
	{
		s = (p->keypress[KEY_A] ? 0.2 : -0.2);
		key = p->map[p->k][(int)((p->c->p_x + p->c->plane_x * s))]
			[(int)((p->c->p_y + p->c->plane_y * s))];
	}
	//	soundstep(p);
	if (key == 0)
		p->c->pas += 7;
	move_up(p, key, 0, s);
	//	if (p->keypress[KEY_E] == 1)
	//		take_object(p);
	if (p->k == 1)
		flee(p);
	return (0);
}
