/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_wstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 16:57:05 by lchenut           #+#    #+#             */
/*   Updated: 2015/02/19 15:53:49 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** void
**		ft_treat_arg_wstr(t_pf *t, va_list va)
** Modify the t->s (or set t->swstr) and t->l variables for the conversion S or
** conversion with the l modifier.
** The argument (va_arg(va, wchar_t *)) is converted so it can be write
** safely. If a precision is specified, no more than the number specified
** are written.
** For more informations : man 3 printf.
** ----------------------------------------------------------------------------
*/
static int		cpt_new_str(t_pf *t, t_wstr *f)
{
	int		i;
	t_wstr	*temp;

	i = 0;
	temp = f;
	while (temp)
	{
		i = i + temp->tabwc[1];
		temp = temp->next;
	}
	if (f)
		f->len = i;
	else if (t->s[0])
		t->l = i;
	if (t->width > i || t->zero > i)
		return (MAX(t->width, t->zero));
	else
		return (i);
}

static t_wstr	*treat_precision_wstr(t_wstr *f, t_pf *t)
{
	t_wstr		*temp;
	t_wstr		*temp2;
	int			cnt;

	temp = f;
	cnt = f->tabwc[1];
	while (cnt <= t->precision && temp)
	{
		temp2 = temp;
		temp = temp->next;
		if (temp)
			cnt = cnt + temp->tabwc[1];
	}
	if (cnt <= t->precision)
		return (f);
	if (temp != f)
	{
		ft_pf_clean_tab(temp);
		temp2->next = NULL;
		return (f);
	}
	ft_pf_clean_tab(f);
	return (NULL);
}

static void		ft_clean_wstr_temp(t_wstr **f, t_pf *t)
{
	if (*f)
	{
		ft_pf_clean_tab(*f);
		*f = NULL;
	}
	free(t->s);
	t->s = ft_strnew(0);
	t->l = -1;
}

static t_wstr	*ft_treat_arg_wstr_temp(t_pf *t, wchar_t *lstr)
{
	t_wstr		*f;
	int			i;
	int			*tab;

	i = 0;
	f = NULL;
	while (lstr[i])
	{
		if (lstr[i] <= 0X7F)
			tab = ft_pf_treat_wchar((int)lstr[i], 1);
		else if (lstr[i] <= 0X7FF)
			tab = ft_pf_treat_wchar((int)lstr[i], 2);
		else if (lstr[i] <= 0XFFFF)
			tab = ft_pf_treat_wchar((int)lstr[i], 3);
		else if (lstr[i] <= 0X10FFFF)
			tab = ft_pf_treat_wchar((int)lstr[i], 4);
		else
		{
			ft_clean_wstr_temp(&f, t);
			break ;
		}
		f = ft_pf_init_wstr(f, tab);
		i++;
	}
	return (f);
}

void			ft_pf_treat_arg_wstr(t_pf *t, va_list va)
{
	wchar_t		*lstr;
	wchar_t		*lstr2;
	t_wstr		*f;
	int			i;

	i = 0;
	lstr = va_arg(va, wchar_t *);
	lstr2 = NULL;
	f = NULL;
	if (!lstr)
		lstr2 = ft_pf_init_wnull();
	if (!(t->flag[4] && t->precision == 0))
		f = ft_treat_arg_wstr_temp(t, (lstr) ? lstr : lstr2);
	f = (t->flag[4] && f) ? treat_precision_wstr(f, t) : f;
	i = cpt_new_str(t, f);
	if (!f && t->s[0] != '\0')
		ft_pf_treat_wstr_null(t);
	else if (f)
		ft_pf_treat_wstr(t, f, i);
	if (!lstr && lstr2)
		free(lstr2);
}
