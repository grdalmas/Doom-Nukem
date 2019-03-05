/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 00:11:00 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/05 05:51:28 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom-nukem.h"

static void			creator_map_textures(t_struct *p)
{
	ft_bzero(p->img_str2, WIDTH * HEIGHT * 4);
	//mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[42].img_ptr, 300, 0);
	img_to_img3(p, 0, 0, 42);
	img_to_img(p, 946, 240, 7);
	img_to_img(p, 841, 135, 8);
	img_to_img(p, 841, 240, 23);
	img_to_img(p, 946, 135, 9);
	img_to_img(p, 1051, 240, 4);
	img_to_img(p, 1051, 135, 10);
	img_to_img(p, 1156, 240, 121);
	img_to_img(p, 1156, 135, 11);
	img_to_img(p, 841, 435, 51);
	img_to_img(p, 946, 435, 33);
	img_to_img(p, 1051, 435, 46);
	img_to_img(p, 1156, 435, 50);
}

static void			creator_map2(t_struct *p, int i, int j)
{
	if (p->floor != 0)
	{
		img_to_img2(p, (i - 1) * 40 + 456,
						j * 40 - 5, p->floor);
	}
	i = 20;
	while (i < 24)
	{
		if (p->sprite[i].k == 4)
		{
			img_to_img2(p, 136 + ((15 - p->sprite[i].y) * 40),
					15 + (p->sprite[i].x * 40), p->sprite[i].id);
		}
		i++;
	}
}

void				creator_map(t_struct *p, int i, int j)
{
	creator_map_textures(p);
	while (i < 15)
	{
		j = 0;
		while (j < 15)
		{
			if (p->map[4][j][i] == 1)
			{
				img_to_img2(p, 156 + (i * 40),
						35 + (j * 40), 9);
			}
			if (p->map[4][j][i] > 1)
			{
				img_to_img2(p, 156 + (i * 40),
						35 + (j * 40), p->map[4][j][i]);
			}
			j++;
		}
		i++;
	}
	creator_map2(p, i, j);
	minimap2(p);
}
