/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_vertmoves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:36:09 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/01 11:09:58 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	check_columnup(int **tab,  int size, int column)
{
    int y;
    int tmp;
    int i;
	int ret;

	ret = 0;
    y = 0;
    while (y < size - 1)
    {
        i = cmp_case(tab[y][column], tab[y + 1][column]);
		if (i == 1)
		{
            tab[y][column] = 2 * tab[y][column];
            tab[y + 1][column] = 0;
			ret++;
		}
        else if (i == 2)
		{
            tmp = y;
			while (tmp > 0)
			{
				if ((tab[tmp - 1][column] != 0
					&& tab[tmp - 1][column] != tab[y + 1][column]))
					break ;
				tmp--;
			}
            if (tab[tmp][column] == tab[y + 1][column])
				tab[tmp][column] *= 2;
            else
                tab[tmp][column] = tab[y + 1][column];
            tab[y + 1][column] = 0;
			ret++;
		}
        y++;
    }
    return (ret);
}
/*
static int	check_columndown(int **tab,  int size, int column)
{
    int y;
    int tmp;
    int i;
	int ret;

    y = size - 1;
	ret = 0;
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
			while (tmp < size - 1)
			{
				if ((tab[tmp + 1][column] != 0
					&& tab[tmp + 1][column] != tab[y - 1][column]))
					break ;
				tmp++;
			}
            if (tab[tmp][column] == tab[y - 1][column])
				tab[tmp][column] *= 2;
            else
                tab[tmp][column] = tab[y - 1][column];
            tab[y - 1][column] = 0;
		}
		ret = ret | i;
        y--;
    }
    return (ret);
}
*/
static int	check_columndown(int **tab, int size, int column, int kc)
{
	int ret;

	ret = 0;
	ret = ret + gm_push(tab, size, column, kc);
	ret = ret + gm_merge(tab, size, column, kc);
	ret = ret + gm_push(tab, size, column, kc);
	return (ret);
}

int			gm_vert(int **tab, int size, int keycode)
{
    int x;
	int ret;

    x = 0;
	ret = 0;
	if (keycode == KEY_UP)
		while (x < size)
			ret += check_columnup(tab, size, x++);
	else
		while (x < size)
			ret += check_columndown(tab, size, x++, keycode);
    return (ret);
}
