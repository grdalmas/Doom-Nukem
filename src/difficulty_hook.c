#include "doom-nukem.h"

int		mouse_motion_diff(int x, int y, t_struct *p)
{
    if (p->choice == 3)
    {
		if (x >= 715 && x <= 905 && y >= 555 && y <= 600)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[134].img_ptr, 0, 35);
		else if (x >= 710 && x <= 910 && y >= 685 && y <= 735)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[135].img_ptr, 0, 35);
		else if (x >= 1105 && x <= 1320 && y >= 905 && y <= 940)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[136].img_ptr, 0, 35);
		else
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[136].img_ptr, 0, 35);
    }
	return (1);
}
/*
int		mouse_clic_diff(int b, int x, int y, t_struct *p)
{
	int		i;

	if (p->choice == 3)
	{
		if ((b == 1) && x >= 715 && x <= 905 && y >= 555 && y <= 600)
			//music
		else if ((b == 1) && x >= 710 && x <= 910 && y >= 685 && y <= 735)
			//music
		else if ((b == 1) && x >= 1105 && x <= 1320 && y >= 905 && y <= 940)
			//music (return)
		else
			//music or nothing
	}
	return (1);
}*/

int		mouse_release_diff(int b, int x, int y, t_struct *p)
{
    if (p->choice == 3)
    {
		if ((b == 1) && x >= 715 && x <= 905 && y >= 555 && y <= 600)
            p->difficulty = 0;
		else if ((b == 1) && x >= 710 && x <= 910 && y >= 685 && y <= 735)
            p->difficulty = 1;
		else if ((b == 1) && x >= 1105 && x <= 1320 && y >= 905 && y <= 940)
			p->choice = 2;
		else
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[136].img_ptr, 0, 35);
    }
	return (1);
}