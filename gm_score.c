/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:57:08 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/01 17:45:14 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		gm_score(int **tab, int size)
{
	int score;
	int x;
	int y;

	score = 0;
	x = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			score += (ft_depow2(tab[y][x]) - 1) * tab[y][x];
			x++;
		}
		y++;
	}
	return (score);
}
