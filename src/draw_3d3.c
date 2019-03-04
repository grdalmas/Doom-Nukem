/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:46:36 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/04 16:48:22 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void			shakeshadow(t_struct *p, int i, float distance)
{
	if (i == 0)
	{
		p->c->shadow = distance * 0.25;
		if (p->c->shadow > 1)
			p->c->shadow = 1;
	}
	else
	{
		p->c->shadow = ((double)HEIGHT / (2.0 * (double)p->c->y_end
					- (double)HEIGHT)) * 0.25;
		if (p->c->shadow > 1)
			p->c->shadow = 1;
	}
}
