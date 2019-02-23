/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:35:20 by grdalmas          #+#    #+#             */
/*   Updated: 2019/02/23 22:14:18 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void	draw_map_creator(void *gm)
{
	t_struct	*p;
	t_coord 	pt;

	if (!(p = (t_struct*)gm))
		return ;
	put_texture_on_img(&p->image[MAP_CREATOR], &p->texture[T_MAP_CREATOR]);
	put_texture_on_img(&p->image[GAME_I], &p->texture[T_CREATOR_INTERFACE]);
	mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, )
}
