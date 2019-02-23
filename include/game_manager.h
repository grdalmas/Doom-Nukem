/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:12:31 by grdalmas          #+#    #+#             */
/*   Updated: 2019/02/23 21:10:10 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MANAGER_H
# define GAME_MANAGER_H

/*
**	Menu Principal
*/
# define G_NAME "WOLF 3-D"
# define G_RUN "Game"
# define G_MC "Map Creator"
# define G_EXIT "Exit"



typedef enum	e_texture
{
	T_MAP_CREATOR, T_CREATOR_INTERFACE, T_FONT,
	NB_TEXTURE,
}				t_texture;

 typedef enum	e_page
 {
 	MAIN_MENU, GAME, MAP_CREATOR, NB_PAGE, GAME_I, MAP_I, NB_IMG,
 }				t_page;

typedef enum	e_menu
{
	MENU, RUN, MAP_CREA, NB_MENU_ENTRY,
}				t_menu;

typedef struct		s_coord
{
	int				x;
	int				y;
	unsigned int	color;
}					t_coord;

typedef struct		s_img
{
	void			*ptr;
	char			*data;
	t_coord			size;
	int				width;
	int				bpp;
	int				endian;
	unsigned int	octet;
}					t_img;

typedef void		(*t_draw)(void *gm);

typedef int			(*t_event_k)(int keyhook, void *gm);

typedef int			(*t_event_m)(int button, int x, int y, void *gm);

typedef struct 		s_game
{
	t_draw			draw[NB_MENU_ENTRY];
	t_event_k		event_key[NB_MENU_ENTRY];
	t_event_m		event_mouse[NB_MENU_ENTRY];
	t_menu			current_state;
}					t_game;

void		draw_game(void *gm);

#endif
