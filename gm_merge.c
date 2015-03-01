/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:58:16 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 11:10:33 by lchenut          ###   ########.fr       */
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

int			gm_merge(int **tab, int size, int linecol, int kc)
{
	if (kc == KEY_DOWN)
		return (gm_merge_down(tab, size, linecol));
	return (0);
}
