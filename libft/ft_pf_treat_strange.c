/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_strange.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 14:38:40 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 14:40:09 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** void
**		ft_treat_arg_strange(t_pf *f, t_pf *t, va_list va)
** Treat the two strange conversions case :
**		1°) The pointer conversion %p
**		2°) The counter non conversion %n
** ----------------------------------------------------------------------------
*/
static void			ft_clear_wc(t_pf *t, va_list va)
{
	int i;

	i = 0;
	while (t->s[i])
	{
		if (t->s[i] == '*')
			va_arg(va, long long);
		i++;
	}
}

static long long	count_total(t_pf *f)
{
	long long	i;
	t_pf		*t;

	i = 0;
	t = f;
	while (t->precision != -12)
	{
		i = i + t->l;
		t = t->next;
	}
	return (i);
}

static void			ft_treat_count(t_pf *f, t_pf *t, va_list va)
{
	long long i;
	long long *j;

	t->m = ft_pf_check_modifier(t);
	t->precision = -12;
	ft_clear_wc(t, va);
	i = count_total(f);
	j = va_arg(va, long long *);
	if (t->m == NONE)
		*j = (int)i;
	else if (t->m == HH)
		*j = (char)i;
	else if (t->m == H)
		*j = (short)i;
	else if (t->m == L || t->m == Z)
		*j = (long)i;
	else
		*j = i;
	free(t->s);
	t->s = NULL;
	t->s = ft_strnew(1);
	t->l = 0;
}

static void			ft_treat_pointer(t_pf *t, char *s, void *temp)
{
	if (t->flag[4] && temp == 0 && t->precision == 0)
	{
		t->width = (t->width > 2) ? t->width : 2;
		s = ft_pf_strfnew_temp(t, ' ', s);
		s[((t->flag[1]) ? 0 : t->width - 2)] = '0';
		s[((t->flag[1]) ? 1 : t->width - 1)] = 'x';
	}
	else
	{
		t->flag[0] = 1;
		s = ft_pf_treat_hex(t, s);
		if (temp == 0)
			s = ft_pf_after_effect(t, s);
	}
	free(t->s);
	t->s = s;
	t->l = ft_strlen(t->s);
}

void				ft_pf_treat_arg_strange(t_pf *f, t_pf *t, va_list va)
{
	void	*temp;
	char	*s;

	if (t->s[t->l - 1] == 'p')
	{
		ft_pf_check_digits(t, va);
		temp = va_arg(va, void *);
		s = ft_htoa((unsigned long)temp);
		ft_treat_pointer(t, s, temp);
	}
	else
		ft_treat_count(f, t, va);
}
