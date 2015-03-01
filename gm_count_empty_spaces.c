/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_count_empty_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:47:23 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 18:49:23 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		gm_count_empty_spaces(int **tab)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (j < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (tab[j][k] == 0)
				i++;
			k++;
		}
		j++;
	}
	return (i);
}
