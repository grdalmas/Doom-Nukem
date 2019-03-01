/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 02:06:49 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/01 02:37:44 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

/*
void		print_map(t_struct *p)
{
	int i;
	int j;

	i = 0;
	while (i < 15)
	{
		j= 0;
	while (j < 15)
	{
		printf("%d ",p->map[4][i][j]);
		j++;
	}
i++;
		printf("\n");

	}
		printf("\n");
}
*/


void		take_object(t_struct *p)
{
	if (p->k == 0 && (int)p->c->p_x == (int)p->sprite[2].x && (int)p->sprite[2].y == (int)p->c->p_y && p->menu != -1)
	{
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->img_ptr2, 340, 0);
		p->menu = 3;
		inverse_map(p);
//		print_map(p);
	}
	else if (p->menu == -1)
	{
		inverse_map(p);
//		print_map(p);
		p->menu = 1; //         MENU EDITEUR
	}

		else if (p->k == 7 && (int)p->c->p_x == (int)p->sprite[16].x && (int)p->sprite[16].y == (int)p->c->p_y && p->trump != 3 && p->sprite[16].k != 6)
	{
		p->trump = 3;
		p->sprite[16].k = 6;
		p->weapon.id = 1;
		system("afplay ./Musiques/chainsaw_start.mp3 &");
	}
	// pour ramasser caisse a outils et ouvrir ascenceur
	else if (p->k == 2 && (int)p->sprited[0] == 0 && p->trump != 2 && p->sprite[0].k != 6)//(int)p->c->p_x == (int)p->sprite[0].x && (int)p->sprite[0].y == (int)p->c->p_y)
	{
		p->tool = 1;
		p->trump = 2;
		p->sprite[0].k = 6;
//		p->elev = 1;
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
	else if (p->k == 5 && (int)p->c->p_x == (int)p->sprite[19].x && (int)p->sprite[19].y == (int)p->c->p_y && p->trump != 4 && p->sprite[19].k != 6)
	{
		p->trump = 4;
		p->sprite[19].k = 6;
		p->weapon.id = 2;
	}
	else if (p->k == 8 && (int)p->sprited[1] == 0)// && p->trump != 5) //&& p->sprite[1].k != 6)
	{
		p->trump = 5;
		p->sprite[1].k = 6;
		p->cure = 1;
		p->life += 50;
		if (p->life > 100)
			p->life = 100;
	}
	else if (p->trump == 1)
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
}

void			soundstep(t_struct *p)
{
	if (p->c->pas == p->pas && (p->c->pas = 1) == 1)
		system("afplay ./musics/pas1.mp3 &");
	else if (p->c->pas == p->pas + 1 && (p->c->pas = 2) == 2)
		system("afplay ./musics/pas2.mp3 &");
	else if (p->c->pas == p->pas + 2 && (p->c->pas = 3) == 3)
		system("afplay ./musics/pas3.mp3 &");
	else if (p->c->pas == p->pas + 3 && (p->c->pas = 4) == 4)
		system("afplay ./musics/pas4.mp3 &");
	else if (p->c->pas == p->pas + 4 && (p->c->pas = 5) == 5)
		system("afplay ./musics/pas5.mp3 &");
	else if (p->c->pas ==  p->pas + 5 && (p->c->pas = 6) == 6)
		system("afplay ./musics/pas6.mp3 &");
	else if (p->c->pas >= p->pas + 6 && (p->c->pas = 0) == 0)
		system("afplay ./musics/pas7.mp3 &");
}

int				key_press_hook(t_struct *p)
{
	double s;
	int key;
	float sprint;

	key = 0;
	if (p->keypress[KEY_ESCAPE] == 1)
		close_window(p);
	if (p->keypress[KEY_LEFT] == 1)
		rotation(p, 0);
	if (p->keypress[KEY_RIGHT] == 1)
		rotation(p, 1);
	if (p->keypress[KEY_SHIFT] == 1)
	{
		sprint = 0.3;
		p->c->pas += 7;
		p->pas = 21;
	}
	else if (p->keypress[KEY_A] == 1 || p->keypress[KEY_D] == 1
			|| p->keypress[KEY_W] == 1 || p->keypress[KEY_S] == 1)
	{
		sprint = 0.2;
		p->pas = 35;
		p->c->pas += 7;
	}
		if (p->keypress[KEY_W] == 1 || p->keypress[KEY_S] == 1)
	{
		s = (p->keypress[KEY_W] ? sprint : - sprint);
		key = p->map[p->k][(int)((p->c->p_x + p->c->dir_x * s))]
			[(int)((p->c->p_y + p->c->dir_y * s))];
	}
	if (p->keypress[KEY_A] == 1 || p->keypress[KEY_D] == 1)
	{
		s = (p->keypress[KEY_A] ? sprint : - sprint);
		key = p->map[p->k][(int)((p->c->p_x + p->c->plane_x * s))]
			[(int)((p->c->p_y + p->c->plane_y * s))];
	}
	if (key == 0)
		soundstep(p);
	move_up(p, key, 0, s);
	return (0);
}
