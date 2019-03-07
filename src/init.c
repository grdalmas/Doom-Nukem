/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_states.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:28:25 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/07 20:47:29 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

int			close_window(t_struct *p)
{
	mlx_destroy_image(p->mlx_ptr, p->img_ptr);
	mlx_destroy_window(p->mlx_ptr, p->w_ptr);
	system("killall afplay");
	exit(EXIT_SUCCESS);
}

void		*init(t_struct *param)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)malloc(sizeof(t_camera))))
		return (NULL);
	param->soundpain = 100;
	param->soundpainmum = 0;
	param->c = camera;
	camera->p_x = 6.5;
	camera->p_y = 7.5;
	camera->dir_x = -1;
	camera->dir_y = 0;
	camera->plane_x = 0;
	camera->plane_y = 1;
	camera->pas = 1;
	param->life = 100;
	param->floor = 7;
	param->dead = 0;
	param->cure = 0;
	param->maap = 0;
	system("afplay ./doomzik/amblobby.mp3 &");
	return (NULL);
}

void		initplayer(t_struct *param)
{
	param->k = 0;
	param->keypress[KEY_Q] = 2;
	param->porte = init_door();
	param->sprite = init_sprite();
	param->weapon.id = 0;
	param->h = 0;
	param->weapon.reload = 0;
	param->s = -1;
	param->trump = 1;
	param->temp = 1;
	param->trons = 0;
	param->elev = 0;
	param->trumplive = 1;
	param->menu = 4;
	param->choice = 0;
	param->ch = 0;
	param->sound = 1;
	param->difficulty = 0;
	init_time_struct(&param->time);
}

t_sprite	*init_sprite(void)
{
	static t_sprite sprite[NUMSPRITE] = {
		{2, 0, 7.5, 7.5, 1}, {8, 1, 7.5, 9.5, 10},
		{0, 51, 9.5, 2.5, 1000}, {1, 3, 3, 3, 1},
		{5, 82, 7.5, 2, 10}, {5, 82, 1.5, 10.5, 10},
		{5, 82, 3.5, 11.5, 10}, {5, 82, 7.5, 1.5, 10},
		{5, 82, 9.5, 13.5, 10}, {5, 82, 7.5, 3.5, 10},
		{8, 119, 2.5, 2.5, 10}, {8, 119, 4, 4, 10},
		{8, 119, 13, 13, 10},
		{8, 119, 13, 2.5, 10},
		{8, 119, 7.5, 2, 10},
		{8, 119, 7.5, 12.5, 10}, {7, 86, 4.5, 3.5, 1},
		{0, 14, 11, 11, 10},
		{9, 14, 7.5, 1.5, 10},
		{6, 95, 7.5, 2, 1},
		{6, 51, 0, 0, 0},
		{6, 33, 0, 0, 0},
		{6, 46, 0, 0, 0},
		{6, 50, 0, 0, 0},
		{1, 33, 7.5, 7.5, 1}
	};

	return (sprite);
}

t_porte		*init_door(void)
{
	static t_porte porte[NUMPORTE] = {{0, 0.02, 22, 1}, {1, 0.02, 2, 1}};

	return (porte);
}
