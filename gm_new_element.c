/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_new_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:45:23 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 18:46:51 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	gm_new_element(int **tab)
{
	int		i;
	int		j;
	int		k;

	j = gm_count_empty_spaces(tab);
	if (j == 0)
		return ;
	i = rand() % j + 1;
	j = 0;
	while (j < 4)
	{
		k = 0;
		while (k < 4 && i != 0)
			if (tab[j][k++] == 0)
				i--;
		if (i == 0)
			break ;
		j++;
	}
	tab[j][k - 1] = (rand() % 10 == 0) ? 4 : 2;
}
