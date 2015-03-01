/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:32:06 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 19:01:20 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdlib.h>
# include <signal.h>
# include <time.h>
# include <curses.h>
# include "libft/libft.h"

enum	e_const
{
	WIN_VALUE = 2048
};

int		**gm_init_tab(void);
void	gm_new_element(int **tab);
int		gm_count_empty_spaces(int **tab);
void	gm_trace_grid(int y, int x, int **tab);
int		gm_horiz(int **tab, int size, int keycode);
int		gm_vert(int **tab, int size, int keycode);
int		gm_game_over(int ***tab, WINDOW *screen, int *test);
void	gm_erase_tab(int ***tab);
int		gm_push(int **tab, int size, int linecol, int kc);
int		gm_merge(int **tab, int size, int linecol, int kc);
int		gm_score(int **tab, int size);
int		gm_winscreen(WINDOW *screen, int ***tab, int *test);
int		gm_checkwin(int **tab, int size, int test);

#endif
