/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:58:16 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 14:52:31 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	gm_merge_down(int **tab, int size, int column)
{
	int ret;

	size = size - 1;
	ret = 0;
	while (size >= 1)
	{
		if (tab[size][column] == tab[size - 1][column] && tab[size][column])
		{
			tab[size][column] = tab[size][column] * 2;
			tab[size - 1][column] = 0;
			ret = ret + 1;
		}
		size--;
	}
	return (ret);
}


static int	gm_merge_up(int **tab, int size, int column)
{
	int ret;
	int	i;

	i = 0;
	ret = 0;
	while (i < size - 1)
	{
		if (tab[i][column] == tab[i + 1][column] && tab[i][column])
		{
			tab[i][column] = tab[i][column] * 2;
			tab[i + 1][column] = 0;
			ret = ret + 1;
		}
		i++;
	}
	return (ret);
}

static int	gm_merge_right(int **tab, int size, int line)
{
	int ret;

	size = size - 1;
	ret = 0;
	while (size >= 1)
	{
		if (tab [line][size] == tab[line][size - 1] && tab[line][size])
		{
			tab[line][size] = tab[line][size] * 2;
			tab[line][size - 1] = 0;
			ret = ret + 1;
		}
		size--;
	}
	return (ret);
}

static int	gm_merge_left(int **tab, int size, int line)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	while (i < size - 1)
	{
		if (tab[line][i] == tab[line][i + 1] && tab[line][i])
		{
			tab[line][i] = tab[line][i] * 2;
			tab[line][i + 1] = 0;
			ret = ret + 1;
		}
		i++;
	}
	return (ret);
}

int			gm_merge(int **tab, int size, int linecol, int kc)
{
	if (kc == KEY_DOWN)
		return (gm_merge_down(tab, size, linecol));
	if (kc == KEY_UP)
		return (gm_merge_up(tab, size, linecol));
	if (kc == KEY_LEFT)
		return (gm_merge_left(tab, size, linecol));
	if (kc == KEY_RIGHT)
		return (gm_merge_right(tab, size, linecol));
	return (0);
}
