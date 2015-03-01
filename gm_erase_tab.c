/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_erase_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:42:43 by lchenut           #+#    #+#             */
/*   Updated: 2015/03/01 18:43:09 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		gm_erase_tab(int ***tab)
{
	free((*tab)[0]);
	(*tab)[0] = NULL;
	free((*tab)[1]);
	(*tab)[1] = NULL;
	free((*tab)[2]);
	(*tab)[2] = NULL;
	free((*tab)[3]);
	(*tab)[3] = NULL;
	free(*tab);
	*tab = NULL;
}
