/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:49:30 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 18:51:30 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	gm_push_down(int **tab, int size, int column)
{
	int tmp;
	int ret;

	size = size - 1;
	ret = 0;
	while (size >= 0)
	{
		if (tab[size][column] == 0)
		{
			tmp = size - 1;
			while (tmp >= 0)
			{
				if (tab[tmp][column] != 0)
				{
					tab[size][column] = tab[tmp][column];
					tab[tmp][column] = 0;
					ret++;
					break ;
				}
				tmp--;
			}
		}
		size--;
	}
	return (ret);
}

static int	gm_push_up(int **tab, int size, int column, int i)
{
	int tmp;
	int ret;

	ret = 0;
	while (i < size)
	{
		if (tab[i][column] == 0)
		{
			tmp = i + 1;
			while (tmp < size)
			{
				if (tab[tmp][column] != 0)
				{
					tab[i][column] = tab[tmp][column];
					tab[tmp][column] = 0;
					ret++;
					break ;
				}
				tmp++;
			}
		}
		i++;
	}
	return (ret);
}

static int	gm_push_right(int **tab, int size, int line)
{
	int tmp;
	int ret;

	size = size - 1;
	ret = 0;
	while (size >= 0)
	{
		if (tab[line][size] == 0)
		{
			tmp = size - 1;
			while (tmp >= 0)
			{
				if (tab[line][tmp] != 0)
				{
					tab[line][size] = tab[line][tmp];
					tab[line][tmp] = 0;
					ret++;
					break ;
				}
				tmp--;
			}
		}
		size--;
	}
	return (ret);
}

static int	gm_push_left(int **tab, int size, int line, int i)
{
	int tmp;
	int ret;

	ret = 0;
	while (i < size)
	{
		if (tab[line][i] == 0)
		{
			tmp = i + 1;
			while (tmp < size)
			{
				if (tab[line][tmp] != 0)
				{
					tab[line][i] = tab[line][tmp];
					tab[line][tmp] = 0;
					ret++;
					break ;
				}
				tmp++;
			}
		}
		i++;
	}
	return (ret);
}

int			gm_push(int **tab, int size, int linecol, int kc)
{
	if (kc == KEY_DOWN)
		return (gm_push_down(tab, size, linecol));
	if (kc == KEY_UP)
		return (gm_push_up(tab, size, linecol, 0));
	if (kc == KEY_LEFT)
		return (gm_push_left(tab, size, linecol, 0));
	if (kc == KEY_RIGHT)
		return (gm_push_right(tab, size, linecol));
	return (0);
}
