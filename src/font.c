/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:37:42 by grdalmas          #+#    #+#             */
/*   Updated: 2019/02/26 17:00:44 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

static void	char_to_img(char c, t_coord pt, t_img *image, t_struct *p)
{
	unsigned int	pos;
	unsigned int	text_pos;
	t_coord			pt_t;
	t_coord			var;

	var.y = 0;
	var.x = BOX_X;
	if (!c || c <= 32 || pt.x + BOX_X > WIDTH || pt.y + BOX_Y > HEIGHT
		|| pt.x < 0 || pt.y < 0)
		return ;
	if ((handle_exceptions(c, &var, &pt_t)) == '6')
		handle_six(pt, image, p);
	var.y = -1;
	while (++var.y < BOX_Y && c != '6')
	{
		pos = (unsigned int)((var.y + pt.y) * image->width)
				+ ((unsigned int)pt.x * image->octet);
		text_pos = (unsigned int)((pt_t.y + var.y) * p->texture[T_FONT].width)
				+ ((unsigned int)pt_t.x * p->texture[T_FONT].octet);
		ft_memcpy(image->data + pos, p->texture[T_FONT].data
				+ text_pos, (size_t)((image->octet) * (unsigned int)(var.x)));
	}
}

void		string_to_img(char *str, t_coord pt, t_img *img, t_struct *p)
{
	int		i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
	{
		char_to_img(str[i], pt, img, p);
		if (ft_strchr(TINY_CHAR, str[i]))
			pt.x -= 15;
		pt.x += BOX_X;
	}
}

/*
** Securiser la fonction !
*/

t_coord		centerx_str(char *str, t_coord pt)
{
	size_t len;

	if (!str)
		return (pt);
	len = ft_strlen(str);
	if ((pt.x -= (len / 2) * 32) < 0)
		pt.x = 0;
	return (pt);
}
