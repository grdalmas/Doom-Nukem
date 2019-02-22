/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:35:25 by grdalmas          #+#    #+#             */
/*   Updated: 2019/02/22 04:31:57 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"



void	draw_game(void *gm)
{
	t_struct	*p;
	int i;

	i = 0;
	if (!(p = (t_struct*)gm))
		return ;
	if (p->temp < 80)
		p->temp++;
	else
		p->temp = 0;
	p->time.update(&p->time);
	key_press_hook(p);
	raycasting(p, 0, 0);
	mlx_string_put(p->mlx_ptr, p->w_ptr, 1595, 5, 0xffffff, ft_itoa((int)p->time.fps));
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
	//	printf("%i ",p->porte[i].poort);
		if (p->porte[i].poort == 1 && p->porte[i].open > 0)
			p->porte[i].open -= p->porte[i].spd;
		if (p->porte[i].poort == 0 && p->porte[i].open <= 1)
			p->porte[i].open += p->porte[i].spd;
		i++;
	}
	//if (p->k == 7)
	//printf("%i ", (int)p->c->p_y);
	if (p->keypress[KEY_E] == 1 && p->k == 8 && (int)p->c->p_x == 2 && (int)p->c->p_y == 7 && p->s < 0)
	{
		p->s = 0;
	}
		if (p->s >= 0)
		{
		p->porte[1].poort = 0;
			p->s++;
			mlx_string_put(p->mlx_ptr, p->w_ptr, 691, 50, 0xffffff, ft_itoa((int)(11 - p->s/20)));
			if (p->s >= 200)
				spawn(p);
		}
		alive(p);
		weapon(p);
		if (p->cure == 0)
			p->life -= 0.03;

	//printf("%f ", atan2(p->c->dir_x,p->c->dir_y) * 180 / PI);
}
