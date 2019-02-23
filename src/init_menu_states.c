/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_states.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:28:25 by grdalmas          #+#    #+#             */
/*   Updated: 2019/02/23 21:10:30 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void	init_menu(t_game *gm)
{
	//gm->draw[MENU] = draw_main_menu;
	gm->draw[RUN] = draw_game;
	gm->draw[MAP_CREA] = draw_map_creator;
	// gm->event_key[MENU] = eventk_menu;
	// gm->event_key[GAME] = eventk_game;
	// gm->event_key[MAP_CREA] = eventk_map_creator;
	// gm->event_mouse[MENU] = eventm_menu;
	// gm->event_mouse[GAME] = eventm_game;
	// gm->event_mouse[MAP_CREA] = eventm_map_creator;
	gm->current_state = RUN;
}
