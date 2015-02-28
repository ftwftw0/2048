/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_modifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 12:59:07 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 13:38:36 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** int
**		ft_is_lh(char *s, char c);
** Return 0 if the modifier is ll (or hh) is found in the string s, return 1
** if the modifier l (or h) is found and return 2 if none of them are found.
** ----------------------------------------------------------------------------
** t_modif
**		check_modifier(t_pf *t)
** Return the enum t_modif set to the value of modifier found in the string
** t->s.
** ----------------------------------------------------------------------------
*/
int			ft_pf_is_lh(char *s, char c)
{
	int i;
	int t;

	i = 0;
	t = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] == c)
		{
			t = 1;
			i++;
		}
		else if (s[i] == c)
			return (1);
		i++;
	}
	return ((t == 1) ? 2 : 0);
}

t_modif		ft_pf_check_modifier(t_pf *t)
{
	t_modif	modif;
	int		i;

	if (ft_is_in(t->s, 'z'))
		modif = Z;
	else if (ft_is_in(t->s, 'j'))
		modif = J;
	else if ((i = ft_pf_is_lh(t->s, 'l')))
		modif = (i == 2) ? LL : L;
	else if ((i = ft_pf_is_lh(t->s, 'h')))
		modif = (i == 2) ? HH : H;
	else
		modif = NONE;
	return (modif);
}
