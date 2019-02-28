/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 00:11:00 by cmartine          #+#    #+#             */
/*   Updated: 2019/02/28 01:09:29 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/doom-nukem.h"

// METTRE LE PROTOTYPE DANS LE .H UNE FOIS CREE
void		creator_map(t_struct * p)
{
	ft_bzero(p->img_str2, WIDTH * HEIGHT * 4);
	img_to_img(p, 0, 0, 42, 1); //tes

	img_to_img(p, 945, 240, 58, 0.3); //indice pour dessiner index tex
	img_to_img(p, 840, 135, 8, 0.3); //indice pour dessiner index tex
	img_to_img(p, 840, 240, 23, 0.3); //indice pour dessiner index tex
	img_to_img(p, 945, 135, 9, 0.3); //indice pour dessiner index tex
	img_to_img(p, 1050, 240, 4, 0.3); //indice pour dessiner index tex
	img_to_img(p, 1050, 135, 10, 0.3); //indice pour dessiner index tex
	img_to_img(p, 1155, 240, 121, 0.3); //gomme
	img_to_img(p, 1155, 135, 11, 0.3); //indice pour dessiner index tex




	img_to_img(p, 840, 435, 51, 0.3); //indice pour dessiner index tex
//	img_to_img(p, 840, 540, 15, 0.3); //indice pour dessiner index tex
//	img_to_img(p, 945, 540, 16, 0.3); //indice pour dessiner index tex
	img_to_img(p, 945, 435, 33, 0.3); //indice pour dessiner index tex
//	img_to_img(p, 1050, 540, 0, 0.3); //indice pour dessiner index tex
	img_to_img(p, 1050, 435, 46, 0.3); //indice pour dessiner index tex
//	img_to_img(p, 1155, 540, 12, 0.3); //indice pour dessiner index tex
	img_to_img(p, 1155, 435, 50, 0.3); //indice pour dessiner index tex


	int i;
	int j;

	i = 0;
	while (i < 15)
	{
		j = 0;
		while (j < 15)
		{
			if (p->map[4][j][i] >= 1)
			{
				img_to_img(p, 155 + (i * 40), 35 + (j * 40), p->map[4][j][i], 0.15625);
			}
			j++;
		}
		i++;
	}

	minimap2(p);
}
