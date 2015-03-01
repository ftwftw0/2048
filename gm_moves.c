/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:54:22 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/01 11:08:13 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/*
**  Returns 1 if even, 2 if first case goes to second case, 0 if nothing moves
*/

int		cmp_case(int case1, int case2)
{
	if (case1 == case2 && case1 != 0)
		return (1);
	else if (case1 == 0 && case2)
		return (2);
	else
		return (0);
}
