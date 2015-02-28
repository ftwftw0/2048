/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:30:26 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/28 17:18:22 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	gm_put_tab_to_window(int *tab, int j, int tmpx)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tab[i] != 0)
			mvprintw(j, tmpx * i + tmpx / 2 - ft_intlen(tab[i]) / 2 + 1,
					"%i", tab[i]);
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
	y = ((y - 5) / 4) * 4 + 5;
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
}

int main(void)
{
	int kc;
	int x;
	int y;
	int **tab;
	WINDOW *screen;

	tab = gm_init_tab();
	if (!(screen = initscr()))
		return (0);
	keypad(screen, true);
	while (1)
	{
		kc = getch();
		getmaxyx(screen, y, x);
		clear();
		if (kc == 27 || y < 10 || x < 38)
			break ;
		else if (kc == KEY_UP)
		{
			gm_vert(tab, 4, kc);
			gm_new_element(tab);
		}
		else if (kc == KEY_DOWN)
		{
			gm_vert(tab, 4, kc);
			gm_new_element(tab);
		}
		else if (kc == KEY_LEFT)
		{
			gm_horiz(tab, 4, kc);
			gm_new_element(tab);
		}
		else if (kc == KEY_RIGHT)
		{
			gm_horiz(tab, 4, kc);
			gm_new_element(tab);
		}
		gm_trace_grid(y, x, tab);
		refresh();
	}
	endwin();
	if (kc == 27)
		ft_printf("Bye, see you later\n");
	else
		ft_printf("\033[31m/!\\ Window size too small /!\\\033[0m\n");
	ft_printf("%i %i\n", 8 * 4 + 5, 4 * 1 + 5);
	return (0);
}
