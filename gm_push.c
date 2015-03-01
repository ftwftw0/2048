/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:49:30 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 11:10:23 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		gm_push_down(int **tab, int size, int column)
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

int			gm_push(int **tab, int size, int linecol, int kc)
{
	if (kc == KEY_DOWN)
		return (gm_push_down(tab, size, linecol));
	return (0);
}
