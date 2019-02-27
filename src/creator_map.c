# include "../include/doom-nukem.h"

 // METTRE LE PROTOTYPE DANS LE .H UNE FOIS CREE
void		creator_map(t_struct * p)

{
	mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->img_ptr3, 0, 653);
	ft_bzero(p->img_str2, WIDTH * HEIGHT * 4);
	minimap2(p);
}
