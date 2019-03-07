/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <tifuret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 03:12:51 by cmartine          #+#    #+#             */
/*   Updated: 2019/03/07 20:57:05 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

# include "mlx_macos_key.h"
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "delta_time.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 960
# define WIDTHMAP 270
# define HEIGHTMAP 270
# define SKYHEIGHT 2556
# define SKYHW 1633284
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define SPACE 49
# define PAS 35
# define BPP 4
# define WHBPP 4915200
# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define CLOSE 17
# define POINTERMOTIONMASK (1L << 6)
# define MOTIONNOTIFY 6
# define CLOSEMASK (1L<<17)
# define NUMSPRITE 25
# define TEX 139
# define FOV 60
# define PI 3.14159256
# define PORTE 1
# define NUMPORTE 2
# define NUMENEMY 1
# define WMHM4 291600
# define WH4 4915200
# define SKYHW 1633284
# define WIDTHMINUSONE 1279

/*
**	Enumeration des touches qui peuvent etre presse ensemble
**	Utile aussi pour sauvegarder l'etat de la touche
**	pour agir en consequence dans l'expose.
*/

typedef enum		e_keystate
{
	LAST_KEY_PRESS,
	KEY_TAB, KEY_W, KEY_UP, KEY_DOWN, KEY_D, KEY_A, KEY_SHIFT,
	KEY_C, KEY_LEFT, KEY_RIGHT, KEY_SPACEBAR, KEY_ESCAPE, KEY_Q, KEY_E, KEY_R,
	KEY_S, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_M, KEY_PAD_1, KEY_PAD_2,
	KEY_PAD_3, KEY_PAD_4, KEY_PAD_5,
	NB_KEYSTATE

}					t_keystate;

typedef struct		s_porte
{
	float	open;
	float	spd;
	int		zip;
	int		poort;
}					t_porte;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

typedef struct		s_sprite
{
	int				k;
	int				id;
	double			y;
	double			x;
	int				pv;
}					t_sprite;

typedef struct		s_weapon
{
	int				id;
	int				reload;
	int				sprite;
}					t_weapon;

typedef struct		s_mspr
{
	int				startx;
	int				starty;
	int				endx;
	int				endy;
	int				spritescreenx;
	double			transy;
}					t_mspr;

typedef struct		s_tex
{
	char			*str;
	int				height;
	int				width;
	void			*img_ptr;
	char			*img_str;
	int				sizeline;
	int				endian;
}					t_tex;

typedef struct		s_iti
{
	int l;
	int c;
	int tmp;
	int tmpy;
}					t_iti;

typedef struct		s_camera
{
	double			p_x;
	double			p_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			r_dir_x;
	double			r_dir_y;
	double			floor_x;
	double			floor_y;
	int				map_x;
	int				map_y;
	int				side;
	int				step_x;
	int				step_y;
	double			shadow;
	int				what;
	double			side_x;
	double			side_y;
	double			delta_x;
	double			delta_y;
	double			wall_dist;
	int				y_end;
	double			offset;
	double			rotation_speed;
	int				pas;
	double			ra;
	int				colo;
	int				x1;
	int				calc;
}					t_camera;

typedef struct		s_struct
{
	t_tex			tex[TEX];
	t_delta_time	time;
	t_porte			*porte;
	double			zbuff[WIDTH];
	double			sprited[NUMSPRITE];
	int				ordersprite[NUMSPRITE];
	t_mspr			mspr;
	int				bpp;
	int				size_line;
	void			*mlx_ptr;
	void			*w_ptr;
	void			*img_ptr;
	void			*img_ptr2;
	void			*img_ptr3;
	char			*img_str;
	char			*img_str2;
	char			*img_str3;
	int				***map;
	int				k;
	int				tid;
	int				x;
	int				y;
	t_sprite		*sprite;
	t_color			color;
	t_camera		*c;
	int				ox;
	int				oy;
	float			s;
	int				keypress[NB_KEYSTATE];
	int				dodor;
	t_weapon		weapon;
	float			life;
	int				h;
	int				shoot;
	int				elevator;
	int				hit;
	int				trump;
	int				tool;
	int				maap;
	char			cure;
	char			temp;
	char			trons;
	char			elev;
	char			pas;
	char			trumplive;
	char			menu;
	char			edit;
	int				edits;
	int				mousex;
	int				mousey;
	char			floor;
	char			soundpain;
	char			soundpainmum;
	int				choice;
	int				ch;
	int				sound;
	int				difficulty;
	float			sprint;
	int				dead;
	t_iti			i;
	int				skytex;
	double			skyt;
}					t_struct;

