/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 03:10:31 by cmartine          #+#    #+#             */
/*   Updated: 2019/02/22 04:31:32 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void		which_text(t_struct *p)
{
	if (p->map[p->k][p->c->map_x % 18][p->c->map_y % 18] > 1)
		p->tid = p->map[p->k][p->c->map_x % 18][p->c->map_y % 18];
	else if (p->map[p->k][p->c->map_x % 18][p->c->map_y % 18] == 1)
	{
		if (p->c->side == 0 && p->c->r_dir_x > 0)
			p->tid = 9;
		else if (p->c->side == 0 && p->c->r_dir_x < 0)
			p->tid = 10;
		else if (p->c->side == 1 && p->c->r_dir_y > 0)
			p->tid = 11;
		else
			p->tid = 8;
	}
	if (p->tid == 5 && p->s > 0)
		p->tid = 18;
	if (p->k == 0 && p->tid == 22 && p->elev == 0)
	{
			p->tid = 117;
			p->porte[0].poort = 1;
	}
	/*if (p->k == 2 && p->tid != 24 && p->tid != 13)
		p->tid = 23;
	if (p->k == 7 && p->tid != 22)
		p->tid = 102;
	if (p->k == 9 && p->tid != 22 && p->tid != 115)
		p->tid = 4;
*/
}

void		which_textf(t_struct *p)
{
/*	if (p->map[p->k][p->c->map_x % 18][p->c->map_y % 18] == 1)
	{
		if (p->c->side == 0 && p->c->r_dir_x > 0)
			p->tid = 9;
		else if (p->c->side == 0 && p->c->r_dir_x < 0)
			p->tid = 10;
		else if (p->c->side == 1 && p->c->r_dir_y > 0)
			p->tid = 11;
		else
			p->tid = 8;
	}
*/	//else if (p->map[p->k][p->c->map_x % 18][p->c->map_y % 18] > 1)
	//	p->tid = p->map[p->k][p->c->map_x % 18][p->c->map_y % 18];
		p->tid = 7;
	if (p->k == 5)
		p->tid = 6;
	else if (p->k == 2 && p->tid != 24 && p->tid != 13)
		p->tid = 23;
	else if (p->k == 1)
		p->tid = 65;
	else if (p->k == 4)
		p->tid = 67;
	else if (p->k == 3)
		p->tid = 90;
	else if (p->k == 7)
		p->tid = 102;
	else if (p->k == 9 && p->tid != 115)
		p->tid = 4;
}

void			color_text2(t_struct *p, int col, int line, double ratio)
{
	ratio = 1 - ratio * 0.8;
	if (col + line + 3 < 262144)
	{
		p->color.r = (unsigned char)((ratio) * (unsigned char)(p->tex[p->tid].img_str[col + line]));
		p->color.g = (unsigned char)((ratio) * (unsigned char)(p->tex[p->tid].img_str[col + line + 1]));
		p->color.b = (unsigned char)((ratio) * (unsigned char)(p->tex[p->tid].img_str[col + line + 2]));
}
}

void			color_text(t_struct *p, int col, int line, double ratio)
{
	which_text(p);
	col = col * BPP;
	line = line * 1024;
	ratio = 1 - ratio * 0.8;
	if (col + line + 3 < 262144)
	{
		p->color.r = (unsigned char)((ratio) * (unsigned char)(p->tex[p->tid].img_str[col + line]));
		p->color.g = (unsigned char)((ratio) * (unsigned char)(p->tex[p->tid].img_str[col + line + 1]));
		p->color.b = (unsigned char)((ratio) * (unsigned char)(p->tex[p->tid].img_str[col + line + 2]));
}
}

void			color_textf(t_struct *p, int col, int line, double ratio)
{
	which_textf(p);
	col = col * BPP;
	line = line * 1024;
	ratio = 1 - ratio * 0.8;
	if (col + line + 3 < 262144)
	{
		p->color.r = (unsigned char)((ratio) * (unsigned char)(p->tex[p->tid].img_str[col + line]));
		p->color.g = (unsigned char)((ratio) * (unsigned char)(p->tex[p->tid].img_str[col + line + 1]));
		p->color.b = (unsigned char)((ratio) * (unsigned char)(p->tex[p->tid].img_str[col + line + 2]));
}
}

static void		floor_casting(t_struct *p, int x, int y, int z)
{
	double	distance;
	double	tmp_fl_x;
	double	tmp_fl_y;
	int		tex_x;
	int		tex_y;

	y = p->c->y_end;
	z = HEIGHT - y;
	p->c->what = 1;
	while (y++ < HEIGHT + abs(p->h)  && z-- > 0 - abs(p->h))
	{
		distance = (double)HEIGHT / (2.0 * ((double)y ) - (double)HEIGHT);
		p->c->ra = distance / p->c->wall_dist;
		if (p->k != 7)
		{
			p->c->shadow = distance * 0.25;
			if (p->c->shadow > 1)
				p->c->shadow = 1;
		}
		tmp_fl_x = p->c->ra * p->c->floor_x + (1.0 - p->c->ra) * p->c->p_x;
		tmp_fl_y = p->c->ra * p->c->floor_y + (1.0 - p->c->ra) * p->c->p_y;
		tex_x = (int)(tmp_fl_x * p->tex[p->tid].width) % p->tex[p->tid].width;
		tex_y = (int)(tmp_fl_y * p->tex[p->tid].height) % p->tex[p->tid].height;
		color_textf(p, tex_x, tex_y, p->c->shadow );
		tex_y = y - HEIGHT + abs(p->h);
		//	printf("%i ",tex_y);
		draw_pixel2(p, p->img_str2, x, y + p->h);
		//	write(1,"a",1);
		if (p->k != 9)
			draw_pixel2(p, p->img_str2, x, z + p->h);
		//	write(1,"b",1);
	}
	p->c->what = 0;
}

