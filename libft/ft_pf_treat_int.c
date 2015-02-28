/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 16:05:58 by lchenut           #+#    #+#             */
/*   Updated: 2015/01/09 14:39:21 by lchenut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ----------------------------------------------------------------------------
** void
**		ft_treat_arg_int(t_pf *t, va_list va)
** Modify the t->s and t->l variables for the conversions i / d / D.
** If i or d is given, the argument (va_arg(va, int)) is converted to signed
** decimal, if D is given the conversion is long signed decimal.
** For more informations : man 3 printf.
** ----------------------------------------------------------------------------
*/
static int	cpt_new_str(t_pf *t, int l, char s)
{
	if (t->width > l || t->precision > l || t->zero > l)
	{
		if (t->flag[2] || t->flag[3] || s == '-')
			return (ft_pf_max(t->width, t->precision, t->zero) + 1);
		return (ft_pf_max(t->width, t->precision, t->zero));
	}
	else
	{
		if (t->flag[2] || t->flag[3] || s == '-')
			return (l + 1);
		return (l);
	}
}

static int	ft_padding_before(char *new, t_pf *t, char *s)
{
	int i;

	i = 0;
	if (!t->flag[5] && !t->flag[1])
	{
		while (i < t->width - MAX((int)((s[0] == '-')
						? (ft_strlen(s) - 1) : ft_strlen(s)), t->precision))
			new[i++] = ' ';
	}
	if (t->flag[2] || t->flag[3] || s[0] == '-')
	{
		i = (i == 0) ? i : i - 1;
		if (s[0] == '-')
			new[i++] = '-';
		else
			new[i++] = (t->flag[2]) ? '+' : ' ';
	}
	if (t->flag[5] && !t->flag[1])
	{
		while (i < MAX(t->width, t->zero) -
				((s[0] == '-') ? (int)(ft_strlen(s) - 1) : (int)ft_strlen(s)))
			new[i++] = '0';
	}
	return (i);
}

static char	*ft_treat_int(t_pf *t, char *s)
{
	int		len;
	int		i;
	char	*new;

	len = cpt_new_str(t, ft_strlen(s), s[0]);
	if (len == (int)ft_strlen(s))
		return (s);
	new = ft_strnew(len);
	len = ft_padding_before(new, t, s);
	while ((int)ft_strlen(s) <
			((s[0] == '-') ? t->precision + 1 : t->precision))
	{
		new[len++] = '0';
		t->precision--;
	}
	i = (s[0] == '-') ? 1 : 0;
	while (s[i])
		new[len++] = s[i++];
	ft_pf_padding_after(new, t, len);
	free(s);
	s = NULL;
	return (new);
}

void		ft_pf_treat_arg_int(t_pf *t, va_list va)
{
	long long	i;
	char		*s;

	i = va_arg(va, long long);
	if (t->m == NONE)
		s = ft_ltoa((int)i);
	else if (t->m == HH)
		s = ft_ltoa((char)i);
	else if (t->m == H)
		s = ft_ltoa((short)i);
	else if (t->m == L || t->m == Z)
		s = ft_ltoa((long)i);
	else
		s = ft_ltoa(i);
	s = (t->flag[4] && i == 0 && t->precision == 0) ?
		ft_pf_strfnew_temp(t, ' ', s) : ft_treat_int(t, s);
	free(t->s);
	t->s = s;
	t->l = ft_strlen(t->s);
}
