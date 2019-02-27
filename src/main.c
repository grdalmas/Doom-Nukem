/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:09:28 by bbataini          #+#    #+#             */
/*   Updated: 2019/02/27 22:47:37 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"


// void			flyisabug(t_struct *p)
// {
// 	float	s;
// 	int		nb;

// 	s = 0.5;
// 	nb = (rand() % 4);
// 	if (nb == 0 && p->map[p->k][(int)(p->sprite[4].x + s)]
// 			[(int)(p->sprite[4].y)] == 0)
// 		p->sprite[4].x += s;
// 	else if (nb == 1 && p->map[p->k][(int)(p->sprite[4].x)]
// 			[(int)(p->sprite[4].y + s)] == 0)
// 		p->sprite[4].y += s;
// 	else if (nb == 2 && p->map[p->k][(int)(p->sprite[4].x - s)]
// 			[(int)(p->sprite[4].y)] == 0)
// 		p->sprite[4].x -= s;
// 	else if (nb == 3 && p->map[p->k][(int)(p->sprite[4].x)]
// 			[(int)(p->sprite[4].y - s)] == 0)
// 		p->sprite[4].y -= s;
// }

// void		mvmy(t_struct *p, int i, float sx, float sy)
// {
// 	int j;

// 	j = 4;
// 	while (j < 10)
// 	{
// 		if (p->sprite[j].k == 5 && ((int)(p->sprite[i].x + sx)
// 					== (int)p->sprite[j].x &&
// 					(int)(p->sprite[i].y + sy) == (int)p->sprite[j].y && j != i))
// 			break ;
// 		else if (j >= 9)
// 		{
// 			p->sprite[i].x += sx;
// 			p->sprite[i].y += sy;
// 		}
// 		j++;
// 	}
// }

// void		mvmy2(t_struct *p, int i, float sx, float sy)
// {
// 	int j;

// 	j = 10;
// 	while (j < 16)
// 	{
// 		if (p->sprite[j].k == 8 && ((int)(p->sprite[i].x + sx)
// 					== (int)p->sprite[j].x &&
// 					(int)(p->sprite[i].y + sy) == (int)p->sprite[j].y && j != i))
// 			break ;
// 		else if (j >= 15)
// 		{
// 			p->sprite[i].x += sx;
// 			p->sprite[i].y += sy;
// 		}
// 		j++;
// 	}
// }

// void			movemy(t_struct *p, int i)
// {
// 	float sx;
// 	float sy;

// 	while (p->k == 5 && i < 10)
// 	{
// 		if ((p->temp % 20) < 10)
// 			p->sprite[i].id = 82;
// 		else
// 			p->sprite[i].id = 83;
// 		if (p->sprite[i].x >= p->c->p_x)
// 			sx = -0.05;
// 		else
// 			sx = 0.05;
// 		if (p->sprite[i].y >= p->c->p_y)
// 			sy = -0.05;
// 		else
// 			sy = 0.05;
// 		if (p->map[p->k][(int)(p->sprite[i].x + sx)][(int)(p->sprite[i].y + sy)]
// 				== 0 && p->sprite[i].k == 5)
// 			mvmy(p, i, sx, sy);
// 		i++;
// 	}
// }

// void			movemy2(t_struct *p, int i)
// {
// 	float sx;
// 	float sy;

// 	while (p->k == 8 && i < 18)
// 	{
// 		if (p->temp % 20 < 10)
// 			p->sprite[i].id = 84;
// 		else
// 			p->sprite[i].id = 85;
// 		if (p->sprite[i].x >= p->c->p_x)
// 			sx = -0.02;
// 		else
// 			sx = 0.02;
// 		if (p->sprite[i].y >= p->c->p_y)
// 			sy = -0.02;
// 		else
// 			sy = 0.02;
// 		if (p->map[p->k][(int)(p->sprite[i].x + sx)][(int)(p->sprite[i].y + sy)]
// 				== 0 && p->sprite[i].k == 8)
// 			mvmy2(p, i, sx,sy);
// 		i++;
// 	}
// }

void			sprite_move(t_struct *p)
{
	flyisabug(p);
	if (p->k == 5)
		movemy(p, 4);
	else if (p->k == 8)
		movemy2(p, 10);
}

void			rotrump(t_struct *p)
{// sprite qui change selon les angles, modifier le number !!!
	if (p->sprite[17].x > p->c->p_x && p->sprite[17].y > p->c->p_y)
		p->sprite[17].id = 14;
	else if (p->sprite[17].x < p->c->p_x && p->sprite[17].y < p->c->p_y)
		p->sprite[17].id = 17;
	else if (p->sprite[17].x > p->c->p_x && p->sprite[17].y < p->c->p_y)
		p->sprite[17].id = 16;
	else if (p->sprite[17].x < p->c->p_x && p->sprite[17].y > p->c->p_y)
		p->sprite[17].id = 15;
	if (p->sprite[18].x > p->c->p_x && p->sprite[18].y > p->c->p_y)
		p->sprite[18].id = 14;
	else if (p->sprite[18].x < p->c->p_x && p->sprite[18].y < p->c->p_y)
		p->sprite[18].id = 17;
	else if (p->sprite[18].x > p->c->p_x && p->sprite[18].y < p->c->p_y)
		p->sprite[18].id = 16;
	else if (p->sprite[18].x < p->c->p_x && p->sprite[18].y > p->c->p_y)
		p->sprite[18].id = 15;
}

int		mlx_main_loop(t_struct *p)
{
	int i;

	i = 0;
	if (p)
	{
		p->gm.draw[p->gm.current_state](p);
	}
	return (0);
}


static void		window(t_struct *p, int w, int h)
{
	int bpp;
	int size_l;
	int endian;

	p->mlx_ptr = mlx_init();
	p->w_ptr = mlx_new_window(p->mlx_ptr, 1620, 960, "DOOM ZER");
	p->img_ptr = mlx_new_image(p->mlx_ptr, WIDTHMAP, HEIGHTMAP);
	p->img_ptr2 = mlx_new_image(p->mlx_ptr, 1280, 960);
	p->img_ptr3 = mlx_xpm_file_to_image(p->mlx_ptr, "textures/dom.xpm", &w, &h);
	p->img_str = mlx_get_data_addr(p->img_ptr, &bpp, &size_l, &endian);
	p->img_str2 = mlx_get_data_addr(p->img_ptr2, &bpp, &p->size_line, &endian);
	//	p->img_str3 = mlx_get_data_addr(p->img_ptr3, &bpp, &size_l, &endian);
	init(p);
	initplayer(p);
	init_menu(&p->gm);
	load_textures(p);
	mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[45].img_ptr, 0, 35);
	mlx_hook(p->w_ptr, KEYPRESS, KEYPRESSMASK, keypress, p);
	mlx_hook(p->w_ptr, KEYRELEASE, KEYRELEASEMASK, keyrelease, p);
	mlx_hook(p->w_ptr, CLOSE, CLOSEMASK, close_window, p);
	mlx_mouse_hook(p->w_ptr, mouse_button, p);
	mlx_hook(p->w_ptr, MOTIONNOTIFY, POINTERMOTIONMASK, rotation2, p);
	mlx_loop_hook(p->mlx_ptr, mlx_main_loop, p);
	mlx_loop(p->mlx_ptr);
}

int				main(int argc, const char **argv)
{
	t_struct	param;

	ft_bzero(&param, sizeof(param));
	(void)argv;
	if (argc > 1)
	{
		perror("error, no argument needed");
		return (1);
	}
	if (WIDTH != 1280 || HEIGHT != 960)
	{
		ft_putendl("error, wrong size of window");
		exit(EXIT_FAILURE);
	}
	save_map(&param);
	window(&param, 35, 65);
	return (0);
}
