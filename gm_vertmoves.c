/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_vertmoves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:36:09 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/01 18:52:25 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	check_columndown(int **tab, int size, int column, int kc)
{
	int ret;

	ret = 0;
	ret = ret + gm_push(tab, size, column, kc);
	ret = ret + gm_merge(tab, size, column, kc);
	ret = ret + gm_push(tab, size, column, kc);
	return (ret);
}

static int	check_columnup(int **tab, int size, int column, int kc)
{
	int ret;

	ret = 0;
	ret = ret + gm_push(tab, size, column, kc);
	ret = ret + gm_merge(tab, size, column, kc);
	ret = ret + gm_push(tab, size, column, kc);
	return (ret);
}

int			gm_vert(int **tab, int size, int keycode)
{
	int x;
	int ret;

	x = 0;
	ret = 0;
	if (keycode == KEY_UP)
		while (x < size)
			ret += check_columnup(tab, size, x++, keycode);
	else
		while (x < size)
			ret += check_columndown(tab, size, x++, keycode);
	return (ret);
}
