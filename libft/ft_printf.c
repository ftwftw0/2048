/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 14:17:00 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 14:54:02 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** int
**		ft_printf(const char *format, ...)
** man 3 printf
** #kiss #love
*/
static void	ft_treat_arg_digit(t_pf *t, va_list va)
{
	t->m = (ft_is_in("DOUB", t->s[t->l - 1])) ? L : ft_pf_check_modifier(t);
	ft_pf_check_digits(t, va);
	if (ft_is_in("Ddi", t->s[t->l - 1]))
		ft_pf_treat_arg_int(t, va);
	else if (ft_is_in("Oo", t->s[t->l - 1]))
		ft_pf_treat_arg_oct(t, va);
	else if (ft_is_in("Uu", t->s[t->l - 1]))
		ft_pf_treat_arg_uns(t, va);
	else if (ft_is_in("Xx", t->s[t->l - 1]))
		ft_pf_treat_arg_hex(t, va);
	else
		ft_pf_treat_arg_bin(t, va);
}

static void	ft_treat_arg_charstr(t_pf *t, va_list va)
{
	t->m = (ft_pf_is_lh(t->s, 'l') == 1 || t->s[t->l - 1] == 'S'
			|| t->s[t->l - 1] == 'C') ? L : NONE;
	ft_pf_check_char(t, va);
	if (ft_is_in(t->s, '-') && ft_pf_is_zero(t->s) && t->zero > 0)
	{
		t->width = t->zero;
		t->zero = 0;
	}
	if (t->s[t->l - 1] == 's' && t->m != L)
		ft_pf_treat_arg_str(t, va);
	else if (t->s[t->l - 1] == 'c' && t->m != L)
		ft_pf_treat_arg_char(t, va);
	else if (t->s[t->l - 1] == 'S' || t->s[t->l - 1] == 's')
		ft_pf_treat_arg_wstr(t, va);
	else
		ft_pf_treat_arg_wchar(t, va);
}

static void	ft_treat_arg(t_pf *f, t_pf *t, va_list va)
{
	if (ft_is_in(DIGITS, t->s[t->l - 1]))
		ft_treat_arg_digit(t, va);
	else if (ft_is_in("sScC", t->s[t->l - 1]))
		ft_treat_arg_charstr(t, va);
	else if (ft_is_in("pn", t->s[t->l - 1]))
		ft_pf_treat_arg_strange(f, t, va);
	else if (t->l != 1 && !ft_is_in(FLAGS_MODIF, t->s[t->l - 1]))
		ft_pf_treat_arg_other(t, va);
	else
	{
		free(t->s);
		t->l = 0;
		t->s = ft_strnew(0);
	}
	t->width = -1;
	t->precision = 0;
}

int			ft_printf(const char *format, ...)
{
	int		i;
	t_pf	*f;
	t_pf	*t;
	va_list	va;

	f = NULL;
	f = ft_pf_split((char *)format, f);
	t = f;
	va_start(va, format);
	while (t)
	{
		if (t->s[0] == '%')
			ft_treat_arg(f, t, va);
		t = t->next;
	}
	i = ft_pf_prt_all(f);
	ft_pf_close_all(f);
	va_end(va);
	return (i);
}
