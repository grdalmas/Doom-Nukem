#include "doom-nukem.h"


int		mouse_motion_settings(int x, int y, t_struct *p)
{

		y = y+30;
    if (p->choice == 2)
    {
		if (x >= 600 && x <= 1025 && y >= 562 && y <= 610)
        {
			if (p->sound == 1)
                mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[132].img_ptr, 0, 0);
            else if (p->sound == 0)
			    mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[129].img_ptr, 0, 0);
        }
		else if (x >= 790 && x <= 900 && y >= 835 && y <= 930)
        {
            if (p->sound == 1)
                mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[133].img_ptr, 0, 0);
            else if (p->sound == 0)
			    mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[130].img_ptr, 0, 0);
        }
		else if (x >= 1105 && x <= 1320 && y >= 895 && y <= 930)
        {
			if (p->sound == 1)
                mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[131].img_ptr, 0, 0);
            else if (p->sound == 0)
			    mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[128].img_ptr, 0, 0);
        }
		else
        {
            if (p->sound == 1)
			    mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[126].img_ptr, 0, 0);
            else if (p->sound == 0)
                mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[127].img_ptr, 0, 0);
        }
    }
	return (1);
}
/*
int		mouse_clic_settings(int b, int x, int y, t_struct *p)
{
	int		i;

	if (p->choice == 2)
	{
		if ((b == 1) && x >= 600 && x <= 1025 && y >= 562 && y <= 610)
			//music
		else if ((b == 1) && x >= 790 && x <= 900 && y >= 835 && y <= 920)
			//music
		else if ((b == 1) && x >= 1105 && x <= 1320 && y >= 895 && y <= 930)
			//music (Return)
		else
			//music or nothing
	}
	return (1);
}*/

int		mouse_release_settings(int b, int x, int y, t_struct *p)
{
		y = y+30;
    if (p->choice == 2)
    {
		if ((b == 1) && x >= 600 && x <= 1025 && y >= 562 && y <= 610)
            p->choice = 3;
		else if ((b == 1) && x >= 790 && x <= 900 && y >= 835 && y <= 920)
        {
            if (p->sound == 1)
                p->sound = 0;
            else if (p->sound == 0)
                p->sound = 1;
        }
		else if ((b == 1) && x >= 1105 && x <= 1320 && y >= 895 && y <= 930)
			p->choice = 0;
		else
        {
            if (p->sound == 1)
			    mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[126].img_ptr, 0, 0);
            else if (p->sound == 0)
                mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[127].img_ptr, 0, 0);
        }
    }
	return (1);
}
