/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:35:20 by grdalmas          #+#    #+#             */
/*   Updated: 2019/02/26 23:17:48 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"
/*
static void put_interface_text(t_struct *p)
{
	t_coord pt;

	pt.x = PERCENTAGE(50, p->image[MAP_CREATOR].size.x);
	pt.y = PERCENTAGE(2, p->image[MAP_CREATOR].size.y);
	string_to_img(MC_TITLE, center_str(MC_TITLE,pt), &p->image[MAP_CREATOR], p);
	pt.x = PERCENTAGE(50, p->image[GAME_I].size.x);
	pt.y = PERCENTAGE(5, p->image[GAME_I].size.y);
	string_to_img(MC_INFO, centerx_str(MC_INFO, pt), &p->image[GAME_I], p);
}

void	draw_map_creator(void *gm)
{
	t_struct	*p;
	t_coord 	pt;

	if (!(p = (t_struct*)gm))
		return ;
	put_texture_on_img(&p->image[MAP_CREATOR], &p->texture[T_MAP_CREATOR]);
	put_texture_on_img(&p->image[GAME_I], &p->texture[T_CREATOR_INTERFACE]);
	mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->image[p->current_page].ptr, 0, 0);
	mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->image[GAME_I].ptr, 0, p->image[MAP_CREATOR].size.y);
	put_interface_text(p);
	draw_pallette(p);
}*/
