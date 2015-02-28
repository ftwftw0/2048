/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:30:26 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/28 15:07:59 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	gm_put_tab_to_window(int *tab, int j, int tmpx)
{
	int i;

	i = 0;
	while (i < 4)
	{
		mvprintw(j, tmpx * i + tmpx / 2 - ft_intlen(tab[i]) / 2 + 1, "%i", tab[i]);
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

int **ft_init()
{
	int **tab;
	int i;
	int j;

	if (!(tab = (int **)malloc(sizeof(int *) * 4)))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * 4)))
		{
			free(tab);
			return (NULL);
		}
		j = 0;
		while (j < 4)
		{
			tab[i][j] = i * j * 100000;
			j++;
		}
		i++;
	}
	return (tab);
}

int main(void)
{
	int kc;
	int x;
	int y;
	WINDOW *screen;

int **tab;
tab = ft_init();
	if (!(screen = initscr()))
		return (0);
	keypad(screen, true);
	while (1)
	{
		kc = getch();
		getmaxyx(screen, y, x);
		clear();
		gm_trace_grid(y, x, tab);
		if (kc == 27 || y < 10 || x < 38)
			break ;
		else if (kc == KEY_UP)
			mvprintw(y / 2, x / 2, "key up");
		else if (kc == KEY_DOWN)
			mvprintw(y / 2, x / 2, "key down");
		else if (kc == KEY_LEFT)
			mvprintw(y / 2, x / 2, "key left");
		else if (kc == KEY_RIGHT)
			mvprintw(y / 2, x / 2, "key right");
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
