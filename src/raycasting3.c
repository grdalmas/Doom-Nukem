/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:38:19 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/04 21:40:00 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

t_sprite	*init_sprite(void)
{
	static t_sprite sprite[NUMSPRITE] = {
		{2, 0, 7.5, 7.5, 1}, /* tools */
		{8, 1, 7.5, 9.5, 10}, /* medikit */
		{0, 51, 9.5, 2.5, 1000}, /* computer */
		{1, 3, 3, 3, 1}, /* map */
		{5, 82, 7.5, 2, 10},  /* se raproche du player 4 */
		{5, 82, 1.5, 10.5, 10}, /* se rapproche du player 5 */
		{5, 82, 3.5, 11.5, 10}, /* se rapproche du player 6 */
		{5, 82, 7.5, 1.5, 10}, /* se rapproche du player 7 */
		{5, 82, 9.5, 13.5, 10}, /* se rapproche du player 8 */
		{5, 82, 7.5, 3.5, 10}, /* se rapproche du player 9 */
		{8, 119, 2.5, 2.5, 10}, /* mechant 10 */
		{8, 119, 4, 4, 10},
		{8, 119, 13, 13, 10},
		{8, 119, 13, 2.5, 10},
		{8, 119, 7.5, 2, 10},
		{8, 119, 7.5, 12.5, 10}, /* mechant 15 */
		{7, 86, 4.5, 3.5, 1}, /* tronconneuse 16 ! */
		{0, 14, 11, 11, 10}, /* trump 17 */
		{9, 14, 7.5, 1.5, 10}, /* trump 18 */
		{6, 95, 7.5, 2, 1}, /* pompe 19 */
		{6, 51, 0, 0, 0}, /*editeur */
		{6, 33, 0, 0, 0},
		{6, 46, 0, 0, 0},
		{6, 50, 0, 0, 0}, /* editeur */
		{1, 33, 7.5, 7.5,1}, /* 22 statue */
	};
	return (sprite);
}

void		draw_transparent_wall_3(t_struct *p, int tex)
{
	if (p->hit == 2)
		tex = 6;
	else if (p->hit == 3 && p->s == -1)
	{
		tex = 5;
		p->tid = 5;
	}
	else if (p->hit == 3 && p->s >= 0)
	{
		tex = 18;
		p->tid = 18;
	}
}

void		draw_transparent_wall_2(t_struct *p, int x, int y, int wall_height, int col, int tex_x)
{
	int		tex;
	int		tex_y;
	int		line;

	tex = 1;
	draw_transparent_wall_3(p, tex);
	while (y++ <= p->c->y_end)
	{
		tex_y = (y * 2 - HEIGHT + wall_height - p->h * 2)
			* (p->tex[tex].height / 2) / wall_height;
		line = tex_y * 1024;
		if (col + line + 3 < 262144 && col >= 0 && line >= 0)
			p->color.a = p->tex[tex].img_str[col + line + 3];
		if (p->color.a == 0)
		{
			color_text(p, tex_x, tex_y, p->c->shadow);
			draw_pixel2(p, p->img_str2, x, y);
		}
	}
}

void		draw_transparent_wall(t_struct *p, int x, int y, int wall_height)
{
	int		tex_x;
	int		col;

	wall_height = abs((int)(HEIGHT / p->c->wall_dist));
	y = (int)(-wall_height / 2 + HEIGHT / 2) + p->h;
	p->c->y_end = (int)(wall_height / 2 + HEIGHT / 2);
	if (y < 0)
		y = 0;
	tex_x = (int)((p->c->offset * 256 >= 256 ? 255 : p->c->offset * 256));
	col = tex_x * BPP;
	p->c->shadow = ((double)HEIGHT / (2.0 * (double)p->c->y_end
				- (double)HEIGHT)) * 0.25;
	if (p->c->shadow > 1)
		p->c->shadow = 1;
	if (p->c->y_end > HEIGHT - p->h)
		p->c->y_end = HEIGHT - 1 - p->h;
	p->c->y_end += p->h;
	draw_transparent_wall_2(p, x, y, wall_height, col, tex_x);
}
