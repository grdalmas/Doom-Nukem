/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 03:42:36 by bbataini          #+#    #+#             */
/*   Updated: 2019/02/28 05:10:56 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"
/*
int				*fill_color(int *str, int x, int y, int c)
{
	int w;
	int h;

	w = WIDTHMAP;
	h = HEIGHTMAP;
	if (str[x + w * y] != c && x + w * y < w * h)
	{
		str[x + w * y] = c;
		if (str[x + 1 + w * y] != c && x + 1 + w * y < w * h)
			str = fill_color(str, x + 1, y, c);
		if (str[x - 1 + w * y] != c)
			str = fill_color(str, x - 1, y, c);
		if (str[x + w * (y + 1)] != c && x + w * (y + 1) < w * h)
			str = fill_color(str, x, y + 1, c);
		if (str[x + w * (y - 1)] != c && x + w * (y - 1) < w * h)
			str = fill_color(str, x, y - 1, c);
	}
	return (str);
}

static int		laby_bonus(t_struct *p, int i, int j)
{
	int c;

	c = 0xFFFFFF;
	if (p->map[p->k][j][i] == 68)
		c = 0x33FFF6;
	if (p->map[p->k][j][i] == 66)
		c = 0xFFFF33;
	if (p->map[p->k][j][i] == 12)
		c = 0x33FF49;
	if (p->map[p->k][j][i] == 13)
		c = 0xFF33DD;
	return (c);
}
*/
static void		labyrinthe(t_struct *p, int x, int y, int cb)
{
	int i;
	int j;

	j = -1;
	while (++j < 15)
	{
		i = -1;
		while (++i < 15)
		{
//			if (p->map[4][j][i] >= 1)
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
//				p->c->x1 = WIDTH / 2;      MET UNE LIGNE AU MILIEU...
//				draw_line2(0, WIDTH / 2, HEIGHT, p);
			}
		}
	}
				p->c->x1 = x + cb + 300;
				draw_line2(y, x + cb + 300, y + cb, p);
				p->c->x1 = x + 300;
				draw_line2(y, x + cb + 300, y, p);
				draw_line2(y + cb, x + cb + 300, y + cb, p);
				draw_line2(y, x + 300, y + cb, p);
}

void		*inverse_map(t_struct *p)
{
	int i;
	int j;
	int k;
	int *tmp;

	i = 0;
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
		while (j++ < 15)
			p->map[4][i][j] = tmp[j];
		free(tmp);
		i++;
	}
	return (0);
}

void			minimap2(t_struct *p)
{
//	inverse_map(p);
	labyrinthe(p, 0, 0, 40);
//	sprite(p, 0xFFFF, 0, 5);
	p->c->x1 = p->c->p_x * (40);
	draw_line(p->c->p_y * (40), p->c->p_x * (40)
			+ p->c->dir_x * (40), p->c->p_y * (40) + p->c->dir_y * (40), p);
}
