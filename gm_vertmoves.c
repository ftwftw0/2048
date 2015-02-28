/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_vertmoves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:36:09 by flagoutt          #+#    #+#             */
/*   Updated: 2015/02/28 17:11:33 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	check_columnup(int **tab,  int size, int column)
{
    int y;
    int tmp;
    int i;

    y = 0;
    while (y < size - 1)
    {
        i = cmp_case(tab[y][column], tab[y + 1][column]);
		if (i == 1)
		{
            tab[y][column] = 2 * tab[y][column];
            tab[y + 1][column] = 0;
		}
        else if (i == 2)
		{
            tmp = y;
			if (tmp > 0)
				while (tab[tmp - 1][column] == 0 && tmp > 0)
					tmp--;
            if (tab[tmp][column] == tab[tmp + 1][column])
				tab[tmp][column] *= 2;
            else
                tab[tmp][column] = tab[y + 1][column];
            tab[y + 1][column] = 0;
		}
        y++;
    }
    return (0);
}

static int	check_columndown(int **tab,  int size, int column)
{
    int y;
    int tmp;
    int i;

    y = size - 1;
    while (y > 0)
    {
        i = cmp_case(tab[y][column], tab[y - 1][column]);
		if (i == 1)
		{
            tab[y][column] = 2 * tab[y][column];
            tab[y - 1][column] = 0;
		}
        else if (i == 2)
		{
            tmp = y;
			if (tmp > 0)
				while (tab[y - 1][column] == 0 && tmp < size - 1)
					tmp++;
            if (tab[tmp][column] == tab[tmp - 1][column])
				tab[tmp][column] *= 2;
            else
                tab[tmp][column] = tab[y - 1][column];
            tab[y - 1][column] = 0;
		}
        y--;
    }
    return (0);
}

int			gm_vert(int **tab, int size, int keycode)
{
    int x;

    x = 0;
	if (keycode == KEY_UP)
		while (x < size)
			check_columnup(tab, size, x++);
	else
		while (x < size)
			check_columndown(tab, size, x++);
    return (1);
}
