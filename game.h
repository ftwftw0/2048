/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:32:06 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/28 17:15:15 by lchenut          ###   ########.fr       */
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
int		cmp_case(int case1, int case2);
int     gm_horiz(int **tab, int size, int keycode);
int     gm_vert(int **tab, int size, int keycode);

#endif
