/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   against_glitch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 10:17:00 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/05 04:54:34 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static int				against_glitch_straff2(t_struct *p, int move, double s)
{
	if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) - 1] > 0
			&& (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y))] > 0))
	{
		if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y)) - 1] == 0)
		{
			if ((int)(p->c->p_x + p->c->plane_x * s) == (int)p->c->p_x - 1
					|| (int)(p->c->p_y + p->c->plane_y * s) == p->c->map_y - 1)
				move = 1;
		}
	}
	if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y))] > 0
			&& (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) + 1] > 0))
	{
		if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y)) + 1] == 0)
		{
			if ((int)(p->c->p_x + p->c->plane_x * s) == (int)p->c->p_x - 1
					|| (int)(p->c->p_y + p->c->plane_y * s) == p->c->map_y + 1)
				move = 1;
		}
	}
	return (move);
}

int				against_glitch_straff(t_struct *p, int move, double s)
{
	if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y))] == 0)
	{
		if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) + 1] > 0
				&& (p->map[p->k][(int)((p->c->p_x)) + 1][p->c->map_y] > 0))
		{
			if (p->map[p->k][(int)((p->c->p_x)) + 1][p->c->map_y + 1] == 0)
			{
				if ((int)(p->c->p_x + p->c->plane_x * s) == (int)p->c->p_x + 1
					|| (int)(p->c->p_y + p->c->plane_y * s) == p->c->map_y + 1)
					move = 1;
			}
		}
	}
	if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) - 1] > 0
			&& (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y))] > 0))
	{
		if (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y)) - 1] == 0)
		{
			if ((int)(p->c->p_x + p->c->plane_x * s) == (int)p->c->p_x - 1
					|| (int)(p->c->p_y + p->c->plane_y * s) == p->c->map_y - 1)
				move = 1;
		}
	}
	move = against_glitch_straff2(p, move, s);
	return (move);
}

static int				against_glitch2(t_struct *p, int move, double s)
{
	if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) - 1] > 0
			&& (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y))] > 0))
	{
		if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y)) - 1] == 0)
		{
			if ((int)(p->c->p_x + p->c->dir_x * s) == (int)p->c->p_x - 1
					|| (int)(p->c->p_y + p->c->dir_y * s) == p->c->map_y - 1)
				move = 1;
		}
	}
	if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y))] > 0
			&& (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) + 1] > 0))
	{
		if (p->map[p->k][(int)((p->c->p_x)) - 1][(int)((p->c->p_y)) + 1] == 0)
		{
			if ((int)(p->c->p_x + p->c->dir_x * s) == (int)p->c->p_x - 1
					|| (int)(p->c->p_y + p->c->dir_y * s) == (int)p->c->p_y + 1)
				move = 1;
		}
	}
	return (move);
}

int				against_glitch(t_struct *p, int move, double s)
{
	if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y))] == 0)
	{
		if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) + 1] > 0
				&& (p->map[p->k][(int)((p->c->p_x)) + 1][(p->c->map_y)] > 0))
		{
			if (p->map[p->k][(int)((p->c->p_x)) + 1][p->c->map_y + 1] == 0)
			{
				if ((int)(p->c->p_x + p->c->dir_x * s) == (int)p->c->p_x + 1
					|| (int)(p->c->p_y + p->c->dir_y * s) == p->c->map_y + 1)
					move = 1;
			}
		}
	}
	if (p->map[p->k][(int)((p->c->p_x))][(int)((p->c->p_y)) - 1] > 0
			&& (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y))] > 0))
	{
		if (p->map[p->k][(int)((p->c->p_x)) + 1][(int)((p->c->p_y)) - 1] == 0)
		{
			if ((int)(p->c->p_x + p->c->dir_x * s) == (int)p->c->p_x - 1
					|| (int)(p->c->p_y + p->c->dir_y * s) == p->c->map_y - 1)
				move = 1;
		}
	}
	move = against_glitch2(p, move, s);
	return (move);
}
