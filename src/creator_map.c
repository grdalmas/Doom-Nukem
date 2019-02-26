# include "../include/doom-nukem.h"

 // METTRE LE PROTOTYPE DANS LE .H UNE FOIS CREE
void		creator_map(t_struct * p)
{
	ft_bzero(p->img_str2, WIDTH * HEIGHT * 4);
	minimap2(p);
}
