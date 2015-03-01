/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:30:26 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 19:43:16 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	gm_init_all(int *test, int ***tab, WINDOW **screen)
{
	int x;
	int y;

	srand(time(NULL));
	*test = 0;
	if (!(*screen = initscr()))
		return (0);
	if (!(*tab = gm_init_tab()))
		return (0);
	keypad(*screen, true);
	start_color();
	curs_set(0);
	getmaxyx(*screen, y, x);
	gm_trace_grid(y, x, *tab);
	return (1);
}

static void	gm_if_forest(int kc, int **tab)
{
	if (kc == KEY_UP && gm_vert(tab, 4, kc))
		gm_new_element(tab);
	else if (kc == KEY_DOWN && gm_vert(tab, 4, kc))
		gm_new_element(tab);
	else if (kc == KEY_LEFT && gm_horiz(tab, 4, kc))
		gm_new_element(tab);
	else if (kc == KEY_RIGHT && gm_horiz(tab, 4, kc))
		gm_new_element(tab);
}

static int	gm_end_it_now(int x, int y)
{
	endwin();
	if (y >= 10 && x >= 38)
		ft_printf("Bye, see you later\n");
	else
		ft_printf("\033[31m/!\\ Window size too small /!\\\033[0m\n");
	return (0);
}

static int	gm_check_valid_tab(int **tab)
{
	int x;
	int y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tab[x][y] == 0 || (x < 3 && tab[x][y] == tab[x + 1][y])
					|| (y < 3 && tab[x][y] == tab[x][y + 1]))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int			main(void)
{
	WINDOW	*screen;
	int		kc;
	int		xy[2];
	int		test;
	int		**tab;

	if (!gm_init_all(&test, &tab, &screen))
		return (0);
	while (1)
	{
		kc = getch();
		getmaxyx(screen, xy[1], xy[0]);
		clear();
		gm_if_forest(kc, tab);
		if (kc == 27 || xy[1] < 10 || xy[0] < 38 ||
			(!gm_check_valid_tab(tab) && !gm_game_over(&tab, screen, &test))
		|| (gm_checkwin(tab, 4, test) && !(gm_winscreen(screen, &tab, &test))))
			break ;
		gm_trace_grid(xy[1], xy[0], tab);
		refresh();
	}
	return (gm_end_it_now(xy[0], xy[1]));
}