static void		draw_floor_3d(t_struct *p)
{
	if (p->c->side == 0 && p->c->r_dir_x > 0)
	{
		p->c->floor_x = p->c->map_x;
		p->c->floor_y = p->c->map_y + p->c->offset;
	}
	else if (p->c->side == 0 && p->c->r_dir_x < 0)
	{
		p->c->floor_x = p->c->map_x + 1.0;
		p->c->floor_y = p->c->map_y + p->c->offset;
	}
	else if (p->c->side == 1 && p->c->r_dir_y > 0)
	{
		p->c->floor_x = p->c->map_x + p->c->offset;
		p->c->floor_y = p->c->map_y;
	}
	else
	{
		p->c->floor_x = p->c->map_x + p->c->offset;
		p->c->floor_y = p->c->map_y + 1.0;
	}
}

int			hodor(t_struct *p)
{
	int	tex_x;
	if (p->tid == p->porte[p->dodor].zip)
		tex_x = (int)((p->c->offset * 256 >= 256 ? 255 : (p->c->offset - p->porte[p->dodor].open)  * 256));
	else
		tex_x = (int)((p->c->offset * 256 >= 256 ? 255 : p->c->offset * 256));
	return(tex_x);
}

void			color_text_sky(t_struct *p, int col, int line, int tex)
{

	col = col * BPP;
	line = line * (2556); // p->tex[tex].height * 4;
	//	}
	if (col + line + 3 < 1633284 /* p->tex[tex].width * 4 * p->tex[tex].height*/ && col >= 0 && line > 0)
		//	printf("%i ",col);
		//	if (col + line + 3 < 262144 && col >= 0 && line >= 0  )
	{
		p->color.r = (unsigned char)(p->tex[tex].img_str[col + line]);
		//		p->color.r = (unsigned char)((1 - ratio * 0.8) * p->color.r);
		p->color.g = (unsigned char)(p->tex[tex].img_str[col + line + 1]);
		//		p->color.g = (unsigned char)((1 - ratio * 0.8) * p->color.g);
		p->color.b = (unsigned char)(p->tex[tex].img_str[col + line + 2]);
		//		p->color.b = (unsigned char)((1 - ratio * 0.8) * p->color.b);
		//		p->color.a = (unsigned char)(p->tex[p->tid].img_str[col + line + 3]);
	}
}

void			skybox(t_struct *p, int y, int x)
{
	double t;
	int		tex = 0;
	int        tx;
	int        ty;
	int			tmp_y;
	
	t = atan2(p->c->r_dir_x,p->c->r_dir_y) * 180 / PI;
	while (t < 0.0)
		t += 360.0;
	while (t >= 360.0)
		t -= 360.0;
	if (t >= 0 && t < 90)
		tex = 107;
	else if (t >= 90 && t < 180)
		tex = 108;
	else if (t >= 180 && t < 270)
		tex = 109;
	else if (t >= 270 && t < 360)
		tex = 110;
	tx = ((int)((t / 90.0) * (double)p->tex[tex].width) % p->tex[tex].width);

	//	printf("tx : %d\n", tx);
	//	printf("wt : %d\n", p->tex[107].width);
//	printf("tx : %d\n", p->tex[107].height);

	while (y-- >= 0 - p->h)
	{	
		if (y  < 0)
		{
			if (t >= 0 && t < 90)
				tex = 111;
			else if (t >= 90 && t < 180)
				tex = 112;
			else if (t >= 180 && t < 270)
				tex = 113;
			else if (t >= 270 && t < 360)
				tex = 114;
			tmp_y = - y;
			ty = (int)(((double)tmp_y / ((double)((HEIGHT)) / 2.1))
					* p->tex[tex].height) % (p->tex[tex].height);
			ty = 639 - ty;
		}
		else
			ty = (int)(((double)y / ((double)((HEIGHT)) / 2.1))
					* p->tex[tex].height) % (p->tex[tex].height);
		color_text_sky(p, tx, ty, tex);
		draw_pixel2(p, p->img_str2, x, y +p->h);
	}
}

void			draw_wall_3d(t_struct *p, int x, int y, int wall_height)
{
	int		tex_x;
	int		tex_y;
	//	double	distance;

	wall_height = abs((int)(HEIGHT / p->c->wall_dist));
	y = (int)(-wall_height / 2 + HEIGHT / 2) + p->h;
	p->c->y_end = (int)(wall_height / 2 + HEIGHT / 2);
	if (y < 0)
		y = 0;

	if (p->k == 9)
		skybox(p, y - p->h, x); // - (p->c->y_end / 2));
	tex_x = hodor(p);
	draw_floor_3d(p);
	floor_casting(p, x, 0, 0);
	//	if (p->k != 7)    A REMETTRE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
	if (p->k != 7)
	{
		p->c->shadow = ((double)HEIGHT / (2.0 * (double)p->c->y_end - (double)HEIGHT)) * 0.25;
		//j aimerai bien bidouiller ca si j ai le temps
		//p->c->shadow = distance * 0.25;
		if (p->c->shadow > 1)
			p->c->shadow = 1;
	}
	if (p->c->y_end > HEIGHT - p->h)
		p->c->y_end = HEIGHT - 1 - p->h;
	p->c->y_end += p->h;
	while (y++ <= p->c->y_end )
	{
		tex_y = (y * 2 - HEIGHT + wall_height - p->h * 2)
			* (p->tex[p->tid].height / 2) / wall_height;
		color_text(p, tex_x, tex_y, p->c->shadow);
		draw_pixel2(p, p->img_str2, x, y);
	}
}
