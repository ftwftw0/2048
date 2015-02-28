/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:25:09 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 13:48:13 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** void
**		ft_treat_arg_other(t_pf *t, va_list va)
** Modify the t->s and t->l variables if none conversions are given, such as
** "%%".
** ----------------------------------------------------------------------------
*/
static int	ft_getnumber(char *s, va_list va, char *comp)
{
	int i;
	int sign;
	int	cpt;

	i = 1;
	sign = 1;
	cpt = 0;
	while (s[i])
	{
		if ((s[i] == '*' || ft_isdigit(s[i])) && !ft_is_in(comp, s[i - 1])
				&& s[i] != '0')
		{
			cpt = (s[i] == '*') ? va_arg(va, int) : ft_atoi(s + i);
			if (cpt < 0)
				sign = -1;
			i++;
			while (ft_isdigit(s[i]) && s[i - 1] != '*')
				i++;
		}
		else
			i++;
		if (s[i - 1] == '*' && ft_is_in(comp, s[i - 2]))
			va_arg(va, int);
	}
	return ((cpt > 0) ? cpt * sign : cpt);
}

void		ft_pf_treat_arg_other(t_pf *t, va_list va)
{
	int		i;
	char	*s;

	i = ft_getnumber(t->s, va, ".");
	if (i == 0)
	{
		s = ft_strnew(1);
		s[0] = t->s[t->l - 1];
	}
	else if (i < 0 || t->flag[1])
	{
		s = ft_strfnew((size_t)(ABS(i)), ' ');
		s[0] = t->s[t->l - 1];
	}
	else
	{
		s = (t->flag[5]) ? ft_strfnew(i, '0') : ft_strfnew(i, ' ');
		s[i - 1] = t->s[t->l - 1];
	}
	free(t->s);
	t->s = NULL;
	t->l = ft_strlen(s);
	t->s = s;
}
