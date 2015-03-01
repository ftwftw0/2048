/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_checkwin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:57:26 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 18:59:48 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			gm_checkwin(int **tab, int size, int test)
{
	int x;
	int y;

	if (test)
		return (0);
	y = -1;
	while (++y < size)
	{
		x = 0;
		while (x < size)
			if (tab[y][x++] >= WIN_VALUE)
				return (1);
	}
	return (0);
}
