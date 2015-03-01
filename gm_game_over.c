/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:57:49 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 10:49:25 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	gm_erase_tab(int ***tab)
{
	free((*tab)[0]);
	(*tab)[0] = NULL;
	free((*tab)[1]);
	(*tab)[1] = NULL;
	free((*tab)[2]);
	(*tab)[2] = NULL;
	free((*tab)[3]);
	(*tab)[3] = NULL;
	free(*tab);
	*tab = NULL;
}

static void	gm_print_message_game_over(WINDOW *screen)
{
	int x;
	int y;

	getmaxyx(screen, y, x);
	clear();
	mvprintw(y / 2, x / 2 - 5, "GAME OVER");
	mvprintw(y / 2 + 1, x / 2 - 8, "Press r to retry");
	mvprintw(y / 2 + 2, x / 2 - 8, "Press e to exit");
}

int			gm_game_over(int ***tab, WINDOW *screen)
{
	int kc;

	if (*tab)
		gm_erase_tab(tab);
	while ((kc = getch()))
	{
		gm_print_message_game_over(screen);
		if (kc == 'r' || kc == 'R')
		{
			*tab = gm_init_tab();
			clear();
			return (1);
		}
		else if (kc == 27 || kc == 'e' || kc == 'E')
			return (0);
	}
	return (0);
}
