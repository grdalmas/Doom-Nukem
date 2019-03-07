/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <tifuret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:33:39 by tifuret           #+#    #+#             */
/*   Updated: 2019/03/07 20:59:46 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void			skybox3(t_struct *p)
{
	if (p->skyt >= 0 && p->skyt < 90)
		p->skytex = 111;
	else if (p->skyt >= 90 && p->skyt < 180)
		p->skytex = 112;
	else if (p->skyt >= 180 && p->skyt < 270)
		p->skytex = 113;
	else if (p->skyt >= 270 && p->skyt < 360)
		p->skytex = 114;
}

static void			skybox2(t_struct *p)
{
	p->skytex = 0;
	p->skyt = atan2(p->c->r_dir_x, p->c->r_dir_y) * 180 / PI;
	while (p->skyt < 0.0)
		p->skyt += 360.0;
	while (p->skyt >= 360.0)
		p->skyt -= 360.0;
	if (p->skyt >= 0 && p->skyt < 90)
		p->skytex = 107;
	else if (p->skyt >= 90 && p->skyt < 180)
		p->skytex = 108;
	else if (p->skyt >= 180 && p->skyt < 270)
		p->skytex = 109;
	else if (p->skyt >= 270 && p->skyt < 360)
		p->skytex = 110;
}

void			skybox(t_struct *p, int y, int x)
{
	int			tx;
	int			ty;
	int			tmp_y;

	skybox2(p);
	tx = ((int)((p->skyt / 90.0) * (double)p->tex[p->skytex].width)
			% p->tex[p->skytex].width);
	while (y-- >= 0 - p->h)
	{
		if (y < 0)
		{
			skybox3(p);
			tmp_y = -y;
			ty = (int)(((double)tmp_y / ((double)((HEIGHT)) / 2.1))
					* p->tex[p->skytex].height) % (p->tex[p->skytex].height);
			ty = 639 - ty;
		}
		else
			ty = (int)(((double)y / ((double)((HEIGHT)) / 2.1))
					* p->tex[p->skytex].height) % (p->tex[p->skytex].height);
		color_text_sky(p, tx, ty);
		draw_pixel2(p, p->img_str2, x, y + p->h);
	}
}
