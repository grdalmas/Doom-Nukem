/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:12:39 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/02 06:36:11 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void			spawn(t_struct *p)
{
	int i;

	if (((int)p->c->p_x != 10 || (int)p->c->p_x != 9) && (int)p->c->p_y != 7)
		p->porte[1].poort = 1;
	i = 10;
	while (i < 16)
	{
		p->sprite[i].k = 8;
		p->sprite[i].pv = 10;
		i++;
	}
	p->s = -1;
	if ((int)p->c->p_x == 7.5 && (int)p->c->p_y == 10.5)
		p->porte[1].poort = 0;
}

void		alive(t_struct *p)
{
	int i;
	int alldead;

	alldead = 1;
	i = 0;
	while (i < 18)
	{
		if (p->sprite[i].pv <= 0)
			p->sprite[i].k = 6;
		if (p->sprite[i].k != 6 && i > 4 && i < 10)
			alldead = 0;
		i++;
	}
	if (alldead == 1 && p->weapon.id != 2)
	{
		p->sprite[19].k = 5;
	}
	if (p->sprite[17].k == 6)
		p->trumplive = 0;
}

