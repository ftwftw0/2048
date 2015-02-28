/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:21:47 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/28 16:55:52 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		**gm_new_tab(void)
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

void	gm_new_element(int **tab)
{
	int		i;
	int		j;
	int		k;

	i = rand() % gm_count_empty_spaces(tab) + 1;
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

int		**gm_init_tab(void)
{
	int		**tab;

	srand(time(NULL));
	tab = gm_new_tab();
	gm_new_element(tab);
	gm_new_element(tab);
	return (tab);
}
