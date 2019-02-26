/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:12:31 by grdalmas          #+#    #+#             */
/*   Updated: 2019/02/26 16:11:35 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MANAGER_H
# define GAME_MANAGER_H

# define PERCENTAGE(p, x) ((p * x) / 100)

/*
**	Map Creator
**	TEXT:				Nombre de texture dans la palette.
**	TEXT_P:				Ecart en pixel, (le pas) entre chaque box de texture.
**	ITEM_SIZE:			Taille en pixel d'un carre pour representer une texture
**						/!\ pas encore proportionel a la taille fenetre ...
**	CUSTOM_MAP_NAME:	Nom du fichier lors d'une save.
**	MAP_CREA_MAX_MAP:	Nombre de map maximum & Utile aussi pour l'increment
**						du chiffre dans le nom du fichier.
*/
# define MC_TITLE "MAP CREATOR"
# define MC_INFO "Draw your map"
# define MC_SAVE "save"
# define TEXT 11
# define TEXT_P 16
# define CUSTOM_MAP_NAME "./custom_map_0.txt"
# define MAP_CREA_MAX_MAP '9' + 1
# define ITEM_SIZE 48

/*
**	Caractere a gerer differement pour l'espacement
**	lors de l'affichage d'une chaine de caractere.
**	(Caracteres qui rentre dans une case de 16 x 48 pixel).
*/
# define TINY_CHAR ".,1l!':;]Iij|["

/*
**	Les caracteres sont dans des cases de 32 x 48 pixel.
**	Afin de ne pas copier les contour de la case, nous recuperons
**	un rectangle legerement plus petit definit ci dessous.
**	La premiere case commence au pixel 34 en x et 34 en y.
*/
# define FRAME_X 32
# define FRAME_Y 48
# define BOX_X FRAME_X - 2
# define BOX_Y FRAME_Y - 2
# define START_XY 34

/*
**	Calcul de la position reel du caractere en pixel.
*/
# define GET_POS_X(c) (START_XY + (FRAME_X * GET_X(c)) )
# define GET_POS_Y(c) (START_XY + (FRAME_Y * GET_Y(c)) )


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
