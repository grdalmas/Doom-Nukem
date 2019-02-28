/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:35:25 by grdalmas          #+#    #+#             */
/*   Updated: 2019/02/28 22:55:22 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void	draw_game(void *gm)
{
	t_struct	*p;
	int i;

	char *s;
	if (!(p = (t_struct*)gm))
		return ;
	p->time.update(&p->time);
	i = 0;
	if (p->temp < 80)
		p->temp++;
	else
		p->temp = 0;
	if (p->menu == 1)
	{
	key_press_hook(p);
	raycasting(p, 0, 0);
	s = ft_itoa((int)p->time.fps);
		mlx_string_put(p->mlx_ptr, p->w_ptr, 1595, 5, 0xffffff, s);
		free(s);
	if (p->keypress[KEY_R] == 1 && p->weapon.reload < 12)
		p->weapon.reload += 1;
	else
		p->keypress[KEY_R] = 0;
	if (p->k == 5 || p->k == 8)
		sprite_move(p);
	else if (p->k == 0 || p->k == 9)
		rotrump(p);
	while (i < NUMPORTE)
	{
		if (p->porte[i].poort == 1 && p->porte[i].open > 0)
			p->porte[i].open -= p->porte[i].spd;
		if (p->porte[i].poort == 0 && p->porte[i].open <= 1)
			p->porte[i].open += p->porte[i].spd;
		i++;
	}
	if (p->keypress[KEY_E] == 1 && p->k == 8 && (int)p->c->p_x == 2 && (int)p->c->p_y == 7 && p->s < 0)
	{
		p->s = 0;
	}
		if (p->s >= 0)
		{
		p->porte[1].poort = 0;
			p->s++;
			char *str;
			str = ft_itoa((int)(11 - p->s / 20));
			mlx_string_put(p->mlx_ptr, p->w_ptr, 691, 50, 0xffffff, str);
			free(str);
			if (p->s >= 200)
				spawn(p);
		}
		alive(p);
		weapon(p);
		if (p->cure == 0 &&  p->k == 9)
			p->life -= 4;
		else if (p->cure == 0)
			p->life -= 0.02;


	}
	else if (p->menu == 2) // GAME OVER MODE
	{
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[119].img_ptr, 340, 0);
		s = ft_itoa(p->temp);
		mlx_string_put(p->mlx_ptr, p->w_ptr, 900, 500, 0xffffff, "Retour au menu :");
		mlx_string_put(p->mlx_ptr, p->w_ptr, 1080, 500, 0xffffff, s);
		free(s);
	}
	else if (p->menu == 3) // MAP EDITOR
	{
		if (p->edit != 0)
			img_to_img(p, p->mousex - 350, p->mousey - 20, p->edit, 0.15625);
		else if (p->edits > 19)
			img_to_img(p, p->mousex - 350, p->mousey - 20, p->sprite[p->edits].id, 0.15625);
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->img_ptr2, 340, 0);
//		hookcreator(p);
		creator_map(p);
	}
	//else if (p->menu == 4)
	//	draw_main_menu(p);
}
