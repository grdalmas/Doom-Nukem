/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:29:26 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/04 20:32:50 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void			keypress2(int keycode, t_struct *p)
{
	if (keycode == MLX_KEY_C)
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
	else if (keycode == MLX_KEY_PAD_1)
		p->keypress[KEY_PAD_1] = 1;
	else if (keycode == MLX_KEY_PAD_2)
		p->keypress[KEY_PAD_2] = 1;
	else if (keycode == MLX_KEY_PAD_3)
		p->keypress[KEY_PAD_3] = 1;
	else if (keycode == MLX_KEY_PAD_4)
		p->keypress[KEY_PAD_4] = 1;
	else
		keypress3(keycode, p);
}

int				keypress(int keycode, void *d)
{
	t_struct *p;

	if (!(p = (t_struct*)d))
		return (0);
	if (keycode == MLX_KEY_ESCAPE)
		close_window(p);
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
	else
		keypress2(keycode, p);
	return (1);
}

void			keyrelease3(int keycode, t_struct *p)
{
	if (keycode == MLX_KEY_4)
		p->keypress[KEY_4] = 0;
	else if (keycode == MLX_KEY_5)
		p->keypress[KEY_5] = 0;
	else if (keycode == MLX_KEY_PAD_1)
		p->keypress[KEY_PAD_1] = 0;
	else if (keycode == MLX_KEY_PAD_2)
		p->keypress[KEY_PAD_2] = 0;
	else if (keycode == MLX_KEY_PAD_3)
		p->keypress[KEY_PAD_3] = 0;
	else if (keycode == MLX_KEY_PAD_4)
		p->keypress[KEY_PAD_4] = 0;
	else if (keycode == MLX_KEY_PAD_5)
		p->keypress[KEY_PAD_5] = 0;
	else if (keycode == MLX_KEY_SHIFT_LEFT)
		p->keypress[KEY_SHIFT] = 0;
}

void			keyrelease2(int keycode, t_struct *p)
{
	if (keycode == MLX_KEY_S)
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
		p->keypress[KEY_R] = 1;
	else if (keycode == MLX_KEY_1)
		p->keypress[KEY_1] = 0;
	else if (keycode == MLX_KEY_2)
		p->keypress[KEY_2] = 0;
	else if (keycode == MLX_KEY_3)
		p->keypress[KEY_3] = 0;
	keyrelease3(keycode, p);
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
	else if (keycode == MLX_KEY_E && p->menu != 2 && p->menu != 4)
	{
		if (p->menu == 3)
			p->menu = -1;
		p->keypress[KEY_E] = 0;
		take_object(p);
	}
	else
		keyrelease2(keycode, p);
	return (1);
}
