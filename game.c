/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:30:26 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/28 13:50:28 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	gm_trace_grid(int y, int x)
{
	int i;
	int j;

	j = 0;
	y = ((y - 5) / 4) * 4 + 5;
	x = ((x - 5) / 4) * 4 + 5;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if (j == 0 || j == y - 1 || i == 0 || i == x - 1)
			mvprintw(j, i, "X");
			i++;
		}
		j++;
	}
}

int main(void)
{
	int kc;
	int x;
	int y;
	WINDOW *screen;

	if (!(screen = initscr()))
		return (0);
	keypad(screen, true);
	while (1)
	{
		kc = getch();
		getmaxyx(screen, y, x);
		clear();
		gm_trace_grid(y, x);
		mvprintw(0, 0, "test");
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
