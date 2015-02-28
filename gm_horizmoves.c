/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_horizmoves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:23:25 by flagoutt          #+#    #+#             */
/*   Updated: 2015/02/28 18:05:12 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	check_lineright(int *line,  int size)
{
    int x;
    int tmp;
    int i;

    x = size - 1;
    while (x > 0)
    {
        i = cmp_case(line[x], line[x - 1]);
		if (i == 1)
		{
            line[x] = 2 * line[x];
            line[x - 1] = 0;
		}
        else if (i == 2)
		{
            tmp = x;
			if (tmp < size - 1)
				while ((line[tmp + 1] == 0 || line[tmp + 1] == line[x - 1])
					   && tmp < size - 1)
					tmp++;
            if (line[tmp] == line[x - 1])
				line[tmp] *= 2;
            else
                line[tmp] = line[x - 1];
            line[x - 1] = 0;
		}
        x--;
    }
    return (0);
}

static int	check_lineleft(int *line,  int size)
{
    int x;
    int tmp;
    int i;

    x = 0;
    while (x < size - 1)
    {
        i = cmp_case(line[x], line[x + 1]);
		if (i == 1)
		{
            line[x] = 2 * line[x];
            line[x + 1] = 0;
		}
        else if (i == 2)
		{
            tmp = x;
			if (tmp > 0)
				while ((line[tmp - 1] == 0 || line[tmp - 1] == line[x + 1])
					   && tmp > 0)
					tmp--;
            if (line[tmp] == line[x + 1])
				line[tmp] *= 2;
            else
                line[tmp] = line[x + 1];
            line[x + 1] = 0;
		}
        x++;
    }
    return (0);
}

int  		   gm_horiz(int **tab, int size, int keycode)
{
    int y;

    y = 0;
	if (keycode == KEY_LEFT)
		while (y < size)
			check_lineleft(tab[y++], size);
	else
		while (y < size)
			check_lineright(tab[y++], size);
    return (1);
}
