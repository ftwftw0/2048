/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_function_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 16:50:56 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 14:36:05 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** ...
** Garbage Functions T2
** ----------------------------------------------------------------------------
*/
void	ft_pf_clean_tab(t_wstr *f)
{
	t_wstr *t;
	t_wstr *t2;

	t = f;
	while (t)
	{
		t2 = t->next;
		free(t->tabwc);
		t->tabwc = NULL;
		free(t);
		t = NULL;
		t = t2;
	}
}

t_wstr	*ft_pf_init_wstr(t_wstr *f, int *tab)
{
	t_wstr	*t;
	t_wstr	*t2;

	if (!(t = (t_wstr *)malloc(sizeof(t_wstr))))
		return (NULL);
	t->tabwc = ft_pf_tabdup(tab);
	t->next = NULL;
	t->len = 0;
	t->befwc = NULL;
	t->aftwc = NULL;
	free(tab);
	tab = NULL;
	if (!f)
		return (t);
	t2 = f;
	while (t2->next)
		t2 = t2->next;
	t2->next = t;
	return (f);
}

void	ft_pf_treat_wstr_null(t_pf *t)
{
	char *s;

	if (t->flag[1])
		s = ft_pf_padding_wchar(t, 0, 0);
	else
		s = ft_pf_padding_wchar(t, 0, 1);
	free(t->s);
	t->s = NULL;
	t->s = s;
	t->l = ft_strlen(t->s);
}

void	ft_pf_treat_wstr(t_pf *t, t_wstr *f, int i)
{
	if (i > f->len)
	{
		if (t->flag[1])
			f->aftwc = ft_pf_padding_wchar(t, f->len, 0);
		else
			f->befwc = ft_pf_padding_wchar(t, f->len, 1);
	}
	free(t->s);
	t->s = NULL;
	t->l = i;
	t->swstr = f;
}

wchar_t	*ft_pf_init_wnull(void)
{
	wchar_t	*str;

	if (!(str = (wchar_t *)malloc(sizeof(wchar_t) * 7)))
		return (NULL);
	str[0] = L'(';
	str[1] = L'n';
	str[2] = L'u';
	str[3] = L'l';
	str[4] = L'l';
	str[5] = L')';
	str[6] = L'\0';
	return (str);
}
