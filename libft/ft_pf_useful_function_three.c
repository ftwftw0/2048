/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_function_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 11:03:55 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 14:40:50 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** ...
** Garbage Functions T3
** ----------------------------------------------------------------------------
*/
t_wchar		*ft_pf_init_wchar(int *tab, int len, t_pf *t)
{
	t_wchar *wc;

	if (!(wc = (t_wchar *)malloc(sizeof(t_wchar))))
		return (NULL);
	wc->befwc = NULL;
	wc->aftwc = NULL;
	if (len > tab[1] && wc)
	{
		if (t->flag[1])
			wc->aftwc = ft_pf_padding_wchar(t, tab[1], 0);
		else
			wc->befwc = ft_pf_padding_wchar(t, tab[1], 1);
	}
	wc->tabwc = tab;
	return (wc);
}

char		*ft_pf_strfnew_temp(t_pf *t, char c, char *s)
{
	char *str;

	t->width = (((t->flag[2] || t->flag[3]) && (t->s[t->l - 1] == 'd'
				|| t->s[t->l - 1] == 'D' || t->s[t->l - 1] == 'i') &&
				(t->width == 0)))
		? t->width + 1 : t->width;
	str = ft_strfnew(t->width, c);
	if (t->flag[2] && (t->s[t->l - 1] == 'd' || t->s[t->l - 1] == 'D'
											|| t->s[t->l - 1] == 'i'))
	{
		if (t->flag[1])
			str[0] = '+';
		else
			str[ft_strlen(str) - 1] = '+';
	}
	free(s);
	s = NULL;
	return (str);
}
