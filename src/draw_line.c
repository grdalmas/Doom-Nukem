/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:49:54 by cmartine          #+#    #+#             */
/*   Updated: 2019/02/27 16:43:44 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void		draw_pixel(char *img_str, int x, int y, int color)
{
	int *str;

	str = (int *)img_str;
	if (x + y * WIDTHMAP < HEIGHTMAP * WIDTHMAP && x > 0 && y > 0)
		str[x + y * (int)WIDTHMAP] = color;
}

void		draw_pixel2(t_struct *p, char *img_str, int x, int y)
{
	x = x * BPP;
	y = y * p->size_line;
	if (x + y + 4 < WHBPP && x >= 0 && y >= 0)
	{
		img_str[x + y] = (char)p->color.r;
		img_str[x + y + 1] = (char)p->color.g;
		img_str[x + y + 2] = (char)p->color.b;
	}
}

static void	draw_case_one(int y1, int x2, int y2, t_struct *p)
{
	int x;

	if (x2 - p->c->x1 != 0)
	{
		if (x2 < p->c->x1)
		{
			x = x2 - 1;
			while (++x <= p->c->x1 && (p->c->calc = x + (WIDTHMAP
				* (y1 + (y2 - y1) * (x - p->c->x1) / (x2 - p->c->x1))))
					< WIDTHMAP * HEIGHTMAP)
				if (p->c->calc >= 0 && x >= 0 && x < WIDTHMAP)
					((int *)p->img_str)[p->c->calc] = p->c->colo;
		}
		else
		{
			x = p->c->x1 - 1;
			while (++x <= x2 && (p->c->calc = (x + (WIDTHMAP * (y1 + (y2 - y1) *
				(x - p->c->x1) / (x2 - p->c->x1))))) < WIDTHMAP * HEIGHTMAP)
			{
				if (p->c->calc >= 0 && x >= 0 && x < WIDTHMAP)
					((int *)p->img_str)[p->c->calc] = p->c->colo;
			}
		}
	}
}

static void	draw_case_two(int y1, int x2, int y2, t_struct *p)
{
	int y;
	int calc;

	if (y2 < y1)
	{
		y = y2 - 1;
		while (++y <= y1 && (calc = (p->c->x1 + (x2 - p->c->x1) * (y - y1) /
						(y2 - y1)) + (WIDTHMAP * y)) < WIDTHMAP * HEIGHTMAP)
		{
			if (calc >= 0 && (p->c->x1 + (x2 - p->c->x1) * (y - y1) / (y2 - y1))
		>= 0 && (p->c->x1 + (x2 - p->c->x1) * (y - y1) / (y2 - y1)) < WIDTHMAP)
				((int *)p->img_str)[calc] = p->c->colo;
		}
	}
	else
	{
		y = y1 - 1;
		while (++y <= y2 && (calc = (p->c->x1 + (x2 - p->c->x1) * (y - y1) /
					(y2 - y1)) + (WIDTHMAP * y)) < WIDTHMAP * HEIGHTMAP)
		{
			if (calc >= 0 && (p->c->x1 + (x2 - p->c->x1) * (y - y1) / (y2 - y1))
		>= 0 && (p->c->x1 + (x2 - p->c->x1) * (y - y1) / (y2 - y1)) < WIDTHMAP)
				((int *)p->img_str)[calc] = p->c->colo;
		}
	}
}

void		draw_line(int y, int x2, int y2, t_struct *p)
{
	int dx;
	int dy;

	dx = abs(p->c->x1 - x2);
	dy = abs(y - y2);
	if (dx >= dy)
		draw_case_one(y, x2, y2, p);
	if (dy >= dx)
		draw_case_two(y, x2, y2, p);
}
