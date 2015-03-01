/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:34:45 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/01 17:40:02 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	gm_winscreen_message(int y, int x)
{
	int start;

	start = x / 2 - 33 / 2;
	y = (((y - 6) / 4) * 4 + 5) / 4;
	mvprintw(2 * y - 2, start, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	mvprintw(2 * y - 1, start, "Hey fool, guess what ! You won !");
	mvprintw(2 * y, x / 2 - 4, "Retry : R");
	mvprintw(2 * y + 1, x / 2 - 6, "Continue : C");
	mvprintw(2 * y + 2, x / 2 - 4, "Exit : E");
	mvprintw(2 * y + 3, start, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

int	gm_winscreen(WINDOW *screen, int ***tab, int *test)
{
	int x;
	int y;
	int kc;

	clear();
	getmaxyx(screen, y, x);
	gm_winscreen_message(y, x);
	while (1)
	{
		refresh();
		kc = getch();
		getmaxyx(screen, y, x);
		gm_winscreen_message(y, x);
		if (kc == 'e' || kc == 'E' || kc == 27)
			return (0);
		if (kc == 'r' || kc == 'R')
		{
			gm_erase_tab(tab);
			*tab = gm_init_tab();
			*test = 0;
			clear();
			return (1);
		}
		if (kc == 'c' || kc == 'C')
		{
			*test = 1;
			clear();
			return (2);
		}	
	}
	return (0);
}

int		gm_checkwin(int **tab, int size, int test)
{
	int x;
	int y;

	if (test)
		return (0);
	y = -1;
	while (++y < size)
	{
		x = 0;
		while (x < size)
			if (tab[y][x++] >= WIN_VALUE)
				return (1);
	}
	return (0);
}
