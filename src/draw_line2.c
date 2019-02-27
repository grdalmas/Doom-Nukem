/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 04:29:09 by cmartine          #+#    #+#             */
/*   Updated: 2019/02/27 16:51:29 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

int				*fill_color2(int *str, int x, int y, int c)
{
	int			w;
	int			h;

	w = WIDTH;
	h = HEIGHT;
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

static void		draw_case_one(int y1, int x2, int y2, t_struct *p)
{
	int			x;

	if (x2 - p->c->x1 != 0)
	{
		if (x2 < p->c->x1)
		{
			x = x2 - 1;
			while (++x <= p->c->x1 && (p->c->calc = x + (WIDTH * (y1 + (y2 - y1)
				* (x - p->c->x1) / (x2 - p->c->x1)))) < WIDTH * HEIGHT)
				if (p->c->calc >= 0 && x >= 0 && x < WIDTH)
					((int *)p->img_str2)[p->c->calc] = p->c->colo;
		}
		else
		{
			x = p->c->x1 - 1;
			while (++x <= x2 && (p->c->calc = (x + (WIDTH * (y1 + (y2 - y1)
				* (x - p->c->x1) / (x2 - p->c->x1))))) < WIDTH * HEIGHT)
			{
				if (p->c->calc >= 0 && x >= 0 && x < WIDTH)
					((int *)p->img_str2)[p->c->calc] = p->c->colo;
			}
		}
	}
}

static void		draw_case_two(int y1, int x2, int y2, t_struct *p)
{
	int			y;
	int			calc;

	if (y2 < y1)
	{
		y = y2 - 1;
		while (++y <= y1 && (calc = (p->c->x1 + (x2 - p->c->x1) * (y - y1) /
						(y2 - y1)) + (WIDTH * y)) < WIDTH * HEIGHT)
		{
			if (calc >= 0 && (p->c->x1 + (x2 - p->c->x1) * (y - y1) / (y2 - y1))
		>= 0 && (p->c->x1 + (x2 - p->c->x1) * (y - y1) / (y2 - y1)) < WIDTH)
				((int *)p->img_str2)[calc] = p->c->colo;
		}
	}
	else
	{
		y = y1 - 1;
		while (++y <= y2 && (calc = (p->c->x1 + (x2 - p->c->x1) * (y - y1) /
					(y2 - y1)) + (WIDTH * y)) < WIDTH * HEIGHT)
		{
			if (calc >= 0 && (p->c->x1 + (x2 - p->c->x1) * (y - y1) / (y2 - y1))
		>= 0 && (p->c->x1 + (x2 - p->c->x1) * (y - y1) / (y2 - y1)) < WIDTH)
				((int *)p->img_str2)[calc] = p->c->colo;
		}
	}
}

void			draw_line2(int y, int x2, int y2, t_struct *p)
{
	int			dx;
	int			dy;

	dx = abs(p->c->x1 - x2);
	dy = abs(y - y2);
	if (dx >= dy)
		draw_case_one(y, x2, y2, p);
	if (dy >= dx)
		draw_case_two(y, x2, y2, p);
}
