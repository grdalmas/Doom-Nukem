/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_states.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:28:25 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/02 09:00:19 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

int				close_window(t_struct *p)
{
	mlx_destroy_image(p->mlx_ptr, p->img_ptr);
	mlx_destroy_window(p->mlx_ptr, p->w_ptr);
	system("killall afplay");
	exit(EXIT_SUCCESS);
}

void			*init(t_struct *param)
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
	camera->move_speed = 0.2;
	camera->pas = 1;
	camera->tpobj = 0;
	param->life = 100;
	param->floor = 7;
	param->dead = 0;
	param->cure = 0;
	return (NULL);
}

void			initplayer(t_struct *param)
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
