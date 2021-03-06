/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:21:47 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 18:51:07 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	**gm_new_tab(void)
{
	int		**tab;
	int		i;
	int		j;

	if (!(tab = (int **)malloc(sizeof(int *) * 4)))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		j = 0;
		if (!(tab[i] = (int *)malloc(sizeof(int) * 4)))
		{
			i--;
			while (i > 0)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		while (j < 4)
			tab[i][j++] = 0;
		i++;
	}
	return (tab);
}

int			**gm_init_tab(void)
{
	int		**tab;

	tab = gm_new_tab();
	gm_new_element(tab);
	gm_new_element(tab);
	return (tab);
}
