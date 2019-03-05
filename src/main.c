/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <tifuret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:09:28 by bbataini          #+#    #+#             */
/*   Updated: 2019/03/05 11:40:59 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void			timer(t_struct *p)
{
	char *str;

	str = ft_itoa((int)(11 - p->s / 20));
	mlx_string_put(p->mlx_ptr, p->w_ptr, 691, 50, 0xffffff, str);
	free(str);
}

static void		window(t_struct *p, int w, int h)
{
	int			bpp;
	int			size_l;
	int			endian;

	p->mlx_ptr = mlx_init();
	p->w_ptr = mlx_new_window(p->mlx_ptr, 1620, 960, "DOOM ZER");
	p->img_ptr = mlx_new_image(p->mlx_ptr, WIDTHMAP, HEIGHTMAP);
	p->img_ptr2 = mlx_new_image(p->mlx_ptr, 1280, 960);
	p->img_ptr3 = mlx_xpm_file_to_image(p->mlx_ptr, "textures/dom.xpm", &w, &h);
	p->img_str = mlx_get_data_addr(p->img_ptr, &bpp, &size_l, &endian);
	p->img_str2 = mlx_get_data_addr(p->img_ptr2, &bpp, &p->size_line, &endian);
	init(p);
	initplayer(p);
	load_textures(p);
	mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[123].img_ptr, 0, 0);
	mlx_hook(p->w_ptr, KEYPRESS, KEYPRESSMASK, keypress, p);
	mlx_hook(p->w_ptr, KEYRELEASE, KEYRELEASEMASK, keyrelease, p);
	mlx_hook(p->w_ptr, CLOSE, CLOSEMASK, close_window, p);
	mlx_mouse_hook(p->w_ptr, mouse_button, p);
	mlx_hook(p->w_ptr, MOTIONNOTIFY, POINTERMOTIONMASK, mouse_motion, p);
	mlx_loop_hook(p->mlx_ptr, draw_game, p);
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
