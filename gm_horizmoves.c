/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_horizmoves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:23:25 by flagoutt          #+#    #+#             */
/*   Updated: 2015/02/28 19:25:57 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	check_lineright(int *line,  int size)
{
    int x;
    int tmp;
    int i;
	int ret;

    x = size - 1;
	ret = 0;
    while (x > 0)
    {
        i = cmp_case(line[x], line[x - 1]);
		if (i == 1)
		{
            line[x] = 2 * line[x];
            line[x - 1] = 0;
			ret++;
		}
        else if (i == 2)
		{
            tmp = x;
			if (tmp < size - 1)
				while ((tmp < size - 1) && 
					   (line[tmp + 1] == 0 || line[tmp + 1] == line[x - 1]))
					tmp++;
            if (line[tmp] == line[x - 1])
				line[tmp] *= 2;
            else
                line[tmp] = line[x - 1];
            line[x - 1] = 0;
			ret++;
		}
        x--;
    }
    return (ret);
}

static int	check_lineleft(int *line,  int size)
{
    int x;
    int tmp;
    int i;
	int ret;

    x = 0;
	ret = 0;
    while (x < size - 1)
    {
        i = cmp_case(line[x], line[x + 1]);
		if (i == 1)
		{
            line[x] = 2 * line[x];
            line[x + 1] = 0;
			ret++;
		}
        else if (i == 2)
		{
            tmp = x;
			if (tmp > 0)
				while (tmp > 0
					   && (line[tmp - 1] == 0 || line[tmp - 1] == line[x + 1]))
					tmp--;
            if (line[tmp] == line[x + 1])
				line[tmp] *= 2;
            else
                line[tmp] = line[x + 1];
            line[x + 1] = 0;
			ret++;
		}
        x++;
    }
    return (ret);
}

int  		   gm_horiz(int **tab, int size, int keycode)
{
    int y;
	int ret;

    y = 0;
	ret = 0;
	if (keycode == KEY_LEFT)
		while (y < size)
			ret += check_lineleft(tab[y++], size);
	else
		while (y < size)
			ret += check_lineright(tab[y++], size);
    return (ret);
}
