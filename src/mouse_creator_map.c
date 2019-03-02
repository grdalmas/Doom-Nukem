/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_creator_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 08:16:58 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/02 08:51:16 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static void		choose_text(t_struct *p, int button, int x, int y)
{
	if (button == 2)
	{
		p->edit = 0;
		p->edits = -1;
	}
	else if (x > 1183 && x < 1183 + 76 && y > 135 && y < 135 + 76)
		p->edit = 8;
	else if (x > 1280 && x < 1280 + 76 && y > 130 && y < 214)
		p->edit = 9;
	else if (x > 1383 && x < 1383 + 76 && y > 135 && y < 135 + 76)
		p->edit = 10;
	else if (x > 1493 && x < 1496 + 76 && y > 140 && y < 214)
		p->edit = 11;
	else if (x > 1183 && x < 1183 + 76 && y > 247 && y < 247 + 76)
		p->edit = 23;
	else if (x > 1280 && x < 1357 && y > 240 && y < 240 + 76)
		p->edit = 7;
	else if (x > 1380 && x < 1457 && y > 240 && y < 240 + 76)
		p->edit = 4;
	else if (x > 1480 && x < 1557 && y > 240 && y < 240 + 76)
		p->edit = 121;
	if (p->edit != 0)
		p->edits = -1;
}

static void		choose_sprite(t_struct *p, int x, int y)
{
	if (x > 1190 && x < 1250 && y > 444 && y < 512)
		p->edits = 20;
	else if (x > 1290 && x < 1350 && y > 444 && y < 512)
		p->edits = 21;
	else if (x > 1390 && x < 1450 && y > 444 && y < 512)
		p->edits = 22;
	else if (x > 1490 && x < 1550 && y > 444 && y < 512)
		p->edits = 23;
	if (p->edits > 19)
		p->edit = 0;
	if (x > 1357 && x < 1396 && y > 600 && 638 > y)
	{
		if (p->edit > 0 && p->edit != 121)
			p->floor = p->edit;
		else
			p->floor = 7;
	}
}

static void		change_map(t_struct *p, int x, int y, int i)
{
	if (x >= 0 && x <= 14 && y >= 0 && y <= 14 && p->edit != 0)
	{
		if (p->edit == 121)
		{
			if (x != 0 && x != 14 && y != 0 && y != 14)
				p->map[4][y][x] = 0;
		}
		else
		{
			i = 19;
			while (++i < 24)
			{
				if (p->sprite[i].x == y && p->sprite[i].y == x)
					break ;
			}
			if (i == 24)
			{
				if (y == 13 || y == 14)
					i = (x == 7) ? 100 : 0;
				if (i != 100)
					p->map[4][y][x] = p->edit;
			}
		}
	}
}


void		mouse_creator_map(t_struct *p, int button, int x, int y)
{
		choose_text(p, button, x, y);
		choose_sprite(p, x, y);
		x = (x - 496) / 40;
		y = (y - 37) / 40;
		if (x >= 0 && x <= 14 && y >= 0 && y <= 14 && p->edit == 0)
		{
			if (p->edits > 19)
			{
				if (p->map[4][y][x] == 0)
				{
					p->sprite[p->edits].k = 4;
					p->sprite[p->edits].y = (int)x + 0.5;
					p->sprite[p->edits].x = (int)y + 0.5;
				}
			}
		}
		change_map(p, x, y, 0);
}
