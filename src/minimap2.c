/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <tifuret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 03:42:36 by bbataini          #+#    #+#             */
/*   Updated: 2019/03/07 20:59:01 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		floor_(t_struct *p, int x, int y, int cb)
{
	p->c->x1 = x + cb + 300;
	draw_line2(y, x + cb + 300, y + cb, p);
	p->c->x1 = x + 300;
	draw_line2(y, x + cb + 300, y, p);
	draw_line2(y + cb, x + cb + 300, y + cb, p);
	draw_line2(y, x + 300, y + cb, p);
	mlx_string_put(p->mlx_ptr, p->w_ptr, x + cb + 606, y + 10, 0xffffff, "SOL");
}

static void		labyrinthee(t_struct *p, int x, int y, int cb)
{
	int i;
	int j;

	j = -1;
	while (++j < 15)
	{
		i = -1;
		while (++i < 15)
		{
			p->c->colo = 0x5A5E6B;
			x = j * (40) + 155;
			y = i * (40) + 35;
			p->c->x1 = x + cb;
			draw_line2(y, x + cb, y + cb, p);
			p->c->x1 = x;
			draw_line2(y, x + cb, y, p);
			draw_line2(y + cb, x + cb, y + cb, p);
			draw_line2(y, x, y + cb, p);
		}
	}
	floor_(p, x, y, cb);
}

void			*inverse_map(t_struct *p, int i, int j, int k)
{
	int *tmp;

	while (i < 15)
	{
		if (!(tmp = (int *)malloc(sizeof(int) * 16)))
			return (NULL);
		j = 14;
		k = 0;
		while (j >= 0)
		{
			tmp[k] = p->map[4][i][j];
			j--;
			k++;
		}
		j = 0;
		while (j < 15)
		{
			p->map[4][i][j] = tmp[j];
			j++;
		}
		free(tmp);
		i++;
	}
	return (0);
}

void			minimap2(t_struct *p)
{
	labyrinthee(p, 0, 0, 40);
	p->c->x1 = p->c->p_x * (40);
	draw_line(p->c->p_y * (40), p->c->p_x * (40)
			+ p->c->dir_x * (40), p->c->p_y * (40) + p->c->dir_y * (40), p);
}
