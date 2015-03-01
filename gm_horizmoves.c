/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_horizmoves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:23:25 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/01 17:43:51 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	check_lineleft(int **tab, int size, int line, int kc)
{
	int ret;

	ret = 0;
	ret = ret + gm_push(tab, size, line, kc);
	ret = ret + gm_merge(tab, size, line, kc);
	ret = ret + gm_push(tab, size, line, kc);
	return (ret);
}

static int	check_lineright(int **tab, int size, int line, int kc)
{
	int ret;

	ret = 0;
	ret = ret + gm_push(tab, size, line, kc);
	ret = ret + gm_merge(tab, size, line, kc);
	ret = ret + gm_push(tab, size, line, kc);
	return (ret);
}

int			gm_horiz(int **tab, int size, int keycode)
{
	int y;
	int ret;

	y = 0;
	ret = 0;
	if (keycode == KEY_LEFT)
		while (y < size)
			ret += check_lineleft(tab, size, y++, keycode);
	else
		while (y < size)
			ret += check_lineright(tab, size, y++, keycode);
	return (ret);
}
