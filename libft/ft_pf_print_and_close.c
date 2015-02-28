/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 13:52:36 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 14:17:15 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** int
**		ft_prt_all(t_pf *f)
** Print all the element s of the linked list f. Return the sum of the len
** of each element if none error occured, else return -1.
** ----------------------------------------------------------------------------
** void
**		ft_close_all(t_pf *f)
** Free all the allocated element of the linked list f.
** ----------------------------------------------------------------------------
*/
static void	prt_wchar(t_wchar *t)
{
	int i;

	i = 2;
	if (t->befwc)
	{
		ft_putstr(t->befwc);
		free(t->befwc);
	}
	while (i < t->tabwc[1] + 2)
		write(1, &t->tabwc[i++], 1);
	if (t->aftwc)
	{
		ft_putstr(t->aftwc);
		free(t->aftwc);
	}
	if (t->tabwc)
		free(t->tabwc);
	free(t);
}

static void	prt_wstr(t_wstr *f)
{
	int		i;
	t_wstr	*t;

	t = f;
	if (f->befwc)
	{
		ft_putstr(f->befwc);
		free(f->befwc);
		f->befwc = NULL;
	}
	while (t)
	{
		i = 2;
		while (i < t->tabwc[1] + 2)
			write(1, &t->tabwc[i++], 1);
		t = t->next;
	}
	if (f->aftwc)
	{
		ft_putstr(f->aftwc);
		free(f->aftwc);
		f->befwc = NULL;
	}
}

int			ft_pf_prt_all(t_pf *f)
{
	t_pf	*t;
	int		i;

	t = f;
	i = 0;
	if (ft_pf_is_null(f))
		ft_pf_treat_null(f);
	while (t)
	{
		if (t->s && t->precision != -1)
			write(1, t->s, t->l);
		else if (t->swch && t->precision != -1)
			prt_wchar(t->swch);
		else if (t->swstr && t->precision != -1)
			prt_wstr(t->swstr);
		i = (i < 0 || t->l < 0) ? -1 : i + t->l;
		t = t->next;
	}
	return (i);
}

void		ft_pf_close_all(t_pf *f)
{
	t_pf	*t;

	while (f)
	{
		t = f->next;
		if (f->s)
			free(f->s);
		if (f->swstr)
			ft_pf_clean_tab(f->swstr);
		if (f->flag)
			free(f->flag);
		free(f);
		f = NULL;
		f = t;
	}
}
