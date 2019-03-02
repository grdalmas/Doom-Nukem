#include "doom-nukem.h"

int		mouse_motion_diff(int x, int y, t_struct *p)
{
//	y+=30;
    if (p->choice == 3)
    {
		if (x >= 715 && x <= 905 && y >= 523 && y <= 585)
		{
			if (p->sound == 1)
			{
			if (p->ch != 1)
				system("afplay ./doomzik/zip.mp3 &");
			p->ch = 1;
			}
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[134].img_ptr, 0, 0);
		}
		else if (x >= 710 && x <= 910 && y >= 650 && y <= 700)
		{
			if (p->sound == 1)
			{
			if (p->ch != 2)
				system("afplay ./doomzik/zip.mp3 &");
			p->ch = 2;
			}
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[135].img_ptr, 0, 0);
		}
		else if (x >= 1105 && x <= 1320 && y >= 855 && y <= 900)
		{
			if (p->sound == 1)
			{
			if (p->ch != 3)
				system("afplay ./doomzik/zip.mp3 &");
			p->ch = 3;
			}
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[136].img_ptr, 0, 0);
		}
		else
		{

			p->ch = 0;
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[137].img_ptr, 0, 0);
		}
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
	printf("x%i\n ", x);
	printf("y%i\n ", y);
//	y+=30;
    if (p->choice == 3)
    {
		if ((b == 1) && x >= 715 && x <= 905 && y >= 523 && y <= 585)
		{
			if (p->sound == 1)
				system("afplay ./doomzik/tp.mp3 &");
            p->difficulty = 0;
		}
		else if ((b == 1) && x >= 710 && x <= 910 && y >= 650 && y <= 704)
		{
			if (p->sound == 1)
				system("afplay ./doomzik/youshall.mp3 &");
            p->difficulty = 1;
		}
		else if ((b == 1) && x >= 1105 && x <= 1320 && y >= 855 && y <= 900)
		{
			if (p->sound == 1)
				system("afplay ./doomzik/pain.mp3 &");
			p->choice = 2;
			mouse_release_settings(b, x, y, p);
		}
		else
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[137].img_ptr, 0, 0);
    }
	return (1);
}
