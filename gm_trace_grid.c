/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_trace_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:53:00 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 17:40:04 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	gm_put_tab_to_window(int *tab, int j, int tmpx)
{
	int i;

	i = 0;
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	while (i < 4)
	{
		if (tab[i] != 0)
		{
			attron(COLOR_PAIR(ft_depow2(tab[i]) % 7 + 1));
			mvprintw(j, tmpx * i + tmpx / 2 - ft_intlen(tab[i]) / 2 + 1,
					"%i", tab[i]);
			attroff(COLOR_PAIR(ft_depow2(tab[i]) % 7 + 1));
		}
		i++;
	}
}

void	gm_trace_grid(int y, int x, int **tab)
{
	int i;
	int j;
	int tmpx;
	int tmpy;
	int height;

	j = 0;
	height = 0;
	y = ((y - 6) / 4) * 4 + 5;
	x = ((x - 5) / 4) * 4 + 5;
	tmpy = y / 4;
	tmpx = x / 4;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if ((i % tmpx) == 0 && (j % tmpy) == 0)
				mvprintw(j, i, "+");
			else if ((i % tmpx) == 0)
				mvprintw(j, i, "|");
			else if ((j % tmpy) == 0)
				mvprintw(j, i, "-");
			i++;
		}
		if ((j % tmpy) == tmpy / 2)
			gm_put_tab_to_window(tab[height++], j, tmpx);
		j++;
	}
	mvprintw(y, 0, "Score : %i", gm_score(tab, 4));
}

