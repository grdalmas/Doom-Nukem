# include "../include/doom-nukem.h"

// METTRE LE PROTOTYPE DANS LE .H UNE FOIS CREE
void		creator_map(t_struct * p)
{
	ft_bzero(p->img_str2, WIDTH * HEIGHT * 4);
	img_to_img(p, 0, 0, 42, 1); //tes
	img_to_img(p, 155, 35, 25, 0.15625); //indice pour dessiner sur la mainp

	img_to_img(p, 840, 135, 25, 0.3); //indice pour dessiner index tex
	img_to_img(p, 840, 240, 24, 0.3); //indice pour dessiner index tex
	img_to_img(p, 945, 240, 26, 0.3); //indice pour dessiner index tex
	img_to_img(p, 945, 135, 27, 0.3); //indice pour dessiner index tex
	img_to_img(p, 1050, 240, 28, 0.3); //indice pour dessiner index tex
	img_to_img(p, 1050, 135, 29, 0.3); //indice pour dessiner index tex
	img_to_img(p, 1155, 240, 30, 0.3); //indice pour dessiner index tex
	img_to_img(p, 1155, 135, 31, 0.3); //indice pour dessiner index tex




	img_to_img(p, 840, 435, 14, 0.3); //indice pour dessiner index tex
	img_to_img(p, 840, 540, 15, 0.3); //indice pour dessiner index tex
	img_to_img(p, 945, 540, 16, 0.3); //indice pour dessiner index tex
	img_to_img(p, 945, 435, 17, 0.3); //indice pour dessiner index tex
	img_to_img(p, 1050, 540, 0, 0.3); //indice pour dessiner index tex
	img_to_img(p, 1050, 435, 1, 0.3); //indice pour dessiner index tex
	img_to_img(p, 1155, 540, 3, 0.3); //indice pour dessiner index tex
	img_to_img(p, 1155, 435, 43, 0.3); //indice pour dessiner index tex


	int i;
	int j;

	i = 0;
	while (i < 15)
	{
		j = 0;
		while (j < 15)
		{
			if (p->map[4][j][i] >= 1)
				img_to_img(p, 155 + (i * 40), 35 + (j * 40), p->map[4][j][i], 0.15625); //indice pour dessiner sur la mainp
			j++;
		}
		i++;
	}

	minimap2(p);
}
