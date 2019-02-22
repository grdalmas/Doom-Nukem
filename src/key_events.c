/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:29:26 by grdalmas          #+#    #+#             */
/*   Updated: 2019/02/22 06:18:31 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

int			proxyporte(t_struct *p)
{
	int i;
	i = 0;
	printf("%i", p->porte[i].zip);
	while (i < NUMPORTE -1)
	{
		if (p->map[p->k][(int)p->c->p_x][(int)p->c->p_y] == p->porte[i].zip ||
				p->map[p->k][(int)p->c->p_x - 1][(int)p->c->p_y] == p->porte[i].zip ||
				p->map[p->k][(int)p->c->p_x + 1][(int)p->c->p_y] == p->porte[i].zip ||
				p->map[p->k][(int)p->c->p_x][(int)p->c->p_y - 1] == p->porte[i].zip ||
				p->map[p->k][(int)p->c->p_x][(int)p->c->p_y + 1] == p->porte[i].zip)
			return (i);
		i++;
	}
	return(-1);
}


int				keypress(int keycode, void *d)
{
	t_struct *p;

	if (!(p = (t_struct*)d))
		return (0);
	if (keycode == MLX_KEY_ESCAPE)
		p->keypress[KEY_ESCAPE] = 1;
	else if (keycode == MLX_KEY_W)
		p->keypress[KEY_W] = 1;
	else if (keycode == MLX_KEY_D)
		p->keypress[KEY_D] = 1;
	else if (keycode == MLX_KEY_A)
		p->keypress[KEY_A] = 1;
	else if (keycode == MLX_KEY_S)
		p->keypress[KEY_S] = 1;
	else if (keycode == MLX_KEY_LEFT)
		p->keypress[KEY_LEFT] = 1;
	else if (keycode == MLX_KEY_UP)
		p->keypress[KEY_UP] = 1;
	else if (keycode == MLX_KEY_DOWN)
		p->keypress[KEY_DOWN] = 1;
	else if (keycode == MLX_KEY_RIGHT)
		p->keypress[KEY_RIGHT] = 1;
	else if (keycode == MLX_KEY_C)
		p->keypress[KEY_C] = 1;
	else if (keycode == MLX_KEY_SPACEBAR)
		p->keypress[KEY_SPACEBAR] = 1;
	else if (keycode == MLX_KEY_1)
		p->keypress[KEY_1] = 1;
	else if (keycode == MLX_KEY_2)
		p->keypress[KEY_2] = 1;
	else if (keycode == MLX_KEY_3)
		p->keypress[KEY_3] = 1;
	else if (keycode == MLX_KEY_4)
		p->keypress[KEY_4] = 1;
	else if (keycode == MLX_KEY_5)
		p->keypress[KEY_5] = 1;
	else if (keycode == MLX_KEY_E)// && proxyporte(p) != 0)
	{
		if (p->porte[proxyporte(p)].poort == 0)
			p->porte[proxyporte(p)].poort = 1;
		else if (p->porte[proxyporte(p)].poort == 1)
			if (p->sprite[0].k == 6 && p->elev == 0)
			{
				p->elev = 1;
				p->tool = 0;
			}
		p->porte[proxyporte(p)].poort = 0;
		p->keypress[KEY_E] = 1;
	}
	//else if (keycode == MLX_KEY_F && proxyporte(p) >= 0)//&& proxyporte(p) != 0)
	//	p->porte[proxyporte(p)].poort = 0;
	else if (keycode == MLX_KEY_R)
	{
		p->keypress[KEY_R] = 1;
	}

	else if (keycode == MLX_KEY_K)
		p->h += 10;
	else if (keycode == MLX_KEY_L)
		p->h -= 10;
	else if (keycode == MLX_KEY_SHIFT_LEFT)
		p->keypress[KEY_SHIFT] = 1;
	//else if (keycode == MLX_KEY_C)
	//	p->sprite[16].id = 83;
	//p->porte[0].open = 0;
	p->keypress[LAST_KEY_PRESS] = keycode;
	// key_press_hook(p->keypress[LAST_KEY_PRESS], d);
	/*if (p->keypress[LAST_KEY_PRESS] == 'Q')
	  {
	  p->tdoor -= 0.1;
	  }*/
	return (1);
}


int				keyrelease(int keycode, void *d)
{
	t_struct *p;

	if (!(p = (t_struct*)d))
		return (0);
	if (keycode == MLX_KEY_ESCAPE)
		p->keypress[KEY_ESCAPE] = 0;
	else if (keycode == MLX_KEY_W)
		p->keypress[KEY_W] = 0;
	else if (keycode == MLX_KEY_D)
		p->keypress[KEY_D] = 0;
	else if (keycode == MLX_KEY_A)
		p->keypress[KEY_A] = 0;
	else if (keycode == MLX_KEY_E)
	{
		p->keypress[KEY_E] = 0;
		take_object(p);
	}
	else if (keycode == MLX_KEY_S)
		p->keypress[KEY_S] = 0;
	else if (keycode == MLX_KEY_LEFT)
		p->keypress[KEY_LEFT] = 0;
	else if (keycode == MLX_KEY_UP)
		p->keypress[KEY_UP] = 0;
	else if (keycode == MLX_KEY_DOWN)
		p->keypress[KEY_DOWN] = 0;
	else if (keycode == MLX_KEY_RIGHT)
		p->keypress[KEY_RIGHT] = 0;
	else if (keycode == MLX_KEY_C)
		p->keypress[KEY_C] = 0;
	else if (keycode == MLX_KEY_SPACEBAR)
		p->keypress[KEY_SPACEBAR] = 0;
	else if (keycode == MLX_KEY_S)
		p->keypress[KEY_S] = 0;
	if (keycode == MLX_KEY_R)
	{
		p->keypress[KEY_R] = 1;
	}
	else if (keycode == MLX_KEY_1)
		p->keypress[KEY_1] = 0;
	else if (keycode == MLX_KEY_2)
		p->keypress[KEY_2] = 0;
	else if (keycode == MLX_KEY_3)
		p->keypress[KEY_3] = 0;
	else if (keycode == MLX_KEY_4)
		p->keypress[KEY_4] = 0;
	else if (keycode == MLX_KEY_5)
		p->keypress[KEY_5] = 0;
	else if (keycode == MLX_KEY_SHIFT_LEFT)
		p->keypress[KEY_SHIFT] = 0;
	//key_press_hook(p->keypress[LAST_KEY_PRESS], c);
	return (1);
}
