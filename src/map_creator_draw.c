/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 18:30:19 by grdalmas          #+#    #+#             */
/*   Updated: 2019/02/26 23:17:13 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"
/*
void	put_pixel_txt(t_coord pti, t_coord ptt, t_img *txt, t_img *image)
{
	unsigned int	pos;
	unsigned int	pos_txt;

	if (!txt || !image || !txt->data || !image->data)
		return ;
	if (pti.y >= image->size.y || pti.y < 0 || pti.x >= image->size.x
		|| pti.x < 0)
		return ;
	if (ptt.x >= txt->size.x || ptt.y >= txt->size.y || ptt.x < 0
		|| ptt.y < 0)
		return ;
		pos = (unsigned int)(pti.y * image->width)
			+ ((unsigned int)pti.x * image->octet);
	pos_txt = (unsigned int)(ptt.y * txt->width)
			+ ((unsigned int)ptt.x * txt->octet);
	if (pos > (unsigned)(image->width * WIDTH))
		return ;
	*(unsigned int*)(void*)(image->data + pos) = *(unsigned int*)
		(void*)(txt->data + pos_txt);
}

void	put_texture_on_img(t_img *dest, t_img *text)
{
	t_coord pt;
	t_coord ptt;

	pt.y = 0;
	if (!dest || !text || !dest->data || !text->data)
		return ;
	while (pt.y < dest->size.y)
	{
		pt.x = 0;
		while (pt.x < dest->size.x)
		{
			ptt.x = (text->size.x * pt.x) / dest->size.x;
			ptt.y = (text->size.y * pt.y) / dest->size.y;
			put_pixel_txt(pt, ptt, text, dest);
			pt.x++;
		}
		pt.y++;
	}
}*/
