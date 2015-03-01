/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:30:26 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 17:40:06 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int main(void)
{
	int kc;
	int x;
	int y;
	int test;
	int **tab;
	WINDOW *screen;

	srand(time(NULL));
	test = 0;
	if (!(tab = gm_init_tab()))
		return (0);
	if (!(screen = initscr()))
		return (0);
	keypad(screen, true);
	start_color();
	curs_set(0);
	getmaxyx(screen, y, x);
	gm_trace_grid(y, x, tab);
	while (1)
	{
		kc = getch();
		getmaxyx(screen, y, x);
		clear();
		if (kc == 27 || y < 10 || x < 38)
			break ;
		else if (kc == KEY_UP && gm_vert(tab, 4, kc))
			gm_new_element(tab);
		else if (kc == KEY_DOWN && gm_vert(tab, 4, kc))
			gm_new_element(tab);
		else if (kc == KEY_LEFT && gm_horiz(tab, 4, kc))
			gm_new_element(tab);
		else if (kc == KEY_RIGHT && gm_horiz(tab, 4, kc))
			gm_new_element(tab);
		else if (!gm_count_empty_spaces(tab) && !gm_game_over(&tab, screen, &test))
			break ;
		if (gm_checkwin(tab, 4, test))
			if (!(gm_winscreen(screen, &tab, &test)))
				break ;
		gm_trace_grid(y, x, tab);
		refresh();
	}
	endwin();
	if (y >= 10 && x >= 38)
		ft_printf("Bye, see you later\n");
	else
		ft_printf("\033[31m/!\\ Window size too small /!\\\033[0m\n");
	return (0);
}
