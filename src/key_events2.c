/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <tifuret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:25:34 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/07 20:45:31 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static int			proxyporte(t_struct *p)
{
	int i;

	i = 0;
	while (i < NUMPORTE - 1)
	{
		if (p->map[p->k][(int)p->c->p_x][(int)p->c->p_y] == p->porte[i].zip
				|| p->map[p->k][(int)p->c->p_x - 1][(int)p->c->p_y]
				== p->porte[i].zip
				|| p->map[p->k][(int)p->c->p_x + 1][(int)p->c->p_y]
				== p->porte[i].zip
				|| p->map[p->k][(int)p->c->p_x][(int)p->c->p_y - 1]
				== p->porte[i].zip
				|| p->map[p->k][(int)p->c->p_x][(int)p->c->p_y + 1]
				== p->porte[i].zip)
			return (i);
		i++;
	}
	return (-1);
}

static void			keypress4(int keycode, t_struct *p)
{
	if (keycode == MLX_KEY_P && (p->menu == 1 || p->menu == 0))
	{
		if (p->menu == 0)
			p->menu = 1;
		else
		{
			p->menu = 0;
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[120].img_ptr,
					340, 0);
		}
	}
	else if (keycode == MLX_KEY_SHIFT_LEFT)
		p->keypress[KEY_SHIFT] = 1;
}

void				keypress3(int keycode, t_struct *p)
{
	if (keycode == MLX_KEY_PAD_5)
		p->keypress[KEY_PAD_5] = 1;
	else if (keycode == MLX_KEY_E && p->menu == 1)
	{
		if (p->porte[proxyporte(p)].poort == 0)
			p->porte[proxyporte(p)].poort = 1;
		else if (p->porte[proxyporte(p)].poort == 1)
			if (p->sprite[0].k == 6 && p->elev == 0 && p->k == 0 && p->trump
					== 0 && (int)p->c->p_x == 6 && (int)p->c->p_y == 7)
			{
				p->elev = 1;
				p->tool = 0;
			}
		if (p->sprite[0].k == 6)
			p->porte[proxyporte(p)].poort = 0;
		p->keypress[KEY_E] = 1;
	}
	else if (keycode == MLX_KEY_R)
		p->keypress[KEY_R] = 1;
	else
		keypress4(keycode, p);
}
