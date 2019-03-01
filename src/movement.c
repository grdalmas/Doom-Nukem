/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 01:01:59 by bbataini          #+#    #+#             */
/*   Updated: 2019/03/02 00:10:21 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void			elevator(t_struct *p)
{
	if (p->keypress[KEY_1] == 1 || p->keypress[KEY_2] == 1
			|| p->keypress[KEY_3] == 1 || p->keypress[KEY_4] == 1
			|| p->keypress[KEY_5] == 1)
	{
		if (p->k == 7)
			p->h = 0;
		if (p->keypress[KEY_1] == 1)
			p->k = 7;
		else if (p->keypress[KEY_2] == 1)
			p->k = 0;
		else if (p->keypress[KEY_3] == 1)
			p->k = 5;
		else if (p->keypress[KEY_4] == 1)
			p->k = 8;
		else if (p->keypress[KEY_5] == 1)
			p->k = 9;
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
}

void			rotation(t_struct *p, int mod)
{
	double tmp_dir_x;
	double tmp_plane_x;

	if (mod == 0)
		p->c->rotation_speed = 0.1;
	if (mod == 1)
		p->c->rotation_speed = -0.1;
	tmp_dir_x = p->c->dir_x;
	p->c->dir_x = tmp_dir_x * cos(-p->c->rotation_speed) -
		p->c->dir_y * sin(-p->c->rotation_speed);
	p->c->dir_y = tmp_dir_x * sin(-p->c->rotation_speed) +
		p->c->dir_y * cos(-p->c->rotation_speed);
	tmp_plane_x = p->c->plane_x;
	p->c->plane_x = tmp_plane_x * cos(-p->c->rotation_speed) -
		p->c->plane_y * sin(-p->c->rotation_speed);
	p->c->plane_y = tmp_plane_x * sin(-p->c->rotation_speed) +
		p->c->plane_y * cos(-p->c->rotation_speed);
}

static void		move_up3(t_struct *p, int move)
{
	if (move == 68 || move == 66)
	{
		if (p->k == 0 && move == 68)
			move_tim(p, move);
		else if (p->k == 0 && move == 66)
			move_greg(p, move);
		else
		{
			p->k = 0;
			p->c->p_x = ((int)p->c->p_x == 13) ? 1.5 : 13.5;
			system("killall afplay");
		}
	}
	if (move == 21)
		close_window(p);
}

static void		move_up2(t_struct *p, int move)
{
	if (move == 13)
	{
		system("killall afplay");
		system("afplay ./musics/lego.mp3 &");
		if (p->k == 2)
		{
			system("killall afplay");
			system("afplay ./musics/amblobby.mp3 &");
		}
		p->c->p_y = (p->k == 0) ? 13.5 : 1.5;
		p->k = (p->k == 0) ? 2 : 0;
	}
	else if (move == 12)
	{
		system("killall afplay");
		system("afplay ./musics/ambbobo.mp3 &");
		if (p->k == 1)
		{
			system("killall afplay");
			system("afplay ./musics/amblobby.mp3 &");
		}
		p->c->p_y = (p->k == 0) ? 1.5 : 13.5;
		p->k = (p->k == 0) ? 1 : 0;
	}
	move_up3(p, move);
}

int			against_glitch_straff(t_struct * p, int move, double s)
{
		if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y))] == 0)
		{
			if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) + 1] > 0
					&& (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y))] > 0))
			{
				if (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y)) + 1] == 0)
				{
					printf("y a un coin 1!!!\n");
					if ((int)(p->c->p_x + p->c->plane_x * s) == (int)p->c->p_x + 1
							|| (int)(p->c->p_y + p->c->plane_y * s) == (int)p->c->p_y + 1)
						move = 1;
				}
			}
		}
			if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) - 1] > 0
					&& (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y))] > 0))
			{
				if (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y)) - 1] == 0)
				{
					printf("y a un coin 2!!!\n");
					if ((int)(p->c->p_x + p->c->plane_x * s) == (int)p->c->p_x - 1
							|| (int)(p->c->p_y + p->c->plane_y * s) == (int)p->c->p_y - 1)
						move = 1;
				}
			}
			if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) - 1] > 0
					&& (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y))] > 0))
			{
				if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y)) - 1] == 0)
				{
					printf("y a un coin 3!!!\n");
					if ((int)(p->c->p_x + p->c->plane_x * s) == (int)p->c->p_x - 1
							|| (int)(p->c->p_y + p->c->plane_y * s) == (int)p->c->p_y - 1)
						move = 1;
				}
			}
			if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y))] > 0
					&& (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) + 1] > 0))
			{
				if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y)) + 1] == 0)
				{
					printf("y a un coin 4!!!\n");
					if ((int)(p->c->p_x + p->c->plane_x * s) == (int)p->c->p_x - 1
							|| (int)(p->c->p_y + p->c->plane_y * s) == (int)p->c->p_y + 1)
						move = 1;
				}
			}
	return (move);
}

int			against_glitch(t_struct * p, int move, double s)
{
		if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y))] == 0)
		{
			if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) + 1] > 0
					&& (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y))] > 0))
			{
				if (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y)) + 1] == 0)
				{
					printf("y a un coin 1!!!\n");
					if ((int)(p->c->p_x + p->c->dir_x * s) == (int)p->c->p_x + 1
							|| (int)(p->c->p_y + p->c->dir_y * s) == (int)p->c->p_y + 1)
						move = 1;
				}
			}
		}
			if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) - 1] > 0
					&& (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y))] > 0))
			{
				if (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y)) - 1] == 0)
				{
					printf("y a un coin 2!!!\n");
					if ((int)(p->c->p_x + p->c->dir_x * s) == (int)p->c->p_x - 1
							|| (int)(p->c->p_y + p->c->dir_y * s) == (int)p->c->p_y - 1)
						move = 1;
				}
			}
			if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) - 1] > 0
					&& (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y))] > 0))
			{
				if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y)) - 1] == 0)
				{
					printf("y a un coin 3!!!\n");
					if ((int)(p->c->p_x + p->c->dir_x * s) == (int)p->c->p_x - 1
							|| (int)(p->c->p_y + p->c->dir_y * s) == (int)p->c->p_y - 1)
						move = 1;
				}
			}
			if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y))] > 0
					&& (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) + 1] > 0))
			{
				if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y)) + 1] == 0)
				{
					printf("y a un coin 4!!!\n");
					if ((int)(p->c->p_x + p->c->dir_x * s) == (int)p->c->p_x - 1
							|| (int)(p->c->p_y + p->c->dir_y * s) == (int)p->c->p_y + 1)
						move = 1;
				}
			}
	return (move);
}



		void			move_up(t_struct *p, int move, int i, double s)
		{
			int t;
			int tmp;

			t = 0;
			tmp = 0;
			while (t < NUMPORTE)
			{
				if (p->porte[t].zip == move)
					break ;
				t++;
			}
			if (move == 0 && (int)p->c->p_x == 7 && (int)p->c->p_y == 7
					&& p->k != 1 && p->k != 2 && p->k != 3 && p->k != 4)
			{
				if (p->k == 0)
					p->elevator = 2;
				if (p->k == 5)
					p->elevator = 3;
				if (p->k == 7)
					p->elevator = 1;
				if (p->k == 8)
					p->elevator = 4;
				if (p->k == 9)
					p->elevator = 5;
				elevator(p);
			}

			if (move == 0 && (p->keypress[KEY_A] == 1 || p->keypress[KEY_D] == 1) && p->k == 4)
				move = against_glitch_straff(p, move, s);
			if (move == 0 && (p->keypress[KEY_A] == 1 || p->keypress[KEY_D] == 1))
			{
				//		write(1, "1\n", 2);
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
			if (p->k == 4)
				move = against_glitch(p, move, s);
			if (move == 0 || (t < NUMPORTE && p->porte[t].open >= 0.6))
			{
				//		write(1, "2\n", 2);
				//	if ((p->c->middle_wall_dist > 0.5) && )
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
			else if (move == 12 || move == 13 || move == 68 || move == 66)
				system("afplay ./musics/tp.mp3 &");
			move_up2(p, move);
		}