/*
**					against_glitch.c
*/
int					against_glitch(t_struct *p, int move, double s);
int					against_glitch_straff(t_struct *p, int move, double s);

/*
**					creator_map.c
*/
void				creator_map(t_struct *p, int i, int j);
/*
**					difficulty_hook.c
*/
int					mouse_motion_diff(int x, int y, t_struct *p);
int					mouse_release_diff(int b, int x, int y, t_struct *p);
/*
**					draw_3d.c
*/
void				draw_wall_3d(t_struct *p, int x, int y, int wall_height);
/*
**					draw_3d2.c
*/
void				which_text(t_struct *p);
void				which_textf(t_struct *p);
void				color_text(t_struct *p, int col, int line, double ratio);
void				color_text2(t_struct *p, int col, int line, double ratio);
void				color_textf(t_struct *p, int col, int line, double ratio);
/*
**					draw_line.c
*/
void				draw_pixel(char *img_str, int x, int y, int color);
void				draw_pixel2(t_struct *p, char *img_str, int x, int y);
void				draw_line(int y, int x2, int y2, t_struct *p);
/*
**					draw_line2.c
*/
void				draw_line2(int y, int x2, int y2, t_struct *p);
int					*fill_color2(int *str, int x, int y, int c);
/*
**					game.c
*/
int					draw_game(t_struct *p);
/*
**					hooks.c
*/
int					key_press_hook(t_struct *p);
/*
**					img_to_img.c
*/
void				img_to_img2(t_struct *p, int x, int y, int indice);
void				img_to_img3(t_struct *p, int x, int y, int indice);
void				img_to_img(t_struct *p, int x, int y, int indice);
void				skybox(t_struct *p, int y, int x);
/*
**					init.c
*/
int					close_window(t_struct *p);
void				*init(t_struct *param);
void				initplayer(t_struct *param);
t_sprite			*init_sprite(void);
t_porte				*init_door(void);
/*
**					key_event.c
*/
int					keyrelease(int keycode, void *d);
int					keypress(int keycode, void *d);
/*
**					key_event2.c
*/
void				keypress3(int keycode, t_struct *p);
/*
**					main.c
*/
void				timer(t_struct *p);
/*
**					menu.c
*/
int					mouse_release_menu(int b, int x, int y, t_struct *p);
int					mouse_motion_menu(int x, int y, t_struct *p, int s);
/*
**					minimap.c
*/
int					*fill_color(int *str, int x, int y, int c);
void				minimap(t_struct *p);
/*
**					minimap2.c
*/
void				minimap2(t_struct *p);
void				*inverse_map(t_struct *p, int i, int j, int k);
/*
**					mouse_creator_map.c
*/
void				mouse_creator_map(t_struct *p, int button, int x, int y);
/*
**					mouse_event.c
*/
int					mouse_motion(int x, int y, t_struct *p);
int					mouse_button(int button, int x, int y, t_struct *p);
/*
**					movement.c
*/
void				move_up(t_struct *p, int move, int i, double s);
/*
**					movement2.c
*/
void				move_up2(t_struct *p, int move);
void				elevator(t_struct *p);
/*
**					player_events.c
*/
void				alive(t_struct *p);
void				spawn(t_struct *p);
/*
**					raycasting.c
*/
void				walls_sides(t_struct *p, int x);
/*
**					raycasting2.c
*/
void				raycasting(t_struct *param, int x, int z);
/*
**					save_map.c
*/
void				save_map(t_struct *info);
/*
**					settings_hook.c
*/
int					mouse_motion_settings(int x, int y, t_struct *p);
int					mouse_release_settings(int b, int x, int y, t_struct *p);
/*
**					sprite.c
*/
void				order_sprite(t_struct *p);
void				raysprite(t_struct *p, double d, int i, double ratio);
/*
**					sprite_event.c
*/
void				movemy(t_struct *p, int i);
void				movemy2(t_struct *p, int i);
/*
**					take_object.c
*/
void				take_object(t_struct *p);
/*
**					textures.c
*/
void				load_textures(t_struct *p);
/*
**					textures2.c
*/
void				load_textures4(t_struct *p);
/*
**					trump.c
*/
void				trump(t_struct *p);
void				rotrump2(t_struct *p);
void				rotrump(t_struct *p);
/*
**					weapon.c
*/
void				weapon(t_struct *p);
/*
**					weapon2.c
*/
void				weapon3(t_struct *p);
/*
**					weapon3.c
*/
void				soundpain(t_struct *p);
void				shoot(t_struct *p);
/*
**					skybox.c
*/
void				skybox(t_struct *p, int y, int x);
/*
**					img_to_img.c
*/
void				color_text_sky(t_struct *p, int col, int line);
#endif
