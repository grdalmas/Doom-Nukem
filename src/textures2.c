/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:01:22 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/04 19:11:58 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void		load_textures7(t_struct *p)
{
	p->tex[134].str = ft_strdup("textures/menu/DIFFICULTY-EASY.xpm");
	p->tex[135].str = ft_strdup("textures/menu/DIFFICULTY-HARD.xpm");
	p->tex[136].str = ft_strdup("textures/menu/DIFFICULTY-RETURN.xpm");
	p->tex[137].str = ft_strdup("textures/menu/DIFFICULTY.xpm");
	p->tex[138].str = ft_strdup("textures/keys.xpm");
	init_textures(p);
}

void		load_textures6(t_struct *p)
{
	p->tex[112].str = ft_strdup("textures/sk6.xpm");
	p->tex[113].str = ft_strdup("textures/sk7.xpm");
	p->tex[114].str = ft_strdup("textures/sk8.xpm");
	p->tex[115].str = ft_strdup("textures/transpa.xpm");
	p->tex[116].str = ft_strdup("textures/TRUMP2.xpm");
	p->tex[117].str = ft_strdup("textures/elevator_close.xpm");
	p->tex[118].str = ft_strdup("textures/TRUMP3.xpm");
	p->tex[119].str = ft_strdup("textures/game_over.xpm");
	p->tex[120].str = ft_strdup("textures/pause.xpm");
	p->tex[121].str = ft_strdup("textures/eraser.xpm");
	p->tex[122].str = ft_strdup("textures/menu/MENU.xpm");
	p->tex[123].str = ft_strdup("textures/menu/MENU_START.xpm");
	p->tex[124].str = ft_strdup("textures/menu/MENU_SETTINGS.xpm");
	p->tex[125].str = ft_strdup("textures/menu/MENU_QUIT.xpm");
	p->tex[126].str = ft_strdup("textures/menu/SETTINGS-SOUND_ON.xpm");
	p->tex[127].str = ft_strdup("textures/menu/SETTINGS-SOUND_OFF.xpm");
	p->tex[128].str = ft_strdup("textures/menu/SETTINGS-SOUND_OFF-RETURN.xpm");
	p->tex[129].str = ft_strdup("textures/menu/SETTINGS-SOUND_OFF-DIFF.xpm");
	p->tex[130].str = ft_strdup("textures/menu/SETTINGS-SOUND_OFF-COLOR.xpm");
	p->tex[131].str = ft_strdup("textures/menu/SETTINGS-SOUND_ON-RETURN.xpm");
	p->tex[132].str = ft_strdup("textures/menu/SETTINGS-SOUND_ON-DIFF.xpm");
	p->tex[133].str = ft_strdup("textures/menu/SETTINGS-SOUND_ON-COLOR.xpm");
	load_textures7(p);
}

void		load_textures5(t_struct *p)
{
	p->tex[90].str = ft_strdup("textures/mosaique.xpm");
	p->tex[91].str = ft_strdup("textures/asc1.xpm");
	p->tex[92].str = ft_strdup("textures/gun1.xpm");
	p->tex[93].str = ft_strdup("textures/gun2.xpm");
	p->tex[94].str = ft_strdup("textures/gun3.xpm");
	p->tex[95].str = ft_strdup("textures/gun.xpm");
	p->tex[96].str = ft_strdup("textures/recharge1.xpm");
	p->tex[97].str = ft_strdup("textures/recharge2.xpm");
	p->tex[98].str = ft_strdup("textures/recharge3.xpm");
	p->tex[99].str = ft_strdup("textures/recharge4.xpm");
	p->tex[100].str = ft_strdup("textures/recharge5.xpm");
	p->tex[101].str = ft_strdup("textures/recharge6.xpm");
	p->tex[102].str = ft_strdup("textures/cave.xpm");
	p->tex[103].str = ft_strdup("textures/asc2.xpm");
	p->tex[104].str = ft_strdup("textures/asc3.xpm");
	p->tex[105].str = ft_strdup("textures/asc4.xpm");
	p->tex[106].str = ft_strdup("textures/asc5.xpm");
	p->tex[107].str = ft_strdup("textures/sk1.xpm");
	p->tex[108].str = ft_strdup("textures/sk2.xpm");
	p->tex[109].str = ft_strdup("textures/sk3.xpm");
	p->tex[110].str = ft_strdup("textures/sk4.xpm");
	p->tex[111].str = ft_strdup("textures/sk5.xpm");
	load_textures6(p);
}

void		load_textures4(t_struct *p)
{
	p->tex[69].str = ft_strdup("textures/orchestre_1.xpm");
	p->tex[70].str = ft_strdup("textures/orchestre_2.xpm");
	p->tex[71].str = ft_strdup("textures/orchestre_3.xpm");
	p->tex[72].str = ft_strdup("textures/orchestre_4.xpm");
	p->tex[73].str = ft_strdup("textures/orchestre_5.xpm");
	p->tex[74].str = ft_strdup("textures/wall_tim.xpm");
	p->tex[75].str = ft_strdup("textures/vivaldi.xpm");
	p->tex[76].str = ft_strdup("textures/schubert.xpm");
	p->tex[77].str = ft_strdup("textures/beethoven.xpm");
	p->tex[78].str = ft_strdup("textures/haydn.xpm");
	p->tex[79].str = ft_strdup("textures/mozart.xpm");
	p->tex[80].str = ft_strdup("textures/jack_sparrow.xpm");
	p->tex[81].str = ft_strdup("textures/wall_flowers.xpm");
	p->tex[82].str = ft_strdup("textures/enemy1-1.xpm");
	p->tex[83].str = ft_strdup("textures/enemy1-2.xpm");
	p->tex[84].str = ft_strdup("textures/enemy2-1.xpm");
	p->tex[85].str = ft_strdup("textures/enemy2-3.xpm");
	p->tex[86].str = ft_strdup("textures/tronco.xpm");
	p->tex[87].str = ft_strdup("textures/tronco1.xpm");
	p->tex[88].str = ft_strdup("textures/tronco2.xpm");
	p->tex[89].str = ft_strdup("textures/musique_notes.xpm");
	load_textures5(p);
}
