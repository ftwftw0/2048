/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:57:49 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 19:14:20 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	gm_print_message_game_over(WINDOW *screen, int score)
{
	int x;
	int y;

	getmaxyx(screen, y, x);
	clear();
	mvprintw(y / 2, x / 2 - 5, "GAME OVER");
	mvprintw(y / 2 + 1, x / 2 - 8, "Press r to retry");
	mvprintw(y / 2 + 2, x / 2 - 8, "Press e to exit");
	mvprintw(y / 2 + 3, x / 2 - 8, "SCORE TAVU : %i", score);
}

int			gm_game_over(int ***tab, WINDOW *screen, int *test)
{
	int kc;
	int score;

	score = gm_score(*tab, 4);
	if (*tab)
		gm_erase_tab(tab);
	while ((kc = getch()))
	{
		gm_print_message_game_over(screen, score);
		if (kc == 'r' || kc == 'R')
		{
			*test = 0;
			*tab = gm_init_tab();
			clear();
			return (1);
		}
		else if (kc == 27 || kc == 'e' || kc == 'E')
			return (0);
	}
	return (0);
}
