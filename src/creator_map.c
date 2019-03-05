/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 00:11:00 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/05 03:27:41 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom-nukem.h"

static void			creator_map_textures(t_struct *p)
{
	ft_bzero(p->img_str2, WIDTH * HEIGHT * 4);
	img_to_img(p, 0, 0, 42, 1);
	img_to_img(p, 945, 240, 7, 0.3);
	img_to_img(p, 840, 135, 8, 0.3);
	img_to_img(p, 840, 240, 23, 0.3);
	img_to_img(p, 945, 135, 9, 0.3);
	img_to_img(p, 1050, 240, 4, 0.3);
	img_to_img(p, 1050, 135, 10, 0.3);
	img_to_img(p, 1155, 240, 121, 0.3);
	img_to_img(p, 1155, 135, 11, 0.3);
	img_to_img(p, 840, 435, 51, 0.3);
	img_to_img(p, 945, 435, 33, 0.3);
	img_to_img(p, 1050, 435, 46, 0.3);
	img_to_img(p, 1155, 435, 50, 0.3);
}

static void			creator_map2(t_struct *p, int i, int j)
{
	if (p->floor != 0)
	{
		img_to_img(p, 155 + (i - 1) * 40 + 300,
						(j) * 40 - 5, p->floor, 0.15625);
	}
	i = 20;
	while (i < 24)
	{
		if (p->sprite[i].k == 4)
		{
			img_to_img(p, 135 + ((15 - p->sprite[i].y) * 40),
					15 + (p->sprite[i].x * 40), p->sprite[i].id, 0.15625);
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
				img_to_img(p, 155 + (i * 40),
						35 + (j * 40), 9, 0.15625);
			}
			if (p->map[4][j][i] > 1)
			{
				img_to_img(p, 155 + (i * 40),
						35 + (j * 40), p->map[4][j][i], 0.15625);
			}
			j++;
		}
		i++;
	}
	creator_map2(p, i, j);
	minimap2(p);
}
